#pragma once

#include <string>

class CMessage
{
public:
	CMessage(std::string strMessage) { m_strMessage = strMessage; }
	~CMessage() {}

	std::string m_strMessage;
};