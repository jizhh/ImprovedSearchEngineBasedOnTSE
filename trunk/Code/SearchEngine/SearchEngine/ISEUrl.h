#pragma once
#include <string>

typedef enum tag_url_scheme
{
	SCHEME_HTTP,
	SCHEME_FTP,
	SCHEME_BUTT
}url_scheme_e;

class ISEUrl
{
public:
	std::string szUrl;
	url_scheme_e eScheme;
	std::string szHost;
	int iPort;
	std::string szPath;
public:
	ISEUrl(void);
	~ISEUrl(void);
	/*����URL*/
	bool ISE_ParseUrl(std::string szUrl);
private:
	/*����Э��*/
	void ise_parseScheme(const char* pcUrl);
};

