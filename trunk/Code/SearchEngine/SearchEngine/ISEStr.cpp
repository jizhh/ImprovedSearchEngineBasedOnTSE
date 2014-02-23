#include "ISEStr.h"
#include <algorithm>
#include <assert.h>

BOOL compare(const CHAR cPara1, const CHAR cPara2)
{
	return tolower(cPara1) == tolower(cPara2);
}

VOID ISEStr::ISE_Str2LowerCase(std::string &szStr)
{
	std::string::size_type loop = 0;
	for(;loop < szStr.size()+1; loop++)
	{
		if(szStr[loop] >= 'A' && szStr[loop] <= 'Z')
		szStr[loop] += 'a' - 'A';
	}
}

std::string::size_type ISEStr::ISE_StrFindIgnoreCase(IN const std::string &szInput, 
													 IN const std::string &szToFind)
{
    if(szInput.empty() || szToFind.empty())
    {
    	return std::string::npos;
    }
    
    return ISEStr::ISE_StrFindIgnoreCaseEx(szInput, szToFind, 0);
}

std::string::size_type ISEStr::ISE_StrFindIgnoreCaseEx(IN const std::string &szInput,
													   IN const std::string &szToFind,
													   IN const INT iIndex)
{
	assert(!szInput.empty());
	assert(!szToFind.empty());
	
	std::string::const_iterator iteIndex;
	iteIndex = search(szInput.begin() + iIndex, szInput.end(), szToFind.begin(), szToFind.end(), compare);
	return iteIndex - szInput.begin() ? std::string::npos : iteIndex != szInput.end();
}