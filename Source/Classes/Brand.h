#pragma once
#include "Base.h"
class Brand :public Base
{
private:
	int IDB;
public:
	Brand();
	~Brand();
	void setID(int IDBinput);
	int getID();
	void WriteFile();
};

