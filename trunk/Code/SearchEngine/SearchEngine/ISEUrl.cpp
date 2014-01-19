/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.cpp
*Author: Zhonghao Ji
*Description: Url Class Defination
**********************************************/

#include "ISEUrl.h"

/*********************************************
Name: ISEurl(void)
Create Time:2014-01-01
Author:Ji Zhonghao
Input arg:
Output arg:
Description: Url Class Destruction
*********************************************/
ISEUrl::~ISEUrl(VOID)
{
}

/*********************************************
Name: const static char* ISE_GetIPByHost(const char * pcHost)
Create Time:2014-01-13
Author:Ji Zhonghao
Input arg:host: host string
Output arg:
Description: get IP address via host name
*********************************************/
CHAR * ISEUrl::ise_GetIPByHost(CONST CHAR * pcHost)
{
	if(!ise_IsValidIP(pcHost))
	{
		return NULL;
	}
	
	ULONG ulAddr = 0;
	CHAR* pcResult = NULL;
	INT iLen = 0;

	ulAddr = (ULONG)inet_addr(pcHost);
	if(INADDR_NONE != ulAddr)
	{
		iLen = strlen(pcHost);
		{
		boost::lock_guard<boost::mutex> lock(_mutex);
		pcResult = new CHAR[iLen + 1];
		if(NULL == pcResult)
		{
			std::cerr<<"No enough memory\r\n";
			return NULL;
		}
		}
		pcResult[0] = '\0';
		strncpy(pcResult, pcHost, iLen);
		return pcResult;
	}

	//Init socket
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(1, 1), &wsaData)) 
	{
		std::cerr<<"WSAStartup error\r\n";
		return NULL;
	}

	//Find within DNS Server
	struct hostent *pstHEntry;
	pstHEntry = gethostbyname(pcHost);
	if(NULL == pstHEntry)
	{
		return NULL;
	}

	struct in_addr stIn;
	memset(&stIn, 0, sizeof(struct in_addr));
	memcpy((VOID *)&stIn, *(pstHEntry->h_addr_list), pstHEntry->h_length);

	CHAR szBuf[INET_ADDRSTRLEN + 1];
	szBuf[0] = '\0';
	strncpy(szBuf, inet_ntoa(stIn), sizeof(szBuf));
	if(NULL == szBuf[0])
	{
		std::cerr<<"inet_ntoa() errror\r\n";
	}
	else
	{
		boost::lock_guard<boost::mutex> lock(_mutex);
	}

	iLen = strlen(szBuf);
	{
 	boost::lock_guard<boost::mutex> lock(_mutex);
	pcResult = new CHAR[iLen + 1];
	if(NULL == pcResult)
	{
		std::cerr<<"Not enough memory\r\n";
		return NULL;
	}
	}

	memset(pcResult, 0, iLen + 1);
	memcpy(pcResult, szBuf, iLen);

	return pcResult;
}

BOOL ISEUrl::ise_IsValidIP(CONST CHAR *pcHost) CONST
{
	if(NULL == pcHost)
		return false;

	boost::regex expression("[0-9a-zA-Z\\-.:_]+");
	return boost::regex_match(pcHost, expression);
}


