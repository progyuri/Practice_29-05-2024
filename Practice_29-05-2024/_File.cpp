#include <iostream>
#include "_File.h"

Product* _File::Open(string path, string namefile, char* type_of_access) {
	FILE* inputfile;
	Product* p = new Product[30];
	

	if (!fopen_s(&inputfile, (path + namefile).c_str(), type_of_access)) {
		int i=1;
		while (!feof(inputfile)) {
			fscanf_s(inputfile, "%s", p[i].name, sizeof(p[i].name));
			fscanf_s(inputfile, "%f", &p[i].price, sizeof(p[i].price));
			fscanf_s(inputfile, "%u", &p[i].quantity, sizeof(p[i].quantity));
			p[i].id = i;
			i++;
		}

		fclose(inputfile);
	}
	return p;
}

