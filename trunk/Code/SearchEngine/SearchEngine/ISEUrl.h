/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.h
*Author: Zhonghao Ji
*Description: Url Class Declaration
**********************************************/
#ifndef _ISEURL_H_
#define _ISEURL_H_

#pragma once
#include <string>
#include "basetype.h"
#include <boost\thread\mutex.hpp>
#include <boost\thread\lock_guard.hpp>
#include <boost\regex.h>
#include <WinSock.h>

class ISEUrl
{
public:
	explicit ISEUrl(INT iPort = DEFAULT_PORT, url_scheme_e e_scheme = SCHEME_HTTP, CONST std::string &szUrl = ""):iPort(iPort),eScheme(e_scheme),szUrl(szUrl){};
	virtual ~ISEUrl(VOID);
	/*解析URL*/
	BOOL ISE_ParseUrl(std::string szUrl);
	static char *ISE_GetIPByHost(const char* pcHost);
	bool ISE_IsValidIP(const char *pcHost) const;
private:
	INT iPort;
	url_scheme_e eScheme;
	std::string szHost;
	std::string szPath;
	std::string szUrl;
	/*解析协议*/
	VOID ise_parseScheme(CONST CHAR* pcUrl){};
};
#endif
