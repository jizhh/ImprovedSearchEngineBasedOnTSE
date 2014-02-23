/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEPage.h
*Author: Zhonghao Ji
*Description: Page Class Declaration
**********************************************/

#pragma once
#include <string>
#include <map>
#include <vector>
#include "basetype.h"

class ISEPage
{
public:
	INT iHeaderLen;
	INT iStatusCode;
	INT iHeaderContentLength;
	BOOL bConnectionState;
	/*网页头信息*/
	std::string szUrl;
	std::string szHeader;
	std::string szLocation;
	std::string szContentEncoding;
	std::string szContentType;
	std::string szCharSet;
	std::string szTransferEncoding;

	/*网页体信息*/
	std::string szContent;
	std::string szContentNoTags;
	std::string szContentLinkInfo;
	/*为搜索引擎准备的链接*/
	std::string szLinkInfoForISE;
	/*为历史存档准备的链接*/
	std::string szLinkinfoForHistory;
	INT iLinkInfoForHistoryLen;

	INT iLinkInfoForISELen;
	INT iContentLen;
public:
	ISEPage(VOID);
	ISEPage(std::string szUrl, 
		    std::string szLocation, 
		    CHAR* pcHeader, 
			CHAR* pcBody,
			INT iBodyLen);
	void ISE_ParseHeaderInfo(std::string szHeader);
	/*解析链接信息*/
	BOOL ISE_ParseHyperLink();
	BOOL ISE_NormallizeUrl(std::string &szUrl);
	BOOL ISE_IsFilterLink(std::string szLink);
	~ISEPage(VOID);
private:
	/* 解析网页头信息*/
	VOID ise_GetStatusCode(std::string &szHeader);
	VOID ise_GetContentLength(std::string szHeader);
	VOID ise_GetConnectionState(std::string szHeader);
	VOID ise_GetLocation(std::string szHeader);
	VOID ise_GetCharset(std::string szHeader);
	VOID ise_GetContentEncoding(std::string szHeader);
	VOID ise_GetContentType(std::string szHeader);
	VOID ise_GetTransferEncoding(std::string szHeader);
	/* 从网页体中解析链接信息*/
	BOOL ise_GetContentLinkInfo();
	BOOL ise_GetLinkInfoForSE();
	BOOL ise_GetLinkInfoForHistory();
	BOOL ise_FindRefLinkForSE();
	BOOL ise_FindRefLinkForHistory();
};

