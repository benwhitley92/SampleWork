#pragma once

#define HAVE_STRUCT_TIMESPEC

#include <pthread.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <queue>

#include "CQueue.h"

class CManager
{
public:
	CManager();
	~CManager();

	void Init(std::string);
	void Start();
	void Stop();

	void DoWork();

	void CheckQueue();

	pthread_t m_ptThread;
	bool m_bRunning;
	std::string m_strModuleName;

	CQueue* m_pIncomingQueue;
	CQueue* m_pOutgoingQueue;
};