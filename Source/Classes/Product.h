#pragma once
#include <iostream>
#include <iomanip>
#include "Category.h"
#include "Brand.h"
#include "Seller.h"
using namespace std;
class Product :public Category, public Brand, public Seller
{
private:
	int Stock;
	int Price;
	int IDP;
	int Loc;
public:
	Product();
	~Product();
	int setStock(int Sinput);
	int getStock();
	void ChangeProStock(int Uinput);
	int setPrice(int Pinput);
	int getPrice();
	void setID(int IDPinput);
	int getID();
	void setLoc(int Linput);
	int getLoc();
	void PrintProductinfo();
};

