#pragma once
class CNoncopy
{
public:
	CNoncopy(void){};
	~CNoncopy(void){};
private:
	CNoncopy(const CNoncopy& Copy);
	CNoncopy& operator=(const CNoncopy& Copy);
};

