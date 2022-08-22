#include "stdafx.h"
#include "Category.h"


Category::Category()
{
	IDC = 0;
}
Category::~Category()
{
}
void Category::setID(int IDCinput) {
	IDC = IDCinput;
}
int Category::getID() {
	return IDC;
}

void Category::WriteFile()
{
	ofstream OutCat;
	OutCat.open("Cat.txt", ios::app);
	OutCat << getName() << ' ' <<getID()<<"\n";
	OutCat.close();
}
