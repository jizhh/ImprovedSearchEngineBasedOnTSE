/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.cpp
*Author: Zhonghao Ji
*Description: Url Class Defination
**********************************************/
#include "ISEUrl.h"
/*********************************************
Name: ISEurl(void)
Create Time:2014-01-01
Author:Ji Zhonghao
Input arg:
Output arg:
Description: Url Class Destruction
*********************************************/
ISEUrl::~ISEUrl(VOID)
{
}

/*********************************************
Name: const static char* ISE_GetIPByHost(const char * pcHost)
Create Time:2014-01-13
Author:Ji Zhonghao
Input arg:host: host string
Output arg:
Description: get IP address via host name
*********************************************/
char * ISEUrl::ISE_GetIPByHost(const char * pcHost)
{
}

bool ISEUrl::ISE_IsValidIP(const char *pcHost) const
{
	if(NULL == pcHost)
		return false;
}


