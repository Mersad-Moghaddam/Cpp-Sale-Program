#pragma once
#include "Category.h"
//#include "Brand.h"
#include "Customer.h"
//#include "Seller.h"
#include "Product.h"
#include "Factor.h"
#include <vector>
using namespace std;
class List
{
private:
	int Procounter,Catcounter,Cuscounter,Selcounter,Brcounter,Fcounter;
	
	vector<Category>CateList;
	vector<Factor>FacList;
	vector<Brand>BraList;
	vector<Seller>SellList;
	vector<Product>ProList;
	vector<Customer>CustList;
public:
	List();
	~List();
	void WriteFile();
	void AddFactor(Factor F);
	void AddProduct(Product P);
	void RemoveProduct();
	void EditProduct();
	void ProChangeStockSelect(int i, int x);
	void CustChangeWalletSelect(int i, int x);
	void ShowC(string x);
	void WriteC();
	int ProSize();
	int CustSelect(int i);
	string CustNameSelect(int i);
	int CustWalletSelect(int i);
	int ProStockSelect(int i);
	int ProPriceSelect(int i);
	string ProNameSelect(int i);
	int ProSelect(int i);
	Product ProIndex(int i);
	Customer CusIndex(int i);
	void ShowProducts();
	void AddCategory(Category Ca);
	void AddBrand(Brand B);
	void AddCustomer(Customer Cu);
	void shopping(int x,int x1,int x2);
	void FiletoProject(string x);
	//void ShowCustomer();
	void AddSeller(Seller S);
	int getprocounter();
	void ChangeStock(int idinput,int Uinput);
	void Header();
	int getPrC();
	int getCaC();
	int getCuC();
	int getSeC();
	int getBrC();
};

