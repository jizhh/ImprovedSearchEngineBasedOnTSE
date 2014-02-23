/**********************************************
*Copyright 2014 Zhonghao Ji
*File: basetype.h
*Author: Zhonghao Ji
*Description: substitute the raw basetype for ISE's style
**********************************************/

#ifndef _BASE_TYPE_
#define _BASE_TYPE_

#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#include <Windows.h>
#endif

#define INOUT

#define DEFAULT_PORT 80
#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46

typedef enum tag_url_scheme
{                                 
	SCHEME_HTTP,
	SCHEME_FTP,
	SCHEME_BUTT
}url_scheme_e;

#endif
