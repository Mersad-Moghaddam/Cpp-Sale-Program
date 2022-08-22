#include "stdafx.h"
#include "Factor.h"
#include <windows.h>

Factor::Factor()
{
}

Factor::~Factor()
{
}

void Factor::setCID(int i) {
	CID = i;
}
void Factor::setCName(string i) {
	CName = i;
}
void Factor::setPID(int i) {
	PID = i;
}
void Factor::setPName(string i) {
	PName = i;
}
void Factor::setUnits(int i) {
	Units = i*(-1);
}
void Factor::setCost(int i) {
	Cost = i;
}
int Factor::getCID() {
	return CID;
	//for (int i = 0; i < Products.size(); i++) {
		//if (Products[i].getID() == Pinput.getID()) {
			//Products[i].ChangeProStock(count);
			//return;
		//}
	//}
	//Pinput.setStock(count);
	//ChangeSum(Pinput.getPrice(), count);
	//Products.push_back(Pinput);
}
int Factor::getPID() {
	return PID;
	//Products;
}
string Factor::getPName() {
	return PName;
	//for (int i = 0; i < Products.size(); i++) {
		//cout << ' '<< Products[i].Base::getName() << ' ' << Products[i].getID() << ' ' << Products[i].getStock() << ' ' << Products[i].getPrice() << ' ';
		//cout << Products[i].Category::getID() << ' ' << Products[i].Category::getID() << ' ' << Products[i].getIDS() << "\n";
	//}
}
string Factor::getCName () {
	return CName;
}
int Factor::getUnits() {
	return Units;
	//return Sum;
}
int Factor::getCost() {
	return Cost;
}
void Factor::WriteFile() {
	ofstream output;
	output.open("Factor.txt", ios::app);
	output << getCName() << setw(12) << getCID() << setw(6) << getPID() << setw(6) << getPName()
		<< setw(6) << getUnits() << setw(6) << getCost() << setw(6) << "\n";
	output.close();
}
void Factor::FiletoProject(string x) {
	ifstream input("Factor.txt");
	if (input.is_open()) {
		cout <<setw(6) << "CName" << setw(12) << "IDC" << setw(6) << "IDP" << setw(6) << "PName"
			<< setw(6) << "Units" << setw(6) << "Cost" << setw(6) << "\n";
		while (getline(input, x)) {
			cout << x << endl;
		}
		input.close();
	}
	else cout << "Unable to open file";
}