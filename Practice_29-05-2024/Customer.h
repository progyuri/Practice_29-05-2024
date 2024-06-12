#pragma once
#include <iostream>
//#include "\\Teacher\����� �����\��311\Tovar.h"

using namespace std;


struct Product {
	static int id;
	string name="";
	float price=0;
	int quantity = 0;
	Product() {
		id++;
	}
	Product(string name, float price) : name{ name }, price{ price } {
	//	id++;
	}
	Product* GetProduct(int id_product);
	Product* GetProduct(string name_product);
};


// ������ �� 0% �� 100%
	// ���� ����� ����� ������� �� 1000 ---> ������ 2%
	// ���� ����� ����� ������� �� 1000 �� 5000 �� ������ 5%
	// ���� ����� ����� ������� �� 5000 �� 10000 �� ������ 10%
	// ���� ����� ����� ������� �� 10000 �� 20000 � ����� ������ 20%
	// ���� ������ ��� VIP ��������

enum DiscountType {
	No_diskont=0,
	�ustomer1000 = 2,
	�ustomer5000 = 5,
	�ustomer10000 = 10,
	�ustomer20000 = 20,
	VIP_CUSTOMER = 30
};

class Customer
{
public:
	Basket* head;
	Basket* tail;
	int last_idBasket;
	int idCount;
	string name;
	string surname;
	string email;
	string phone;
	DiscountType discount;
	float balance; //���-�� �����
	
	float all_price_order = 0; // ����� ������� ���������� (����� ��� ������� ������)
	
	// ����������� 
	Customer(string name, string surname, string email, string phone, float balance) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		balance (balance)
		{
		discount = No_diskont;
		all_price_order = 0;
		head = nullptr;
		tail = nullptr;
		last_idBasket = 0;
		Basket* ptr_basket = new Basket;
		//ptr_basket->quantity = 0;
		//ptr_basket->totalprice = 0;
		ptr_basket->product = nullptr;
		ptr_basket->idBasket = last_idBasket;
		}

	/*
	// ����������� �����������
	Customer(const Customer& other): 
		name{ other.name },
		surname{ other.surname },
		email{ other.email },
		phone{ other.phone },
		discount{ other.discount},
		balance{ other.balance},
		all_price_order{ other.all_price_order}

	{
	}
	*/
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


	~Customer();
		

	
	
	// �������
	string getName() const {return name;}
	string getSurname() const { return surname; }
	string getEmail() const {return email;}
	string getPhone() const { return phone; }

	float getBalance() const { return balance; }
	
	// �������
	void setName(string newName) {name = newName;}
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }
	

	/// <summary>
	/// ���������� ������� � ������� (��������� ���������) 
	/// </summary>
	/// <param name="id_product">id ������������</param>
	bool AddToBasket(Product* product_obj);

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
	/// ����� ������� � ������� �� id
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Basket* searchIdBasket(int id);
	
	/// <summary>
	/// �������������� ��������� ������� � �������
	/// </summary>
	/// <param name="index"></param>
	bool EditBasket(int idBasket, Product*, int quantity);
	
	/// <summary>
	/// �������� ������� �� �������, ���������� 0 - ���� �� ������� �������(������� �� �������); 1 - ��������� ��������
	/// </summary>
	/// <param name="delNode"></param>
	bool RemovePos_FromBasket(int id);

	/// <summary>
	/// �������� �� ������� ���� �������, ���������� 0 - ���� �� ������� �������; 1 - ��������� ��������
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket();
	
	
	
	

	/// <summary>
	/// ���������� ����� ����� ������ (���������� ����� ����� ������, �������� total_dis - ����� � ������ ������)
	/// </summary>
	/// <returns></returns>
	float AllBasket_Price(float& total_dis);

	/// <summary>
	/// ����������� ������ ��� ����������
	/// </summary>
	double CalculateDiscount(string name);

	
	/// <summary>
	/// ����� ������, ���� ������� �������� (���� ������� ������ �� ������)
	/// �� �������� ��� ������� ������
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name=""></param>
	/// <returns></returns>
	bool Byu();

	/// <summary>
	/// ����������� ����������
	/// </summary>
	void displayCustomer();

	/// <summary>
	/// ��������� ���� �������, �������� ���� ������ �� ������ �������
	/// </summary>
	/// <returns></returns>
	Basket* GetBusket();

	/// <summary>
	/// �������� ������� �� � ���������� �� ������� ���. ������� ��� ������ �������  ���� �� �������, �� ������������ ������ ������
	/// </summary>
	/// <param name="cash"></param>
	/// <returns></returns>
	float GetCash(float cash);
};



