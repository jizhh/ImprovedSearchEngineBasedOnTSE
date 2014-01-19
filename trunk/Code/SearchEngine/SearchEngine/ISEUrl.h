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

class ISEUrl
	:public boost::basic_lockable_adapter<boost::recursive_mutex>
{
public:
	explicit ISEUrl(INT iPort = DEFAULT_PORT, url_scheme_e e_scheme = SCHEME_HTTP, CONST std::string &szUrl = ""):iPort(iPort),eScheme(e_scheme),szUrl(szUrl){};
	virtual ~ISEUrl(VOID);
	/*解析URL*/
	BOOL ise_ParseUrl(std::string szUrl);
	CHAR *ise_GetIPByHost(CONST CHAR* pcHost);
	BOOL ise_IsValidIP(CONST CHAR *pcHost) CONST;
private:
	boost::mutex _mutex;
	INT iPort;
	url_scheme_e eScheme;
	std::string szHost;
	std::string szPath;
	std::string szUrl;
	/*解析协议*/
	VOID ise_parseScheme(CONST CHAR* pcUrl){};
};
#endif
