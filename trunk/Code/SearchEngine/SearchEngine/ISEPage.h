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
	/*��ҳͷ��Ϣ*/
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

	/*��ҳ����Ϣ*/
	std::string szContent;
	std::string szContentNoTags;
	std::string szContentLinkInfo;
	/*Ϊ��������׼��������*/
	std::string szLinkInfoForISE;
	/*Ϊ��ʷ�浵׼��������*/
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
	/*����������Ϣ*/
	bool ISE_ParseHyperLink();
	bool ISE_NormallizeUrl(std::string &szUrl);
	bool ISE_IsFilterLink(std::string szLink);
	~ISEPage(void);
private:
	/* ������ҳͷ��Ϣ*/
	void ise_GetStatusCode(std::string szHeader);
	void ise_GetContentLength(std::string szHeader);
	void ise_GetConnectionState(std::string szHeader);
	void ise_GetLocation(std::string szHeader);
	void ise_GetCharset(std::string szHeader);
	void ise_GetContentEncoding(std::string szHeader);
	void ise_GetContentType(std::string szHeader);
	void ise_GetTransferEncoding(std::string szHeader);
	/* ����ҳ���н���������Ϣ*/
	bool ise_GetContentLinkInfo();
	bool ise_GetLinkInfoForSE();
	bool ise_GetLinkInfoForHistory();
	bool ise_FindRefLinkForSE();
	bool ise_FindRefLinkForHistory();
};

