#include<iostream>
using namespace std;

class Animal
{
	unsigned int speed;
	unsigned int max_speed;
public:
	virtual void sound() = 0;   //Pure Virtual Funtion(����� ����������� �����)

};

class  Cat :public Animal
{
public:
	void sound()
	{
		cout << "���" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "���" << endl;
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