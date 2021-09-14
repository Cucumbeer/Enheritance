#include<iostream>
using namespace std;

class Animal
{
	unsigned int speed;
	unsigned int max_speed;
public:
	virtual void sound() = 0;   //Pure Virtual Funtion(Чисто Виртуальный метод)

};

class  Cat :public Animal
{
public:
	void sound()
	{
		cout << "МЯУ" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "ГАВ" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	//Animal animal;		//Can not instantiate abstract class
	Cat cat;
	cat.sound();
	Dog dog;
	dog.sound();
}