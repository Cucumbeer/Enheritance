#include <iostream>
#include<string>
using namespace std;

#define delimiter "\n-------------------------------------------\n"

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& het_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//		Constructors

	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//		Methods:

	void print()const
	{
		cout << last_name << " " << first_name << ", " << age;
		print_year_suffix(age);
		cout << endl;
		
	}
protected:
	void print_year_suffix(unsigned int age)const
	{
		if (age <= 100)
		{
			if (age%20 >= 5 && age%20 <= 20 || age % 10 >= 5 || age % 10 == 0) cout << " лет";
			else if (age % 10 > 1 && age % 10 < 5) cout << " года";
			else cout << " год";
			cout << endl;
		}
		else cout << "Не может быть";
	}

};

class Student : public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	 double get_rating()const
	{
		return rating;
	}
	 void set_speciality(const string& speciality)
	 {
		 this->speciality = speciality;
	 }
	 void set_group(const string& group)
	 {
		 this->group = group;
	 }
	 void set_rating(double rating)
	 {
		 this->rating = rating;
	 }

	 //			Constructors:
	 Student
	 (
		 const string& last_name, const string& first_name, unsigned int age,
		 const string& speciality, const string& group, double rating
	 ):Human(last_name, first_name, age)
	 {
		 set_speciality(speciality);
		 set_group(group);
		 set_rating(rating);
		 cout << "SConstructor:\t" << this << endl;
	 }
	 ~Student()
	 {
		 cout << "SDestructor:/t" << this << endl;
	 }

	 //			Methods:
	 void print()const
	 {
		 Human::print();
		 cout << "Специальность:  " << speciality << ", Группа:  " << group << ", Успеваемость: " << rating << endl;
	 }
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//			Constructors: 
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "Tconstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "Tdestructor:\t" << this << endl;
	}
	//			Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", опыт преподавания: " << experience;
		print_year_suffix(experience);
		cout << endl;
	}
};

class Graduate :public Student
{
	string diplom_theme;
public:
	const string& get_diploma_theme()const
	{
		return diplom_theme;
	}
	void set_diplom_theme(const string& diplom_theme)
	{
		this->diplom_theme = diplom_theme;
	}

	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diplom_theme
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diplom_theme(diplom_theme);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methods: 
	void print()const
	{
		Student::print();
		cout << "Тема дипломного проекта: " << diplom_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Наследование" << endl;
	Human Andrey("Коротков", "Андрей", 18);
	Andrey.print();
	cout << delimiter << endl;
	Student student("Тупенко", "Василий", 19, "РПО", "ВБУ_011", 90);
	student.print();
	cout << delimiter << endl;
	Teacher Oleg("Ковтун", "Олег", 41, "Программирование", 12);
	Oleg.print();
	cout << delimiter << endl;

	Graduate Musk("Musk", "Elon", 54, "Carbuilding", "VBU_011", 98, "Колонизация марса");
	Musk.print();
	
}