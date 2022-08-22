#pragma once
#include "Base.h"
class Seller :public Base
{
private:
	 
	string SAddress,SName;
	int IDS, SNumber;
public:
	Seller();
	~Seller();
	void setName(string Selname);
	string getName();
	void setNumber(int Ninput);
	int getNumber();
	void setAddress(string Addinput);
	string getAddress();
	void setIDS(int IDSinput);
	int getIDS();
	void WriteFile();
};

