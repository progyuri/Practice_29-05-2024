#pragma once
#include <iostream>
//#include "\\Teacher\общая папка\БВ311\Tovar.h"

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
	
	static int сustomerId;
	string name;
	string surname;
	string email;
	string phone;
	float discount;
	float price_order = 0; // сумма заказов покупателя (нужно для расчета скидки)

	
	
	
	// Конструктор 
	Customer(string name, string surname, string email, string phone) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		discount{ 0 },
		head{ nullptr }, 
		tail{ nullptr }, 
		ptr{ nullptr } {
		сustomerId++;
	}

	// Конструктор копирования
	Customer(const Customer& other): 
		name{ other.name },
		surname{ other.surname },
		email{ other.email },
		phone{ other.phone },
		discount{ other.discount}
	{
		сustomerId++;
		//вставить метод insert для актуализации head,tail
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


	~Customer() {}
		

	
	
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
	/// Получение id покупателя по имени
	/// </summary>
	/// <returns></returns>
	int getCustomerId(string name);
	
	/// <summary>
	/// Получение id покупателя по email
	/// </summary>
	/// <returns></returns>
	int getCustomerId(string email);
		
		
	/// <summary>
	/// Добавление товара в корзину (указываем наим. товара и кол-во) 
	/// </summary>
	/// <param name="id_product">id наименования</param>
	/// <param name="quantity">кол-во товаров</param>
	void AddToBasket(Basket*);

	/// <summary>
	/// Инициализация позиции корзины наименованием товара и количетвом
	/// </summary>
	Basket* initBasket(string p_name, int p_quantity);

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
	void deleteBusket(Basket* delNode) {}


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
	double Discount(int сustomerID);

	
	/// <summary>
	/// метод КУПИТЬ, если покупка возможно (есть наличие товара на складе)
	/// то передаем все позиции заказа
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

// Подсчет суммы всего заказа
float Customer::AllBasket_Price() {
	float total = 0.0f;
	Basket* temp = head;

	while (temp != nullptr) {
		total += temp->product.price * temp->quantity;
		temp = temp->next;
	}

	return total;
}

// Удаление позиции из корзины
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

//Отображение позиции в корзине
void Customer::displayBasketNode(Basket* dispNode) {
	if (dispNode != nullptr)
		cout << dispNode->product.name << " " << dispNode->product.quantity << " " << dispNode->totalprice << endl;
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
	while (temp->product.name != p_name) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}