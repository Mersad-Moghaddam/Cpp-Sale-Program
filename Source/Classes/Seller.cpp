#include "stdafx.h"
#include "Seller.h"


Seller::Seller()
{
}


Seller::~Seller()
{
}
void Seller::setName(string Selname) {
	SName = Selname;
}
string Seller :: getName() {
	return SName;
}
void Seller::setNumber( int Ninput) {
	SNumber = Ninput;
}
int Seller::getNumber() {
	return SNumber;
}
void Seller::setAddress(string Addinput) {
	SAddress = Addinput;
}
string Seller::getAddress() {
	return SAddress;
}
void Seller::setIDS(int IDSinput) {
	IDS = IDSinput;
}
int Seller::getIDS() {
	return IDS;
}
void Seller :: WriteFile() {
	ofstream output;
	output.open("Seller.txt", ios::app);
	output << getIDS() << " " << getName() << " " << getAddress() << " " << getNumber() << endl;
	output.close();
}