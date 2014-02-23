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
	/*��ҳͷ��Ϣ*/
	std::string szUrl;
	std::string szHeader;
	std::string szLocation;
	std::string szContentEncoding;
	std::string szContentType;
	std::string szCharSet;
	std::string szTransferEncoding;

	/*��ҳ����Ϣ*/
	std::string szContent;
	std::string szContentNoTags;
	std::string szContentLinkInfo;
	/*Ϊ��������׼��������*/
	std::string szLinkInfoForISE;
	/*Ϊ��ʷ�浵׼��������*/
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
	/*����������Ϣ*/
	BOOL ISE_ParseHyperLink();
	BOOL ISE_NormallizeUrl(std::string &szUrl);
	BOOL ISE_IsFilterLink(std::string szLink);
	~ISEPage(VOID);
private:
	/* ������ҳͷ��Ϣ*/
	VOID ise_GetStatusCode(std::string &szHeader);
	VOID ise_GetContentLength(std::string szHeader);
	VOID ise_GetConnectionState(std::string szHeader);
	VOID ise_GetLocation(std::string szHeader);
	VOID ise_GetCharset(std::string szHeader);
	VOID ise_GetContentEncoding(std::string szHeader);
	VOID ise_GetContentType(std::string szHeader);
	VOID ise_GetTransferEncoding(std::string szHeader);
	/* ����ҳ���н���������Ϣ*/
	BOOL ise_GetContentLinkInfo();
	BOOL ise_GetLinkInfoForSE();
	BOOL ise_GetLinkInfoForHistory();
	BOOL ise_FindRefLinkForSE();
	BOOL ise_FindRefLinkForHistory();
};

