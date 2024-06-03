#pragma once
#include <iostream>
//#include "\\Teacher\����� �����\��311\Tovar.h"

using namespace std;


struct Product {
	static int id;
	string name;
	float price;
	Product(string name, float price) : name{ name }, price{ price } {
		id++;
	}
};


class Customer
{
public:
	struct Basket {
		Product product(string p_name, float p_price);
		unsigned int quantity;
		float totalprice;
		Basket* next;
	}	
	*head, 
	*tail, 
	*ptr;
	
	static int �ustomerId;
	string name;
	string surname;
	string email;
	string phone;
	float discount;
	float price_order = 0; // ����� ������� ���������� (����� ��� ������� ������)

	
	
	
	// ����������� 
	Customer(string name, string surname, string email, string phone) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		discount{ 0 },
		head{ nullptr }, 
		tail{ nullptr }, 
		ptr{ nullptr } {
		�ustomerId++;
	}

	// ����������� �����������
	Customer(const Customer& other): 
		name{ other.name },
		surname{ other.surname },
		email{ other.email },
		phone{ other.phone },
		discount{ other.discount}
	{
		�ustomerId++;
		//�������� ����� insert ��� ������������ head,tail
	}

	//����������� ��������
	/*Customer(const Customer&& other) {
		name = other.name;
		surname = other.surname;
		email=other.email;
		phone = other.phone;
		discount = other.discount;
		other.name = " ";
		surname{ other.surname },
		email{ other.email },
		phone{ other.phone },
		discount{ other.discount }
	}
	*/
	
	/*
	//�������� ������������
	*/


	~Customer() {}
		

	
	
	// �������
	string getName() const {return name;}
	string getSurname() const { return surname; }
	string getEmail() const {return email;}
	string getPhone() const { return phone; }
	
	// �������
	void setName(string newName) {name = newName;}
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }
	

	/// <summary>
	/// ��������� id ���������� �� �����
	/// </summary>
	/// <returns></returns>
	int getCustomerId(string name);
	
	/// <summary>
	/// ��������� id ���������� �� email
	/// </summary>
	/// <returns></returns>
	int getCustomerId(string email);
		
		
	/// <summary>
	/// ���������� ������ � ������� (��������� ����. ������ � ���-��) 
	/// </summary>
	/// <param name="id_product">id ������������</param>
	/// <param name="quantity">���-�� �������</param>
	void AddToBasket(Basket*);

	/// <summary>
	/// ������������� ������� ������� ������������� ������ � ����������
	/// </summary>
	Basket* initBasket(string p_name, int p_quantity);

	/// <summary>
	/// ����������� �������� � �������
	/// </summary>
	/// <param name="delNode"></param>
	void displayBasketNode(Basket* dispNode);
	
	/// <summary>
	/// ����������� ���� ������� �������
	/// </summary>
	void displayBasket();

	/// <summary>
	/// ����� ������� � ������� �� �����
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Basket* searchBasketName(string);

	
	/// <summary>
	/// �������� ������� �� �������
	/// </summary>
	/// <param name="delNode"></param>
	void deleteBusket(Basket* delNode) {}


	/// <summary>
	/// �������������� ��������� ������� � �������
	/// </summary>
	/// <param name="index"></param>
	void EditBasket(int index, int id_product, int quantity);
	/// <summary>
	/// �������� �� ������� �������
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name="quantity"></param>
	void RemoveFromBasket(int index);

	/// <summary>
	/// �������� �� ������� ���� �������
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket(int index);

	/// <summary>
	/// ����� ��������� ������� � �������
	/// </summary>
	void ShowCart(int index);
	
	/// <summary>
	/// ���������� ����� ����� ������
	/// </summary>
	/// <returns></returns>
	float AllBasket_Price();

	/// <summary>
	/// ����������� ������ ��� ����������
	/// </summary>
	double Discount(int �ustomerID);

	
	/// <summary>
	/// ����� ������, ���� ������� �������� (���� ������� ������ �� ������)
	/// �� �������� ��� ������� ������
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name=""></param>
	/// <returns></returns>
	bool Byu(Basket* basket_obj);
};

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

Customer::Basket* Customer::initBasket(string p_name, int p_quantity) {
	Basket* ptr = new Basket;

	ptr ->product.name = p_name;
	ptr->quantity = p_quantity;
	ptr->totalprice= ptr->product.price*p_quantity
	return ptr;
}

// ������� ����� ����� ������
float Customer::AllBasket_Price() {
	float total = 0.0f;
	Basket* temp = head;

	while (temp != nullptr) {
		total += temp->product.price * temp->quantity;
		temp = temp->next;
	}

	return total;
}

// �������� ������� �� �������
void Customer::deleteBusket(Basket* delNode) {
	if (head == nullptr) return;
	Basket* temp, *prev;

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

//����������� ������� � �������
void Customer::displayBasketNode(Basket* dispNode) {
	if (dispNode != nullptr)
		cout << dispNode->product.name << " " << dispNode->product.quantity << " " << dispNode->totalprice << endl;
}

//����������� ���� ������� � �������
void Customer::displayBasket() {
	Basket* temp = head;
	while (temp != nullptr) {
		displayBasketNode(temp);
		temp = temp->next;
	}
}

Customer::Basket* Customer::searchBasketName(string p_name) {
	Basket* temp = head;
	while (temp->product.name != p_name) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}