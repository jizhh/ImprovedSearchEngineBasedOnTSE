/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEHttp.h
*Author: Zhonghao Ji
*Description: HTTP Class Declaration
**********************************************/
#ifndef _ISEHTTP_H_
#define _ISEHTTP_H_

#pragma once
#include <map>
#include "basetype.h"

class	ISEHttp
{
public:
	ISEHttp();
	virtual ~ISEHttp();

	INT ISE_Fetch(std::string strUrl, 
		          CHAR **ppcFileBuf, 
			      CHAR **ppcFileHead, 
			      CHAR **ppcLocation, 
				  INT* piSock);

private:
	INT ise_read_header(INT iSock, CHAR *pcHeaderPtr);
	INT ise_CreateSocket(CONST CHAR *pcHost, INT iPort);

	INT ise_nonb_connect(INT, struct sockaddr*, INT);
	INT ise_checkBufSize(CHAR **buf, INT *bufsize, INT more);
	INT *piSock;
	std::string szUrl;
};
#endif

