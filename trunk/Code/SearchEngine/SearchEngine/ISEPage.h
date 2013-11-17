/**********************************************
*
*
*
**********************************************/

#pragma once
#include <string>
#include <map>
#include <vector>

class ISEPage
{
public:
	/*网页头信息*/
	std::string szUrl;
	std::string szHeader;
	std::string szLocation;
	std::string szContentEncoding;
	std::string szContentType;
	std::string szCharSet;
	std::string szTransferEncoding;
	int iHeaderLen;
	int iStatusCode;
	int iHeaderContentLength;
	bool bConnectionState;

	/*网页体信息*/
	std::string szContent;
	std::string szContentNoTags;
	std::string szContentLinkInfo;
	/*为搜索引擎准备的链接*/
	std::string szLinkInfoForISE;
	/*为历史存档准备的链接*/
	std::string szLinkinfoForHistory;
	int iLinkInfoForHistoryLen;

	int iLinkInfoForISELen;
	int iContentLen;
public:
	ISEPage(void);
	ISEPage(std::string szUrl, 
		    std::string szLocation, 
		    char* pcHeader, 
			char* pcBody,
			int iBodyLen);
	void ISE_ParseHeaderInfo(std::string szHeader);
	/*解析链接信息*/
	bool ISE_ParseHyperLink();
	bool ISE_NormallizeUrl(std::string &szUrl);
	bool ISE_IsFilterLink(std::string szLink);
	~ISEPage(void);
private:
	/* 解析网页头信息*/
	void ise_GetStatusCode(std::string header);
	void ise_GetContentLength(std::string header);
	void ise_GetConnectionState(std::string header);
	void ise_GetLocation(std::string header);
	void ise_GetCharset(std::string header);
	void ise_GetContentEncoding(std::string header);
	void ise_GetContentType(std::string header);
	void ise_GetTransferEncoding(std::string header);
	/* 从网页体中解析链接信息*/
	bool ise_GetContentLinkInfo();
	bool ise_GetLinkInfo4SE();
	bool ise_GetLinkInfo4History();
	bool ise_FindRefLink4SE();
	bool ise_FindRefLink4History();
};

