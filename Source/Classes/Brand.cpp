#include "stdafx.h"
#include "Brand.h"


Brand::Brand()
{
	IDB = 0;
}


Brand::~Brand()
{
}
void Brand::setID(int IDBinput) {
	IDB = IDBinput;
}
int Brand::getID() {
	return IDB;
}
void  Brand::WriteFile()
{
	ofstream OutBR;
	OutBR.open("Bra.txt", ios::app);
	OutBR << getName() << ' ' << getID() << "\n";
	OutBR.close();
}