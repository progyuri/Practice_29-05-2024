#pragma once
#include <iostream>
//#include "\\Teacher\общая папка\БВ311\Tovar.h"

struct Product {
	static int id;
	string name = "";
	float price = 0;
	int quantity = 0;
	Product() {
		id++;
	}
	Product(string name, float price) : name{ name }, price{ price } {
		//	id++;
	}
	Product* GetProduct(int id_product);
	Product* GetProduct(string name_product);
};

using namespace std;

class _File
{
public:
	string path = "";
	string name = "";

	void Open(string path, string namefile, char* type_of_access, Product*& products);
	void Save(string path, string namefile, char* type_of_access, Product*& products);
};

