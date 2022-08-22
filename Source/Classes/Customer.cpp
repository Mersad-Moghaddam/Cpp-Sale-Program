#include "stdafx.h"
#include "Customer.h"
#include "List.h"
#include "Factor.h"


Customer::Customer()
{
}
Customer::~Customer()
{
}
void Customer::setCuName(string Nameinput)
{
	CuName = Nameinput;
}
string Customer::getCuName()
{
	return CuName;
}
void Customer::setNumber(int Ninput) {
	CNumber = Ninput;
}
int Customer::getNumber() {
	return CNumber;
}
void Customer::setCuID(int Cid) {
	CUID = Cid;
}
int Customer::getCuID() {
	return CUID;
}
void Customer::setAddress(string Addinput) {
	CAddress = Addinput;
}
string Customer::getAddress() {
	return CAddress;
}
void Customer::setWallet(int wallet) {
	Cwallet = wallet;
}
int Customer::getWallet() {
	return Cwallet;
}
//void Customer::searchCustomer(int cId)
//{
//	List*l=new List;
	//int I=l->CusIndex(I);
	//for(int i=0;i<I;i++){
		//Customer *PI=new Customer;
		//if(i==PI->)
	////}
	//ifstream input("Customer.txt");
//	while(input >> CUID) {
		//if (cId == CUID) {
		//	cout << left << " " << "\t" << getCuID() << "\t" << getName() << "\t" << getNumber() << "\t" << getAddress()
			//	<< "\t" <<getWallet() <<endl;
	//	}
//	}
//}
void Customer::WriteFile() 
{
	ofstream output;
	output.open("Customer.txt", ios::app);
	output << getCuID() << " " << getCuName() << " " << getNumber() << " " << getAddress() << " " << getWallet() << endl;
	output.close();
}
