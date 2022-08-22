#pragma once
#include <iostream>
#include <string>
using namespace std;

void P(int a, string b, int c) {
	if (a == 1) {
		cout << " ";
	}
	cout << b;
	if (c == 1) {
		cout << "\n";
	}
	else if (c == 2) {
		cout << "\n ";
	}
}
