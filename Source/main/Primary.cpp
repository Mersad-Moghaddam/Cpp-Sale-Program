// Primary.cpp : Defines the entry point for the console application.
//18-6-2022
//???? ??? ??? ???!
//??? ???? ???
// I don't wanna 

// ??? ??? ???? ??? ????? ????

///Libraries
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
//#include "Factor.h"
#include "List.h"
typedef enum {
	Black = 0, Blue = 1, Green = 2,
	Aqua = 3, Red = 4, Purple = 5,
	Yellow = 6, White = 7, Gray = 8,
	LightBlue = 9, LightGreen = 10,
	LightAqua = 11, LightRed = 12,
	LightPurple = 13, LightYellow = 14,
	LightWhite = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
	Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	BufferInfo bufferInfo;
	if (!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
		return 0;
	Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
	SetConsoleTextAttribute(consoleHandle, color);
	return 1;
}
///Defined Variables & Functions
#define Up 72
#define Down 80
#define Enter 13
#define Clear() system("CLS")


using namespace std;

///Global Variables
int IDP = 0, IDC = 0, IDS = 0, IDB = 0, Stock = 0, Price = 0 ,Number=0 , wallet=0;
string name , address;


///Functions Prototype
void PrintMenu(string MenuList[], int MenuLength, int ptr);
void P(int a, string b, int c);
void Clrchng(int a);
void Selection(int &p, char A, int b);
void HeaderPro();
void DefineProduct(Product &Pin);

int main()
{
	int spID, spPrice, spStock, sbID, scID, ssID;
	int CuID, Number, Wallet;
	string spName,CuName, Address;
	int	Choice = 0, Pointer = 0;
	char Key = 0;

	List Mylist;

	ifstream Text("Products.txt");
	while (Text.peek() != EOF) {
		Product* PImport = new Product;
		Text >> spID;
		PImport->setID(spID);
		Text >> spName;
		PImport->Base::setName(spName);
		Text >> spPrice;
		PImport->setPrice(spPrice);
		Text >> spStock;
		PImport->setStock(spStock);
		Text >> sbID;
		PImport->Brand::setID(sbID);
		Text >> scID;
		PImport->Category::setID(scID);
		Text >> ssID;
		PImport->Seller::setIDS(ssID);
		Mylist.AddProduct(*PImport);
		delete PImport;
	}
	Text.close();
	ifstream CText("Customer.txt");
	while(CText.peek() != EOF){
		Customer* CImport = new Customer;
		CText >> CuID;
		CImport->setCuID(CuID);
		CText >> CuName;
		CImport->setCuName(CuName);
		CText >> Number;
		CImport->setNumber(Number);
		CText >> Address;
		CImport->setAddress(Address);
		CText >> Wallet;
		CImport->setWallet(Wallet);
		Mylist.AddCustomer(*CImport);
		delete CImport;

	}
	CText.close();
	string	MenuList[7] = { "Define","Change Stock","Sell","History","Product List","Show Customers","Exit"};
	string DefineMenu[5] = { "Product","Category","Brand","Seller","Customer" };

	bool Exit = 0;

	while (Exit!=1) {
		P(0,"",1);
		//Printing Menu
		PrintMenu(MenuList, 7, Pointer);
		//Getting Arrow Keys
		Key = _getch();
		Clear();
		if (Key != Enter) {
			//If UP or Down was selected
			Selection(Pointer, Key, 7);
		}
		else {
			//When user pressed Enter
			switch (Pointer) {
			case 0:
				{
					int Pointer = 0;
					char Key = 0;
					bool Exit = 0;
					while (Exit != 1) {
						P(0, "", 1);
						PrintMenu(DefineMenu, 5, Pointer);
						Key = _getch();
						Clear();
						if (Key != Enter) {
							//If UP or Down was selected
							Selection(Pointer, Key, 5);
						}
						else {
							//When user pressed Enter
							//Define Product,Category,Brand,Seller,Customer!
							switch (Pointer) {
							//Define Product
							case 0:
								if (Mylist.getBrC() != 0 && Mylist.getCaC() != 0 /*&& Mylist.getSeC() != 0*/) {
									Product *PProduct = new Product;
									DefineProduct(*PProduct);
									P(0,"",1);
									HeaderPro();
									PProduct->PrintProductinfo();
									//PProduct->WriteProduct();
									Mylist.AddProduct(*PProduct);
									delete PProduct;
								}
								else {
									P(1, "We're currently unable to define product!", 1);
								}
								break;
							case 1:
								{
									Category *PCategory = new Category;
									P(1, "Enter Name:", 2);
									cin >> name;
									PCategory->setName(name);
									P(1, "Enter ID : ", 2);
									cin >> IDC;
									PCategory->setID(IDC);
									PCategory->WriteFile();
									Mylist.AddCategory(*PCategory);
									delete PCategory;
								}
								break;
							case 2:
								{
									Brand *PBrand = new Brand;
									P(1, "Enter Name:", 2);
									cin >> name;
									PBrand->setName(name);
									P(1, "Enter ID : ", 2);
									cin >> IDC;
									PBrand->setID(IDC);
									PBrand->WriteFile();
									Mylist.AddBrand(*PBrand);
									delete PBrand;
								}
								break;
							case 3: {
								Seller *PSeller = new Seller;
								P(1, "Enter Name:", 2);
								cin >> name;
								PSeller->setName(name);
								P(1, "Enter ID : ", 2);
								cin >> IDS;
								PSeller->setIDS(IDS);
								P(1, "Enter Address : ", 2);
								cin >> address;
								PSeller->setAddress(address);
								P(1, "Enter Phone Number : ", 2);
								cin >> Number;
								PSeller->setNumber(Number);
								PSeller->WriteFile();
								Mylist.AddSeller(*PSeller);
								delete PSeller;
							}
								break;
							case 4: {
								Customer *PCustomer = new Customer;
									P(1, "Enter Name:", 2);
									cin >> name;
									PCustomer->setCuName(name);
									P(1, "Enter ID : ", 2);
									cin >> IDC;
									PCustomer->setCuID(IDC);
									P(1, "Enter Address : ", 2);
									cin >> address;
									PCustomer->setAddress(address);
									P(1, "Enter Phone Number : ", 2);
									cin >> Number;
									PCustomer->setNumber(Number);
									P(1, "Enter Wallet : ", 2);
									cin >> wallet;
									PCustomer->setWallet(wallet);
									Mylist.AddCustomer(*PCustomer);
									delete PCustomer;
							}
								break;
							case 5:
								break;
							}
							Exit = 1;
						}
					}
				
				}
				break;
				//Change Stock
			case 1:
				{
				int id, update;
				P(1, "Enetr Product ID:", 2);
				cin >> id;
				P(1, "Enter the update:", 2);
				cin >> update;
				Mylist.ChangeStock(id,update);
			
				}
				break;
				//Sell Product
			case 2:
				{
					int Idc,CUSTS ,PROS;
					P(1,"Enter Customer ID",2);
					cin>>Idc;
					cout << "\n";
					//cout << Mylist.getCuC();Debuge
					for (int i = 0; i < Mylist.getCuC(); i++)
					{
						
						if (Idc == Mylist.CustSelect(i))
						{
							cout << "Name:" << Mylist.CustNameSelect(i) << "\t" << "Wallet:" << Mylist.CustWalletSelect(i) << "\n" << endl;
							int Idp;
							P(1, "Enter Product ID:", 2);
							cin >> Idp;
							for (int j = 0; j < Mylist.getPrC(); j++)
							{
								if (Idp == Mylist.ProSelect(j))
								{
									int unit;
									cout << "PName:" << Mylist.ProNameSelect(j) << "\tStock:" << Mylist.ProStockSelect(j) << "\tPrice:" << Mylist.ProPriceSelect(j) << "\n" << endl;
									cout << "How many units:\t";
									cin >> unit;
									try {
										if (unit <= Mylist.ProStockSelect(j))
										{
											int Desire = unit * Mylist.ProPriceSelect(j);
											setTextColor(Purple);
											cout << "\nTotal Cost:" << Desire << endl;
											//cout << i;
											if (Desire <= Mylist.CustWalletSelect(i))
											{
												char CH;
												setTextColor(Red);
												cout << "\nConfirm (y/n):";
												setTextColor(Yellow);
												cin >> CH;
												if (CH == 'y') 
												{
													//int Stock = Mylist.ProStockSelect(j);
													//Stock -= unit;
													unit = unit * (-1);
													Mylist.ProChangeStockSelect(j, unit);
													int Wallet = Mylist.CustWalletSelect(i);
													Wallet -= Desire;
													Mylist.CustChangeWalletSelect(i, Wallet);
													cout << "\n" << endl;
													Factor* F = new Factor;
													F->setCID(Idc);
													F->setPID(Idp);
													F->setCName(Mylist.CustNameSelect(i));
													F->setPName(Mylist.ProNameSelect(j));
													F->setUnits(unit);
													F->setCost(Desire);
													F->WriteFile();
													Mylist.AddFactor(*F);
													setTextColor(Green);
													cout << "Finished task";
													setTextColor(White);
													break;

												}
												else if (CH == 'n') 
												{
													break;
												}
												else { cout << "Error!!" << endl; }

											}
										}
										else throw invalid_argument("Exception for unit is caught");
									}
									catch (invalid_argument& e) { cerr << "\n\nStock is not enough base on input unit:" << e.what() << endl; }
								}
							}
						}
					}
					//Mylist.shopping(Idc, CUSTS,PROS);
					//cout<<"salam";
					//cin>>id
					//for (int i = 0; i < Mylist.getPrC(); i++) {
						//if(id==idproduct)product
					//}
					//Factor *PFactor = new Factor;
					//PFactor->setCID(IDC);
					///while (has money)
					///serach products
					///get num
					//PFactor->AddtoCart(...., ....);
					///money runs out
					//PFactor->getSum;
					//Mylist.addfactor;
					//delete PFactor;
				}
				break;
				//History
			case 3:
				{
				   Factor* F = new Factor;
				   string line;
				   setTextColor(Red);
				   F->FiletoProject(line);
				   delete F;
				   break;
				}
				
			//Product List
			case 4:
				{
				    //if(Mylist.)
				
				    Mylist.WriteFile();
					string line;
					setTextColor(LightBlue);
					Mylist.FiletoProject(line);
					break;

				}
			//Customers List;
			case 5:
			    {
				    Mylist.WriteC();
					string line;
					setTextColor(Green);
					Mylist.ShowC(line);
				    break;
			    }

			//Exit
			case 6:
				{
				setTextColor(Green);
					cout << "Thank You " << endl;
					Exit = 1;
				}
				break;
			}
			_getch();
			Sleep(777);
			Clear();
		}
	}
    return 0;
}

//Menu Print with Selection
void PrintMenu(string MenuList[], int MenuLength, int ptr) {
	int j = 0;
	for (int i = 0; i<MenuLength; i++) { {
			P(1, "", 0);
			if (i == ptr) {
				Clrchng(1);
			}
			P(0, MenuList[i], 0);
			Clrchng(0);
			P(0, "", 1);
		}
	}
}

//Special Print Function
//template <typename T>
void P(int a, string x, int c) {
	if (a == 1) {
		cout << " ";
	}
	setTextColor(Yellow);
	cout << x;
	setTextColor(White);
	if (c == 1) {
		cout << "\n";
	}
	else if (c == 2) {
		cout << "\n ";
	}
}

//Color Change
void Clrchng(int a) {
	if (a == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
	}
	else if (a == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
	else if (a == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x47);
	}
}

//Selecting The Desired Word
void Selection(int &p, char A, int b) {
	b--;
	switch (A) {
		//up
	case Up:
		if (p == 0) {
			p = b;
		}
		else {
			p--;
		}
		break;
		//down
	case Down:
		if (p == b) {
			p = 0;
		}
		else {
			p++;
		}
		break;
		//case
	}
}

//Header Text for Products
void HeaderPro() {
	//3-12-6-6-4-4-4
	cout << left << " " << setw(3) << "ID" << setw(12) << "Name" << setw(6) << "Price" << setw(6) << "Stock"
		<< setw(4) << "BID" << setw(4) << "CID" << setw(4) << "SID\n";
}

//Get Up/Down Key
void GetKey(){}

//Define Product Function
void DefineProduct(Product &Pin) {
	P(1, "Enter Name:", 2);
	cin >> name;
	Pin.Base::setName(name);
	P(1, "Enter Stock:", 2);
	cin >> Stock;
	while (Pin.setStock(Stock) == 0)
	{
		P(1, "Enter Stock:", 2);
		cin >> Stock;
	}
	// Change Stock
	//Pin.ChangeStock(Stock);
	P(1, "Enter Price:", 2);
	cin >> Price;
	while (Pin.setPrice(Price) == 0)
	{
		P(1, "Enter Price:", 2);
		cin >> Price;
	}
	P(1, "Enter Category ID:", 2);
	cin >> IDC;
	//SearchCat(C, IDC);
	Pin.Category::setID(IDC);
	P(1, "Enter Brand ID:", 2);
	cin >> IDB;
	//SearchBra(B, IDB);
	Pin.Brand::setID(IDB);
	P(1, "Enter Product ID:", 2);
	cin >> IDP;
	Pin.setID(IDP);
	P(1, "Enter Seller ID:", 2);
	cin >> IDS;
	Pin.setIDS(IDS);
}
//Special Search Function
template<class T>
int SearchClass(T a,int i) {
	switch (i) {
	case 1:
		for (int i = 0; i < )
			//a.T::getid();
	}
}
