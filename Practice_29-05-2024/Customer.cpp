#include <iostream>
#include "Customer.h"

Customer::~Customer() {
	Basket* current = head;
	Basket* temp = nullptr;

	while (current != nullptr) {
		temp = current;
		current = current->next;
		delete temp;
	}
}

void Customer::AddToBasket(Basket* newBasket) {
	if (head == nullptr) {
		head = tail = newBasket;
		head->next = nullptr;
	}
	else {
		tail->next = newBasket;
		newBasket->next = nullptr;
		tail = newBasket;
	}
}

Customer::Basket* Customer::initBasket(Product* product_obj, int quantity) {
	Basket* ptr_basket = new Basket;
	last_idBasket++;
	ptr_basket->idBasket = last_idBasket;
	ptr_basket->product = product_obj;
	ptr_basket->quantity = quantity;
	ptr_basket->totalprice = ptr_basket->product->price * ptr_basket->quantity;
	return ptr_basket;
}

// Подсчет суммы всего заказа
float Customer::AllBasket_Price(float &total_dis) {
	float total = 0;
	Basket* temp = head;

	while (temp != nullptr) {
		total += temp->product->price * temp->quantity; // без учета скидки
		total_dis += temp->product->price * temp->quantity * ((100-(this->discount)) / 100.0); // с учетом скидки;
		temp = temp->next;
	}

	return total;
}

// Редактирование позиции в корзине по idBasket 
bool Customer::EditBasket(int idBasket, Product* product_obj, int quantity) {
	Basket* temp = head;
	while (temp != nullptr) {
		if (temp->idBasket == idBasket) {
			temp->product = product_obj;
			temp->quantity = quantity;
			temp->totalprice = product_obj->price * quantity;
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

// Удаление позиции из корзины
bool Customer::RemovePos_FromBasket(Basket* delbasket) {
	if (head == nullptr) return 0;
	Basket* temp, * prev;
	temp = delbasket;
	prev = head;

	if (temp == prev) {
		head = head->next;
		if (tail == temp) {
			tail = tail->next;
		}
		delete temp;
	}
	else {
		while (prev->next != temp) {
			prev = prev->next;
		}
		prev->next = temp->next;
		if (tail == temp) {
			tail = prev;
		}
		delete temp;
	}
	return 0;	
}


//Отображение позиции в корзине
void Customer::displayBasketNode(Basket* dispNode) {
	if (dispNode != nullptr)
		cout << "\033[0m" << "BasketId: " << "\033[1;31m" << dispNode->idBasket
		<< "\033[0m" <<"; name product: " << "\033[1;31m" << dispNode->product->name
		<< "\033[0m" <<"; price :" << "\033[1;31m" << dispNode->product->price
		<< "\033[0m" << "; quantity: " << "\033[1;31m" << dispNode->quantity 
		<< "\033[0m" << "; total price: " << "\033[1;31m" << dispNode->totalprice 
		<< "\033[0m" << endl;
}

//Отображение всех позиций в корзине и итоговых значений по корзиине
void Customer::displayBasket() {
	Basket* temp = head;
	float total_dis = 0;
	cout << "\033[1;33mBasket: \033[0m";
	while (temp != nullptr) {
		displayBasketNode(temp);
		temp = temp->next;
	}
	cout <<"\033[1;33mBusket total:\033[0m" << "\033[1;31m" << AllBasket_Price(total_dis) << "\033[0m" << "  " 
		 << "\033[1;33mwith diskount:\033[0m" << "\033[1;31m" << total_dis << "\033[0m" << endl;
}

Customer::Basket* Customer::searchIdBasket(int id_Basket) {
	Basket* temp = head;
	while (temp->idBasket != id_Basket) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}




bool Customer::Byu() {
	Basket* obj = head;
	if (head == nullptr) return 0;
	else {
		while (obj->next != nullptr) {
			// передаем выбранные продукты продавцу
			/*
			obj->product->name;
			obj->quantity
			*/

			obj = obj->next;
		}
		// если подтверждено то уменьшаем кол-во денег у покупателя на сумму заказа

	}
	return 1;
}

void Customer::displayCustomer() {
	cout << "Display Customer : " << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Email: " << email << endl;
	cout << "Phone: " << phone << endl;
	cout << "Balance: " << balance << endl;
	cout << "Discount: " << discount << "%" << endl;
}



Customer::Basket* Customer::GetBusket() {
	Basket* temp = head;
	if (temp != nullptr) return temp;
		else return nullptr;
}