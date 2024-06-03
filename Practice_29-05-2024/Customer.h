#pragma once
#include <iostream>
//#include "\\Teacher\общая папка\БВ311\Tovar.h"

using namespace std;


struct Product {
	static int id;
	string name="";
	float price=0;
	Product() {
		id++;
	}
	Product(string name, float price) : name{ name }, price{ price } {
		id++;
	}
	Product(int id_product) {
		//находим продукт по id
		id++;
	}
};
int id = 0;


// скидка от 0% до 100%
	// если общая сумма заказов до 1000 ---> скидка 2%
	// если общая сумма заказов от 1000 до 5000 то скидка 5%
	// если общая сумма заказов от 5000 до 10000 то скидка 10%
	// если общая сумма заказов от 10000 до 20000 и более скидка 20%
	// спец скидка для VIP клиентов

enum DiscountType {
	No_diskont=0,
	Сustomer1000 = 2,
	Сustomer5000 = 5,
	Сustomer10000 = 10,
	Сustomer20000 = 20,
	VIP_CUSTOMER = 30
};

class Customer
{
private: int сustomerId;
public:
	struct Basket {	
		Product* product;
		unsigned int quantity;
		float totalprice;
		Basket* next;
	}	
	*head, 
	*tail, 
	*ptr;
	
	static int count;
	string name;
	string surname;
	string email;
	string phone;
	DiscountType discount;
	float money; //кол-во денег
	
	float all_price_order = 0; // сумма заказов покупателя (нужно для расчета скидки)
	
	
	
	
	
	// Конструктор 
	Customer(string name, string surname, string email, string phone, float money) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		money (money)
		{
		discount = No_diskont;
		all_price_order = 0;
		head = nullptr;
		tail = nullptr;
		ptr = nullptr;
		count++;
		сustomerId=count;
		Basket* ptr_basket = new Basket;
		ptr_basket->quantity = 0;
		ptr_basket->next = nullptr;
		ptr_basket->totalprice = 0;
		ptr_basket->product = nullptr;
		}

	// Конструктор копирования
	Customer(const Customer& other): 
		name{ other.name },
		surname{ other.surname },
		email{ other.email },
		phone{ other.phone },
		discount{ other.discount},
		money{ other.money},
		all_price_order{ other.all_price_order},
		head{ other.head },
		tail{ other.tail },
		ptr{ other.ptr }

	{
		сustomerId++;
	}

	//Конструктор переноса
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
	//оператор присваивания
	*/


	~Customer();
		

	
	
	// Геттеры
	int getCustomerId() { return сustomerId;}
	string getName() const {return name;}
	string getSurname() const { return surname; }
	string getEmail() const {return email;}
	string getPhone() const { return phone; }
	
	// Сеттеры
	void setName(string newName) {name = newName;}
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }
	

	/// <summary>
	/// Получение id покупателя по имени
	/// </summary>
	/// <returns></returns>
	//int getCustomerId(string name);
	

	/// <summary>
	/// Добавление товара в корзину (указываем наим. товара и кол-во) 
	/// </summary>
	/// <param name="id_product">id наименования</param>
	/// <param name="quantity">кол-во товаров</param>
	void AddToBasket(Basket*);

	/// <summary>
	/// Инициализация позиции корзины наименованием товара и количетвом
	/// </summary>
	Basket* initBasket(string p_name, int p_quantity, float p_price);

	/// <summary>
	/// Отображение позииции в корзине
	/// </summary>
	/// <param name="delNode"></param>
	void displayBasketNode(Basket* dispNode);
	
	/// <summary>
	/// Отображение всех позиций корзины
	/// </summary>
	void displayBasket();

	/// <summary>
	/// Поиск позиции в корзине по имени
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Basket* searchBasketName(string);

	
	/// <summary>
	/// Удаление позиции из корзины
	/// </summary>
	/// <param name="delNode"></param>
	void deleteBusket(Basket* delNode);


	/// <summary>
	/// Редактирование выбранной позиции в корзине
	/// </summary>
	/// <param name="index"></param>
	void EditBasket(int index, int id_product, int quantity);
	/// <summary>
	/// Удаление из корзины позиции
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name="quantity"></param>
	void RemoveFromBasket(int index);

	/// <summary>
	/// Удаление из корзины всех позиций
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket(int index);

	/// <summary>
	/// Показ выбранной позиции в корзине
	/// </summary>
	void ShowCart(int index);
	
	/// <summary>
	/// Вычисление общей суммы заказа
	/// </summary>
	/// <returns></returns>
	float AllBasket_Price();

	/// <summary>
	/// Определение скидки для покупателя
	/// </summary>
	double CalculateDiscount(string name);

	
	/// <summary>
	/// метод КУПИТЬ, если покупка возможно (есть наличие товара на складе)
	/// то передаем все позиции заказа
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name=""></param>
	/// <returns></returns>
	bool Byu();

	/// <summary>
	/// Отображение покупателя
	/// </summary>
	void displayCustomer();

};

// Устанавливаем значение счетчику = 0
int Customer::count = 0;


