#include "stdafx.h"
#include "Product.h"

Product::Product()
{
	Price = 0;
	Stock = 0;
	Base::setName("Default");
	IDP = 0;
}
Product::~Product()
{
}
int Product::setStock(int Sinput) {
	try {
		if (Sinput > 0)
		{
			Stock = Sinput;
			return 1;
		}
		else throw invalid_argument("Exception for setstock is caught");
	}
	catch (invalid_argument &e) { cerr << "\n\nException while initializing stock:" << e.what() << endl; }
	return 0;

}
void Product::ChangeProStock(int Uinput)
{
	Stock += Uinput;
}

int Product::getStock() {
	return Stock;
}
int Product::setPrice(int Pinput) {
	try {
		if (Pinput > 0)
		{
			Price = Pinput;
			return 1;
		}
		else throw invalid_argument("Exception for setstock is caught");
	}
	catch (invalid_argument &e) { cerr << "\n\nException while initializing stock:" << e.what() << endl; }
	return 0;
}
int Product::getPrice() {
	return Price;
}
void Product::setID(int IDPinput) {
	IDP = IDPinput;
}
int Product::getID() {
	return IDP;
}
void Product::setLoc(int Linput) {
	Loc = Linput;
}
int Product::getLoc() {
	return Loc;
}


//Print Product info
void Product::PrintProductinfo() {
	//3-12-6-6-4-4-4
	cout << left << " " << setw(3) << getID() << setw(12) << Base::getName() << setw(6) << getPrice() << setw(6) << getStock()
		<< setw(4) << Brand::getID() << setw(4) << Category::getID() << setw(4) << getIDS() << "\n";
}

