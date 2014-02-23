#include "basetype.h"
#include <string>
#include <sstream>

class ISEStr
{
public:
	static VOID	ISE_Str2LowerCase(std::string &szStr);
	static std::string ISE_IToS(IN INT iInput)
	{
		std::stringstream stream;
		stream<<iInput;
		return stream.str();
	}
	static std::string::size_type ISE_StrFindIgnoreCase(IN const std::string &szInput, IN const std::string &szToFind);
	static std::string::size_type ISE_StrFindIgnoreCaseEx(IN const std::string &szInput, 
									                      IN const std::string &szToFind, 
														  IN const INT iIndex);
	static INT ISE_StrReplaceStr(IN const std::string szDstStr, IN std::string szSrcStr);
	static INT ISE_StrEraseStr(IN std::string &szInput, IN const std::string &szSubstr);
};