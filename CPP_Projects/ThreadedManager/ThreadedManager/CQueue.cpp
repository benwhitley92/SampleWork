#include "CQueue.h"

CQueue::CQueue()
{
}

CQueue::~CQueue()
{
	if (!IsEmpty())
	{
		delete m_qQueue.front();
		m_qQueue.front() = NULL;

		m_qQueue.pop();
	}
}

CMessage* CQueue::Pop()
{
	CMessage* pMessage = m_qQueue.front();
	m_qQueue.pop();

	return pMessage;
}

void CQueue::Push(CMessage* pMessage)
{
	m_qQueue.push(pMessage);
}


bool CQueue::IsEmpty()
{
	return m_qQueue.empty();
}