#pragma once
#include <map>

class ISEHttp
{
private:
	std::string szUrl;	
	int *piSock;		

public:
	ISEHttp();
	virtual ~ISEHttp();

	int ISE_Fetch(std::string strUrl, 
		      char **ppcFileBuf, 
			  char **ppcFileHead, 
			  char **ppcLocation, 
			  int* piSock);

private:
	int ise_read_header(int iSock, char *pcHeaderPtr);
	int ise_CreateSocket(const char *pcHost, int iPort);

	int ise_nonb_connect(int, struct sockaddr*, int);
	int ise_checkBufSize(char **buf, int *bufsize, int more);
};

