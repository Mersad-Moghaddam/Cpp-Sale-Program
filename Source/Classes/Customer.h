#pragma once
#include "Base.h"
class Customer :public Base
{
private:
	int CNumber,Cwallet,CUID=0;
	string CAddress,CuName;
public:
	Customer();
	~Customer();
	void setCuName(string Nameinput);
	string getCuName();
	void setNumber(int Ninput);
	int getNumber();
	void setCuID(int Ninput);
	int getCuID();
	void setAddress(string Addinput);
	string getAddress();
	void setWallet(int wallet);
	int getWallet();
	void searchCustomer(int cId);
	void WriteFile();
};

