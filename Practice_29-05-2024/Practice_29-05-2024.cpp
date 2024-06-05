#include <iostream>
#include "Customer.h"

using namespace std;

// структура для описания корзины покупателя


int Product::id = 0;



int main()
{
	
	

	Customer C1("John", "Doe","johndoe@example.com", "79115443121",10000);
	Product* P1 = new Product("table", 1000);
	Product* P2 = new Product("chair", 1000);
	Product* P3 = new Product("sofa", 1000);

	C1.AddToBasket(C1.initBasket(P1, 2));
	C1.AddToBasket(C1.initBasket(P2, 5));
	C1.AddToBasket(C1.initBasket(P2, 1));
	C1.discount = Сustomer5000;
	C1.displayCustomer();
	C1.displayBasket();

	C1.deleteBusket(2);
	cout << endl;
	C1.displayBasket();


	/*
	Customer C2("Elena", "Doe","johndoe@example.com", "79115443121",10000);
	C2.discount = Сustomer1000;
	C2.AddToBasket(C2.initBasket("monitor", 1, 300));

	//Customer С2(C1);
	C1.displayCustomer();
	C1.displayBasket();
	cout << endl;
	C2.displayCustomer();
	C2.displayBasket();

	//C2.displayCustomer();
	*/

}


