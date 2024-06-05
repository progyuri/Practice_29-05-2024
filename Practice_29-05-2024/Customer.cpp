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
	Basket* ptr = new Basket;
	ptr->product = product_obj;
	ptr->quantity = quantity;
	id_Basket++;
	ptr->totalprice = ptr->product->price * ptr->quantity;
	return ptr;
}

// Подсчет суммы всего заказа
float Customer::AllBasket_Price(float &total_dis) {
	float total = 0;
	Basket* temp = head;

	while (temp != nullptr) {
		total += temp->product->price * temp->product->quantity; // без учета скидки
		total_dis += temp->product->price * temp->product->quantity * ((100-(this->discount)) / 100.0); // с учетом скидки;
		temp = temp->next;
	}

	return total;
}

// Удаление позиции из корзины
bool Customer::deleteBusket(int id_Basket) {
	Basket* current = head;
	Basket* prev = head;

	while (current != nullptr) {
		if (current->id_Basket == id_Basket) {
			prev->next = current->next;
			delete current;
			return 1;
		}
		current = current->next;
		prev = current;
	}
	return 0;	
}


//Отображение позиции в корзине
void Customer::displayBasketNode(Basket* dispNode) {
	if (dispNode != nullptr)
		cout << "BasketId: " << "\033[1;31m" << dispNode->id_Basket 
		<< "; name product: " << "\033[1;31m" << dispNode->product->name 
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

Customer::Basket* Customer::searchBasketName(string p_name) {
	Basket* temp = head;
	while (temp->product->name != p_name) {
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