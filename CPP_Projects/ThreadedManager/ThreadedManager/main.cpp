#define HAVE_STRUCT_TIMESPEC

#include "CManager.h"
#include <csignal>

bool g_bRunning = true;

void signalHandler(int signum) {
	std::cout << "Interrupt signal (" << signum << ") received." << std::endl;

	g_bRunning = false;
}

int main() {
	signal(SIGINT, signalHandler);

	CManager* pManager1 = new CManager();
	CManager* pManager2 = new CManager();

	pManager1->Init("Module 1");
	pManager2->Init("Module 2");

	CQueue* pManager1ToManager2 = new CQueue();
	CQueue* pManager2ToManager1 = new CQueue();

	pManager2->m_pIncomingQueue = pManager1ToManager2;
	pManager1->m_pOutgoingQueue = pManager1ToManager2;

	pManager1->m_pIncomingQueue = pManager2ToManager1;
	pManager2->m_pOutgoingQueue = pManager2ToManager1;

	pManager1->Start();
	pManager2->Start();

	pManager2ToManager1->Push(new CMessage("Start messaging"));

	while (g_bRunning)
	{
		Sleep(500);
	}

	pManager1->Stop();
	pManager2->Stop();

	pthread_join(pManager1->m_ptThread, NULL);
	pthread_join(pManager2->m_ptThread, NULL);

	delete pManager1ToManager2;
	pManager1ToManager2 = NULL;

	delete pManager2ToManager1;
	pManager2ToManager1 = NULL;

	delete pManager1;
	pManager1 = NULL;

	delete pManager2;
	pManager2 = NULL;

	return 0;
}