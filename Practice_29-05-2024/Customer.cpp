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

Customer::Basket* Customer::initBasket(string p_name, int p_quantity, float p_price) {
	Basket* ptr = new Basket;
	ptr->product = new Product();
	ptr->product->name = p_name;
	ptr->product->price = p_price;
	ptr->quantity = p_quantity;
	ptr->totalprice = ptr->product->price * p_quantity;
	return ptr;
}

// Подсчет суммы всего заказа
float Customer::AllBasket_Price() {
	float total = 0;
	Basket* temp = head;

	while (temp != nullptr) {
		total += temp->product->price * temp->quantity; // без учета скидки
		//total += temp->product->price * temp->quantity * (this->discount / 100); // с учетом скидки;
		temp = temp->next;
	}

	return total;
}

// Удаление позиции из корзины
void Customer::deleteBusket(Basket* delNode) {
	if (head == nullptr) return;
	Basket* temp, * prev;

	temp = delNode;
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

}

//Отображение позиции в корзине
void Customer::displayBasketNode(Basket* dispNode) {
	if (dispNode != nullptr)
		cout << dispNode->product->name << " " << dispNode->quantity << " " << dispNode->totalprice << endl;
}

//Отображение всех позиций в корзине
void Customer::displayBasket() {
	Basket* temp = head;
	while (temp != nullptr) {
		displayBasketNode(temp);
		temp = temp->next;
	}
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
	cout << "Customer ID: " << getCustomerId() << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Email: " << email << endl;
	cout << "Phone: " << phone << endl;
	cout << "Money: " << money << endl;
	cout << "Discount: " << discount << "%" << endl;
}