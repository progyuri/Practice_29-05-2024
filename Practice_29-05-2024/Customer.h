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



struct Basket {
private: Basket* ptr_Basket;
		 Basket* ptr_head;
		 Basket* ptr_next;
		 Basket* ptr_prev;
		 Basket* ptr_tail;
public:
	Product product;
	unsigned int quantity;
	float price_order;
	
};

class Customer
{
public:
	Basket* basket;
	static int �ustomerId;
	string name;
	string surname;
	string email;
	string phone;
	float discount;
	float all_order = 0; // ����� ������� ���������� (����� ��� ������� ������)

	
	
	
	// ����������� 
	Customer(string name, string surname, string email, string phone) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		discount{ 0 } {
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
	}

	
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
	/// ���������� ������ � ������� (�������������� ����������� ������� ������ �� ������)
	/// </summary>
	/// <param name="id_product">id ������������</param>
	/// <param name="quantity">���-�� �������</param>
	void AddToBasket(int id_product, int quantity);
	
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
	double TotalPrice();

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

int Customer::�ustomerId = 0;

