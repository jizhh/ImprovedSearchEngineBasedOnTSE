/**********************************************
*Copyright 2014 Zhonghao Ji
*File: ISEUrl.cpp
*Author: Zhonghao Ji
*Description: Url Interface Defination
**********************************************/
#include "ISEUrlIF.h"
#include "ISEUrl.h"

/*********************************************
Func Name: ISEUrlIF(INT iPort,url_scheme_e e_scheme, CONST std::string &szUrl)
Created Date:2014-01-01
Author:Ji Zhonghao
Input arg:iPort: port number
          e_scheme: enum schemer
		  szUrl: url content
Output arg:None
Description: Url Class Construction, pass parameters to the implemented class
*********************************************/
ISEUrlIF::ISEUrlIF(INT iPort, 
				   url_scheme_e e_scheme, 
				   CONST std::string &szUrl):pUrlImpl(new ISEUrl(iPort, e_scheme, szUrl))
{
}

ISEUrlIF::~ISEUrlIF(VOID)
{
}
