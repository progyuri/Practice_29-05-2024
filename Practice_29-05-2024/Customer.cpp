#include <iostream>
#include "Customer.h"
#include <sstream>

Customer::~Customer() {
	Basket* current = head;
	Basket* temp = nullptr;

	while (current != nullptr) {
		temp = current;
		current = current->next;
		delete temp;
	}
}

bool Customer::AddToBasket(Product* product_obj) {
	if (product_obj == nullptr) return 0;
	
	Basket* ptr_basket = new Basket;

	if (head == nullptr) {
		head = tail = ptr_basket;
		head->next = nullptr;
	}
	else {
		// ��������� ���� �� � ������� ��� ����������� ������� ���� ����, �� ��������� ������ ���-��
		Basket* temp = head;

		while (temp!=nullptr) {
			if (temp->product->name == product_obj->name) {
				temp->product->quantity += product_obj->quantity;
				return 1;
			}
			temp = temp->next;
		}

		tail->next = ptr_basket;
		ptr_basket->next = nullptr;
		tail = ptr_basket;
	}

	
	ptr_basket->idBasket = last_idBasket;
	ptr_basket->product = product_obj;
	//ptr_basket->quantity = quantity;
	//ptr_basket->totalprice = ptr_basket->product->price * ptr_basket->quantity;
	last_idBasket++;
	return 1;
	
}


// ������� ����� ����� ������
float Customer::AllBasket_Price(float &total_dis) {
	float total = 0;
	Basket* temp = head;

	while (temp != nullptr) {
		//total += temp->product->price * temp->quantity; // ��� ����� ������
		//total_dis += temp->product->price * temp->quantity * ((100-(this->discount)) / 100.0); // � ������ ������;
		temp = temp->next;
	}

	return total;
}

// �������������� ������� � ������� �� idBasket 
bool Customer::EditBasket(int idBasket, Product* product_obj, int quantity) {
	Basket* temp = head;
	while (temp != nullptr) {
		if (temp->idBasket == idBasket) {
			temp->product = product_obj;
			//temp->quantity = quantity;
			//temp->totalprice = product_obj->price * quantity;
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

// �������� ������� �� �������
bool Customer::RemovePos_FromBasket(int id) {
	Basket* delbasket = searchIdBasket(id);
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


void Customer::RemoveAllFromBasket() {
	Basket* temp = head;
	while (temp != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
		}
	
}


//����������� ������� � �������
string Customer::displayBasketNode(Basket* dispNode) {
	
	if (dispNode != nullptr) {
		stringstream ss;
		ss << "\033[0m" << "BasketId: " << "\033[1;31m" << dispNode->idBasket
		<< "\033[0m" <<"; name product: " << "\033[1;31m" << dispNode->product->name
		<< "\033[0m" <<"; price :" << "\033[1;31m" << dispNode->product->price
//		<< "\033[0m" << "; quantity: " << "\033[1;31m" << dispNode->quantity 
		<< "\033[0m" << "; quantity: " << "\033[1;31m" << dispNode->product->quantity 
//		<< "\033[0m" << "; total price: " << "\033[1;31m" << dispNode->totalprice 
		<< "\033[0m" << endl;
		return ss.str();
	}
}

//����������� ���� ������� � ������� � �������� �������� �� ��������
string Customer::displayBasket() {
	Basket* temp = head;
	float total_dis = 0;
	string s_totalBasket;
	stringstream ss;
	ss << "\033[1;33mBasket: \033[0m";
	while (temp != nullptr) {
		s_totalBasket+= " "+ displayBasketNode(temp);
		temp = temp->next;
	}
//	ss <<"\033[1;33mBusket total:\033[0m" << "\033[1;31m" << AllBasket_Price(total_dis) << "\033[0m" << "  " 
//		 << "\033[1;33mwith diskount:\033[0m" << "\033[1;31m" << total_dis << "\033[0m" << endl;
//	s_totalBasket+=" " + ss.str()
}

Basket* Customer::searchIdBasket(int id_Basket) {
	Basket* temp = head;
	while (temp->idBasket != id_Basket) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}



// �������������� � ��������
bool Customer::Byu() {
//	Basket* obj = head;
//	if (head == nullptr) return 0;
//	else {
//		while (obj->next != nullptr) {
//			 �������� ��������� �������� ��������
//			/*
//			obj->product->name;
//			obj->quantity
//			*/
//
//			obj = obj->next;
//		}
//		 ���� ������������ �� ��������� ������ � ���������� �� ����� ������
//
//	}
	return 1;
}

string Customer::displayCustomer() {
	stringstream ss;
	ss << "Display Customer : " << endl;
	ss << "Name: " << name << endl;
	ss << "Surname: " << surname << endl;
	ss << "Email: " << email << endl;
	ss << "Phone: " << phone << endl;
	ss << "Balance: " << balance << endl;
	ss << "Discount: " << discount << "%" << endl;
	return ss.str();
}



Basket* Customer::GetBusket() {
	return head;
}

// ��������� ���������� � ���. ��������� �� ������� ��� ���������� �������
// ���� ���� ������, �� �������� ������ �����, ���� ���, �� ��������� ���-�� �������
float Customer::GetCash(float cash) {
	return (cash > balance) ?  balance : cash;
}