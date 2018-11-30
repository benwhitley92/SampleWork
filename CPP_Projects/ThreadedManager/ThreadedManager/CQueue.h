#pragma once

#include "CMessage.h"
#include <queue>

class CQueue
{
public:
	CQueue();
	~CQueue();

	CMessage* Pop();
	void Push(CMessage* pMessage);
	bool IsEmpty();

	std::queue<CMessage*> m_qQueue;
};