#pragma once
#include "Product.h"
#include <vector>
class ProductList :
{
private:
	vector<Product>List;
public:
	ProductList();
	~ProductList();
	void AddProduct();
	void RemoveProduct();
	void EditProduct();
	void PrintProductinfo();
};

