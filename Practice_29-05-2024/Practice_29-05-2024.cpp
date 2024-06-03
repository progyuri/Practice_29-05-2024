#include <iostream>
#include "Customer.h"

using namespace std;

// структура для описания корзины покупателя



int main()
{
	
	

	Customer C1("John", "Doe","johndoe@example.com", "79115443121",10000);

	C1.AddToBasket(C1.initBasket("table", 2, 1000));
	C1.AddToBasket(C1.initBasket("chair", 5, 500));
	C1.AddToBasket(C1.initBasket("sofa", 1, 2000));
	C1.discount = Сustomer5000;
	//Customer С2(С1);
	C1.displayCustomer();
	C1.displayBasket();


	//C2.displayCustomer();
	

}


