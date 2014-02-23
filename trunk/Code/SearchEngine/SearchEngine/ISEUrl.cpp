/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.cpp
*Author: Zhonghao Ji
*Description: Url Class Defination
**********************************************/

#include "ISEUrl.h"
boost::mutex ISEUrl::_mutex;
 
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
Name: BOOL ise_ParseUrl(std::string strUrl)
Create Time:2014-02-12
Author:Ji Zhonghao
Input arg:host: url string
Output arg: 
Return: TRUE: sucess
		FALSE: fail
Description: break an URL into scheme, host, port and request. result as member variants
*********************************************/
BOOL ISEUrl::ise_ParseUrl(std::string strUrl)
{
	if(strUrl.empty())
	{
		return FALSE;
	}
	
	ISEURL_PARA_S stPara;
	memset(stPara, 0, sizeof(stPara));
	stPara.iPort = INVALID_PORT;
	
	ise_ParaseUrlEx(stUrl.c_str,
					(VOID*)&stPara);
	
	this->szHost = stPara.acHost;
	this->szPath = stPara.acRequest;
	this->iPort = stPara.iPort;
	this->szUrl = strUrl;
}

/*********************************************
Name: ise_ParseUrlEx
Create Time:2014-02-16
Author:Ji Zhonghao
Input arg:host: 
Output arg: 
Return: TRUE: sucess
		FALSE: fail
Description: break an URL into scheme, host, port and request. result as member variants
*********************************************/
VOID ISEUrl::ise_ParseUrlEx(IN const CHAR *pcUrl,
							INOUT VOID *pPara)
{
	assert(pPara != NULL);
	assert(pcUrl != NULL);
	
	ISEURL_PARA_S *pstPara = (ISEURL_PARA_S *)pPara;
	
	CHAR *pcTemp = strchr(pcUrl, ':');
	strncpy(pstPara->acProtocol, pcUrl, pcUrl - pcTemp) ? strncpy(pstPara->acProtocol, "http", sizeof("http")) : NULL != pcTemp;
	
	pcTemp += 3 ? pcTemp : *(pcTemp+1) == '/' && *(pcTemp + 2) == '/';
	
	/* 解析host */
	int iHostLen = 0;
	while(ise_IsValidHostChar(*pcTemp))
	{
		pcTemp++;
		iHostLen++;
	}
	strncpy(pstPara->acHost, (pcTemp++) - iHostLen, iHostLen);
	
	/* 解析请求 */
	strncpy(pstPara->acRequest, pcTemp, sizeof(pst->acRequest));
	
	/* 解析端口 */
	pcTemp++ = strchr(pstPara->acHost, ':');
	if(NULL != pcTemp)
	{ 
		pstPara->iPort = atoi(pcTemp);
	}
	else{
		pstPara->iPort = 80;
	}
	
	return;
	}
/*********************************************
Name: const static char* ISE_GetIPByHost(const char * pcHost)
Create Time:2014-01-13
Author:Ji Zhonghao
Input arg:host: host string
Output arg:
Description: get IP address via host name
*********************************************/
CHAR *ISEUrl::ise_GetIPByHost(CONST CHAR * pcHost)
{
	if(!ise_IsValidIP(pcHost))
	{
		return NULL;
	}
	
	CHAR* pcResult = NULL;
	INT iLen = 0;
	
	ise_IPFormat(pcHost, pcResult);
	if(pcResult != NULL)
	{
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

/*********************************************
Name: ise_IPFormat
Create Time:2014-02-16
Author:Ji Zhonghao
Input arg:host: CHAR *pcHost
Output arg:CHAR *pcResult
Return: 
Description: Check if the host is IP format, then copy it
*********************************************/
VOID ISEUrl::ise_IPFormat(IN CHAR *pcHost, OUT CHAR *pcResult)
{
	ULONG ulAddr = 0;
	
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
			return ;
		}
		}
		pcResult[0] = '\0';
		strncpy(pcResult, pcHost, iLen);
	}
	
	return;
}

/*********************************************
Name: BOOL ise_IsValidHost(CONST CHAR *pcHost) CONST
Create Time:2014-02-12
Author:Ji Zhonghao
Input arg:host: host string
Output arg:
Description: Judge if the host is valid
*********************************************/
BOOL ISEUrl::ise_IsValidHost(CONST CHAR *pcHost) CONST
{
	if(NULL == pcHost)
		return false;

	boost::regex expression("[0-9a-zA-Z\\-.:_]+");
	return boost::regex_match(pcHost, expression);
}

/*********************************************
Name: BOOL ise_IsValidIP(CONST CHAR* pcIP) CONST
Create Time:2014-02-12
Author:Ji Zhonghao
Input arg:host: IP string
Output arg:
Description: Judge if the IP is valid
*********************************************/
BOOL ISEUrl::ise_IsValidIP(CONST CHAR* pcIP) CONST
{
	if(NULL == pcIP)
	{
		return FALSE;
	}

	ULONG ulAddr = (ULONG)inet_addr(pcIP);
	if(INADDR_NONE == ulAddr)
	{`
		return FALSE;
	}

	return TRUE;
}

BOOL ISEUrl::ise_IsValidHostChar(IN CONST CHAR cTest)
{
	if((cTest < '9' && cTest >'0') || (cTest < 'Z' && cTest > 'A')||
	   (cTest < 'z' && cTest > 'a')|| ('\\' == cTest) || ('-' == cTest)||
	   ('.' == cTest) || (':' == cTest) || ('_' == cTest))
	{
		return true;
	}	
	
	return false;
}

