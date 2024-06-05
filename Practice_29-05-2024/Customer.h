#pragma once
#include <iostream>
/*
#include "\\Teacher\����� �����\��311\Tovar.h"
*/
using namespace std;


struct Product {
	static int id;
	string name="";
	float price=0;
	int quantity = 0;
	Product() {
	//	id++;
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
	struct Basket {
		Product* product;
		float totalprice;
		int quantity;
		Basket* next;
		
	}
	*head, 
	*tail, 
	*ptr;
	int id_Basket = 0;
	string name;
	string surname;
	string email;
	string phone;
	DiscountType discount;
	float balance; //���-�� �����
	
	float all_price_order = 0; // ����� ������� ���������� (����� ��� ������� ������)
	
	// ����������� 
	Customer(string name, string surname, string email, string phone, float money) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		balance (money)
		{
		discount = No_diskont;
		all_price_order = 0;
		head = nullptr;
		tail = nullptr;
		ptr = nullptr;
		
		Basket* ptr_basket = new Basket;
		ptr_basket->quantity = 0;
		ptr_basket->totalprice = 0;
		ptr_basket->product = nullptr;
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
	
	// �������
	void setName(string newName) {name = newName;}
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }
	

	/// <summary>
	/// ��������� id ���������� �� �����
	/// </summary>
	/// <returns></returns>
	//int getCustomerId(string name);
	

	/// <summary>
	/// ���������� ������ � ������� (��������� ����. ������ � ���-��) 
	/// </summary>
	/// <param name="id_product">id ������������</param>
	/// <param name="quantity">���-�� �������</param>
	void AddToBasket(Basket*);

	/// <summary>
	/// ������������� ������� ������� ������������� ������ � ����������
	/// </summary>
	Basket* initBasket(Product* product_obj, int quantity);

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
	/// �������� ������� �� ������� (���������� 0 - ���� �� ������� �������(������� �� �������; 1 - ��������� ��������)
	/// </summary>
	/// <param name="delNode"></param>
	bool deleteBusket(int id_Basket);


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

};



