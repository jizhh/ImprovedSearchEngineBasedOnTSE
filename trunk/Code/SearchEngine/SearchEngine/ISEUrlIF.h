/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.h
*Author: Zhonghao Ji
*Description: Url Interface Declaration
**********************************************/
#pragma once
#include "basetype.h"
#include <string>
#include <memory>

class ISEUrl;
class Test;
class ISEUrlIF
{
public:
	explicit ISEUrlIF(INT iPort = DEFAULT_PORT, url_scheme_e e_scheme = SCHEME_HTTP, CONST std::string &szUrl ="");
	virtual ~ISEUrlIF(VOID);
	VOID fun(Test& t);
	/*解析URL*/
	CHAR *ise_GetIPByHost(CONST CHAR* pcHost);
	BOOL ISE_ParseUrl(std::string szUrl);
private:
	std::tr1::shared_ptr<ISEUrl> pUrlImpl;
	INT iPort;
	url_scheme_e eScheme;
	std::string szHost;
	std::string szPath;
	std::string szUrl;
	/*解析协议*/
	VOID ise_parseScheme(CONST CHAR* pcUrl);
};

