/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.h
*Author: Zhonghao Ji
*Description: Url Class Declaration
**********************************************/
#ifndef _ISEURL_H_
#define _ISEURL_H_

#pragma once
#include "basetype.h"
#include <WinSock2.h>
#include <string>
#include <boost\thread\mutex.hpp>
#include <boost\thread\lock_guard.hpp>
#include <boost\regex.hpp>
#include <boost\thread\recursive_mutex.hpp>
#include <boost\thread\lockable_adapter.hpp>

#define PROTOCOL_LEN 10
#define HOST_LEN 256
#define REQUEST_LEN 256
#define INVALID_PORT -1

typedef struct tag_ISEUrlPara {
	INT iPort;
	CHAR acProtocol[PROTOCOL_LEN];
	CHAR acHost[HOST_LEN];
	CHAR acRequest[REQUEST_LEN];
}ISEURL_PARA_s;

class ISEUrl
	:public boost::basic_lockable_adapter<boost::recursive_mutex>
{
public:
	explicit ISEUrl(IN INT iPort = DEFAULT_PORT,
				    IN url_scheme_e e_scheme = SCHEME_HTTP, 
				    IN CONST std::string &szUrl = ""):iPort(iPort),eScheme(e_scheme),szUrl(szUrl){};
	virtual ~ISEUrl(VOID);
	/*½âÎöURL*/
	BOOL ise_ParseUrl(std::string szUrl);
	BOOL ise_IPFormat(IN CHAR *pcHost, OUT CHAR *pcResult);
	BOOL ise_ParseUrlEx(IN CHAR *pcUrl,
						INOUT VOID *pPara);
	CHAR *ise_GetIPByHost(IN CONST CHAR* pcHost);
	BOOL ise_IsValidIP(IN CONST CHAR *pcIP) CONST;
	BOOL ise_IsValidHost(IN CONST CHAR *pcHost) CONST;
	BOOL ise_IsValidHostChar(IN CONST CHAR cInput);
private:
	static boost::mutex _mutex;
	INT iPort;
	url_scheme_e eScheme;
	std::string szHost;
	std::string szPath;
	std::string szUrl;
	/*½âÎöÐ­Òé*/
	VOID ise_parseScheme(CONST CHAR* pcUrl){};
};
#endif
