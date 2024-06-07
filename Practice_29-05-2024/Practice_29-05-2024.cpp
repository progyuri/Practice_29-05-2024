#include <iostream>
#include "Customer.h"

using namespace std;

// структура для описания корзины покупателя


int Product::id = 0;


int main()
{
	
	

	Customer C1("John", "Doe","johndoe@example.com", "79115443121",10000);
	Product* P1 = new Product("table", 1000, 5);
	Product* P2 = new Product("chair", 1000, 10);
	Product* P3 = new Product("sofa", 1500, 3);
	Product* P4 = new Product("desk", 2300);
	Product* P5 = new Product("bed", 5000);

	C1.AddToBasket(P1);
	C1.AddToBasket(P2);
	C1.AddToBasket(P3);
	C1.AddToBasket(P4);
	C1.AddToBasket(P3);
	//C1.AddToBasket(C1.initBasket(P2, 5));
	//C1.AddToBasket(C1.initBasket(P3, 1));
	C1.discount = Сustomer5000;

	C1.displayCustomer();
	C1.displayBasket();
	cout << endl;

	C1.RemoveAllFromBasket();
	C1.displayBasket();
	cout << endl;




	/*
	Customer C2("Elena", "Doe","johndoe@example.com", "79115443121",10000);
	C2.discount = Сustomer1000;
	C2.AddToBasket(C2.initBasket(P4, 1));

	//Customer С2(C1);
	C2.displayCustomer();
	C2.displayBasket();
	*/

	if (C1.GetBusket() != nullptr) C1.displayBasketNode(C1.GetBusket());
	else cout << "Basket is empty" << endl;

}


