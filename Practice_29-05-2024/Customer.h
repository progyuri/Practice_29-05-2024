#pragma once
#include <iostream>
/*
#include "\\Teacher\общая папка\БВ311\Tovar.h"
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
public:
	struct Basket {
		Product* product;
		float totalprice;
		int quantity;
		Basket* next;
		int idBasket = 0;
		Basket() {
			idBasket++;
		}
	}
	*head, 
	*tail, 
	*ptr;
	int last_idBasket;
	int idCount;
	string name;
	string surname;
	string email;
	string phone;
	DiscountType discount;
	float balance; //кол-во денег
	
	float all_price_order = 0; // сумма заказов покупателя (нужно для расчета скидки)
	
	// Конструктор 
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
		last_idBasket = 0;
		Basket* ptr_basket = new Basket;
		ptr_basket->quantity = 0;
		ptr_basket->totalprice = 0;
		ptr_basket->product = nullptr;
		ptr_basket->idBasket = last_idBasket;
		}

	/*
	// Конструктор копирования
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
	/// Добавление позиции в корзину (указываем указатель) 
	/// </summary>
	/// <param name="id_product">id наименования</param>
	/// <param name="quantity">кол-во товаров</param>
	void AddToBasket(Basket*);

	/// <summary>
	/// Инициализация позиции корзины указателем на товар и количетвом
	/// </summary>
	Basket* initBasket(Product* product_obj, int quantity);

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
	/// Поиск позиции в корзине по id
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Basket* searchIdBasket(int id);
	
	
	/// <summary>
	/// Удаление позиции из корзины, возвращает 0 - если не удалось удалить(позиция не найдена); 1 - произошло удаление
	/// </summary>
	/// <param name="delNode"></param>
	bool RemovePos_FromBasket(Basket*);


	/// <summary>
	/// Редактирование выбранной позиции в корзине
	/// </summary>
	/// <param name="index"></param>
	bool EditBasket(int idBasket, Product*, int quantity);
	
	/// <summary>
	/// Удаление из корзины всех позиций
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket(int index);

	/// <summary>
	/// Вычисление общей суммы заказа (возвращает общую сумму заказа, параметр total_dis - сумма с учетом скидки)
	/// </summary>
	/// <returns></returns>
	float AllBasket_Price(float& total_dis);

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

	/// <summary>
	/// Получение всей корзины, передаем ссылку на первую позицию
	/// </summary>
	/// <returns></returns>
	Basket* GetBusket();

};



