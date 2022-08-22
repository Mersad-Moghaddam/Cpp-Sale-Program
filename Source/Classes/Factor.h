#pragma once
#include "Customer.h"
#include "Product.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Factor:public Base
{
private:
	int CID,PID,Units,Cost;
	//int Time;
	string CName,PName;
	//vector<Product>Products;
	//double Sum = 0;
public:
	Factor();
	~Factor();
	void setCID(int i);
	void setPID(int i);
	void setPName(string i);
	void setCName(string i);
	void setUnits(int i);
	void setCost(int i);
	int getCID();
	int getPID();
	string getPName();
	string getCName();
	int getUnits();
	int getCost();
	void WriteFile();
	void FiletoProject(string x);

	//void setCID(int CIDinput);
	//void setFacNum(int FNinput);
	//int getFactNum();
	//void setTime(int Tinput);
	//int getTime();
	//void setDate(string Dinput);
	//string getDate();
	//void AddtoCart(Product Pinput,int count);
	//void RemoveFromCart();
	//void PrintCart();
	//void ChangeSum(int price, int c);
	//int getSum();
};

