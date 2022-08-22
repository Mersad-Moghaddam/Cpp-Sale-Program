#pragma once
#include "Base.h"
class Category:public Base
{
private:
	int IDC;
public:
	Category();
	~Category();
	void setID(int IDCinput);
	int getID();
	void WriteFile();
};

