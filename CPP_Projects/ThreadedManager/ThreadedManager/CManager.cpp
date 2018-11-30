#include "CManager.h"

static void* work(void* object)
{
	((CManager *)object)->DoWork();
	return NULL;
}

CManager::CManager()
{
}

CManager::~CManager()
{
}

void CManager::Init(std::string moduleName)
{
	m_strModuleName = moduleName;
	m_bRunning = true;
}

void CManager::Start()
{
	pthread_create(&m_ptThread, NULL, work, this);
}

void CManager::Stop()
{
	m_bRunning = false;
}

void CManager::DoWork()
{
	while (m_bRunning)
	{
		if (m_pIncomingQueue && m_pOutgoingQueue)
		{
			CheckQueue();
		}
	}
}

void CManager::CheckQueue()
{
	if (!m_pIncomingQueue->IsEmpty())
	{
		CMessage* pMessageIn = m_pIncomingQueue->Pop();

		if (pMessageIn)
		{
			std::cout << m_strModuleName << " received message: " << pMessageIn->m_strMessage << std::endl;
			m_pOutgoingQueue->Push(new CMessage("Hello from " + m_strModuleName));

			delete pMessageIn;
			pMessageIn = NULL;
		}
		else
		{
			std::cout << m_strModuleName << " received null message" << std::endl;
		}
	}
	else
	{
		Sleep(500);
	}
}