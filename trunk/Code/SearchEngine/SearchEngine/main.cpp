#include "ISEUrlIF.h"
#include <iostream>
INT main()
{
	ISEUrlIF* pUrl = new ISEUrlIF;
	pUrl->ise_GetIPByHost("1.1.1.1");
}