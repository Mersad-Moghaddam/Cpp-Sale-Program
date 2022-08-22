#include "stdafx.h"
#include "List.h"
#include "Product.h"
#include "Factor.h"
#include <windows.h>

List::List()
{
	Procounter = 0;
	Catcounter = 0;
	Cuscounter = 0;
	Selcounter = 0;
	Brcounter = 0;
	Fcounter = 0;

}
List::~List()
{
}
void List::AddFactor(Factor F) {
	FacList.push_back(F);
}
void List::RemoveProduct() {
	////
}
void List::EditProduct() {
	////.
}
void List::ShowProducts() {
	Header();
	for (int i = 0; i < Procounter; i++) {
		ProList[i].PrintProductinfo();
	}
}
void List::AddCategory(Category Ca)
{
	CateList.push_back(Ca);
}
void List::AddBrand(Brand B)
{
	BraList.push_back(B);
	Brcounter++;
}
void List::ChangeStock(int idinput,int Uinput) {
	Product *ppro = new Product;
	int c;
	for (int i = 0; i < ProList.size(); i++) {
		if (idinput == ProList[i].getID())
		{
			c = i;
			ProList[i].ChangeProStock(Uinput);
			
			
		}
	}
	ProList[c].PrintProductinfo();

}
void List::AddCustomer(Customer Cu)
{
	CustList.push_back(Cu);
	Cuscounter++;
}
//void List::ShowCustomer() {
	//Header();
	//for (int i = 0; i < Procounter; i++) {
		//ProList[i].PrintCustomerinfo();
	//
void List::AddSeller(Seller S)
{
	SellList.push_back(S);
}
void List::AddProduct(Product P) {
	//Adds to Product List
	ProList.push_back(P);
	//Sorts Them
	//sort(ProList.begin(), ProList.end());
	//Changes Counter
	Procounter++;
	//HeaderPro();
}
int List::getprocounter()
{
	return Procounter;
}
void List::Header() {
	////
}

int List::getPrC() {
	return Procounter;
}
int List::getCaC() {
	return CateList.size();
}
int List::getCuC() {
	return Cuscounter;
}
int List::getSeC() {
	return Selcounter;
}
int List::getBrC() {
	return BraList.size();
}
int List::ProSize() {
	return ProList.size();
}
int List::CustSelect(int i) {
	return CustList[i].getCuID();
}
string List::CustNameSelect(int i) {
	return CustList[i].getCuName();
}
int List::CustWalletSelect(int i) {
	return CustList[i].getWallet();
}
int List::ProStockSelect(int i) {
	return ProList[i].getStock();
}
int List::ProPriceSelect(int i) {
	return ProList[i].getPrice();
}
string List::ProNameSelect(int i) {
	return ProList[i].Base::getName();
}
int List::ProSelect(int i) {
	return ProList[i].getID();
}
void List::ProChangeStockSelect(int i, int x) {
	ProList[i].ChangeProStock(x);
}
void List::CustChangeWalletSelect(int i, int x) {
	CustList[i].setWallet(x);
}
Product List::ProIndex(int i) {
	return ProList.at(i);
}
Customer List::CusIndex(int i) {
	return CustList.at(i);
}

void List::WriteFile() {
	ofstream OutProduct;
	int ID=0;
	OutProduct.open("Products.txt", ios::trunc);
	for (int i = 0; i < ProList.size(); i++) {
		int x = ProList[i].getID();
		if (x != ID) {
			OutProduct<<" "<< ProList[i].getID() << setw(6) << ProList[i].Base::getName() << setw(12) << ProList[i].getPrice() << setw(6) << ProList[i].getStock() << setw(4)
				<< ProList[i].Brand::getID() << setw(4) << ProList[i].Category::getID() << setw(4) << ProList[i].getIDS() << "\n";
			ID = x;
		}
	}
	
	OutProduct.close();
}
void List::FiletoProject(string x) {
	ifstream input("Products.txt");
	if (input.is_open()) {
		string Q;
		
		cout << left << " " << setw(3) << "ID" << setw(12) << "Name" << setw(6) << "Price" << setw(6) << "Stock"
			<< setw(4) << "BID" << setw(4) << "CID" << setw(4) << "SID\n";
		while (getline(input, x)) {
			if (Q != x) {
				
				cout << x << endl;
			}
			Q=x;
		}
		input.close();
	}
	else cout << "Unable to open file";
}
void List::ShowC(string x) {
	ifstream innput("Customer.txt");
	if (innput.is_open()) {
		string Q;
		
		cout << left << " " << setw(6) << "CuID" << setw(12) << "CuName" << setw(8) << "Number" << setw(12) << "Address" << setw(12) << "Wallet" << endl;
		while (getline(innput, x)) {
			if (Q != x) {
				
				cout << x << endl;
			}
			Q = x;
		}
		innput.close();
	}
	else cout << "Unable to open file";
}
void List::WriteC() {
	ofstream OutCustomer;
	int ID = 0;
	OutCustomer.open("Customer.txt", ios::trunc);
	for (int i = 0; i < CustList.size(); i++) {
		int x = CustList[i].getCuID();
		string y = CustList[i].getCuName();
		if (x != ID ) {
			OutCustomer<<setw(4) << CustList[i].getCuID()<<"   "<< setw(3) << CustList[i].getCuName() << setw(12) << CustList[i].getNumber() << setw(6) << CustList[i].getAddress() << setw(12)
				<< CustList[i].getWallet() << endl;
			ID = x;
		}
	}
	OutCustomer.close();
}