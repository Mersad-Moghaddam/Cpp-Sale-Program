#pragma once
#include <fstream>
#include <string>
#include <iostream>
//#include "Functions.h"
using namespace std;

class Base
{
private:
	string Name;
public:
	Base();
	~Base();
	void setName(string inputname);
	string getName();

};

