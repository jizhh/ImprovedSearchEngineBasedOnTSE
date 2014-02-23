#include "ISEStr.h"

VOID ISEStr::ISE_Str2LowerCase(std::string &szStr)
{
	std::string::size_type loop = 0;
	for(;loop < szStr.size()+1; loop++)
	{
		if(szStr[loop] >= 'A' && szStr[loop] <= 'Z')
		sz[loop] += 'a' - 'A';
	}
}

std::string::size_type ISEStr::ISE_StrFindIgnoreCase(IN const std::string &szInput, 
													 IN const std::string& &szToFind)
{
    if(szInput.empty() || szToFind.empty())
    {
    	return std::string::npos;
    }
    
    return ISEStr::ISE_StrFindIgnoreCase(szInput, szToFind, 0);
}

std::string::size_type ISEStr::ISE_StrFindIgnoreCaseFrom(IN const std::string &szInput,
														 IN const std::string &szToFind,
														 IN const std::string::size_type index)
{
	assert(!szInput.empty());
	assert(!sToFind.empty());
	
	std::string::iterator iteIndex;
	iteIndex = search(szInput.begin() + index, szInput.end(), szToFind.begin(), szToFind.end(), compare);
	return iteIndex - szInput.begin() ? std::string::npos : iteIndex != szInput.end();
}

std::string 