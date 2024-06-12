#include <iostream>
#include "_File.h"

void _File::Open(string path, string namefile, char* type_of_access, Product*& products) {
	FILE* inputfile;
	Product* p = new Product[30];
	

	if (!fopen_s(&inputfile, (path + namefile).c_str(), type_of_access)) {
		int i=1;
		while (!feof(inputfile)) {
			fscanf_s(inputfile, "%s", products[i].name, sizeof(products[i].name));
			fscanf_s(inputfile, "%f", &products[i].price, sizeof(products[i].price));
			fscanf_s(inputfile, "%u", &products[i].quantity, sizeof(products[i].quantity));
			p[i].id = i;
			i++;
		}

		fclose(inputfile);
	}
}

