#include<iostream>
#include<Windows.h>
using namespace std;

enum Color
{
	//0xAF - \
	F - Цвет шрифта;
	CONSOLE_DEFAULT = 0x07,
	CONSOLE_RED = 0xCC,
	CONSOLE_GREEN = 0xAA,
	CONSOLE_BLUE = 0x99,

	RED		= 0x000000FF,  //Формат rgb
	GREEN	= 0x0000FF00,
	BLUE	= 0x00FF0000
};
/*
enum (Enumeration - перечисление) - это набор целочисленных именнованных констант.
Очень удобно для перечисления цветов, клавиш, вариантов кейса и т.д.
К сожалению в языке С++ перечисления могут хранить лишь целочисленные константы и не могут хранить константы других типов, даже символьные.
перечисления также являются типами данных, и переменные типа enum могут принимать только одно из перечисл. значений
*/

class Shape
{
protected:
	Color color; 
public:
	Color get_color()const
	{
		return color;
	}
	void set_color(Color color)
	{
		this->color = color;
	}
	Shape(Color color = Color::CONSOLE_DEFAULT):color(color){}
	virtual ~Shape(){}

	virtual double get_area()const = 0; //чисто виртуальная функция
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square:public Shape
{
	double side;
public:
	double get_side()const
	{
		return this->side;
	}
	void set_side(double side)
	{
		if (side <= 0)side = 1;
		this->side = side;
	}
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	~Square(){}

	double get_area()const
	{
		return side * side;
	}
	double get_perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
//#define SIMPLE_DRAW
#ifdef SIMPLE_DRAW
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Получаем обработчик окна консоли.
//Через этот обработчик можно обратитьтся к окну консоли нашей программы.
		SetConsoleTextAttribute(hConsole, get_color()); //Задаем цвет текста в выбранном окне консоли.
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT); //Возвращаем цвет на место.  
#endif // SIMPLE_DRAW

		//1) Получаем обработчик окна (Hendler to window - HWND)
		HWND hwnd = GetConsoleWindow(); 
		//2) Получаем контекст устройства:
		HDC hdc = GetDC(hwnd); //HDC - Handler to Device Context
		//3) Создаем карандаш и кисть, которыми будем рисовать
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 255,0)); //PS_SOLID - сплошная линия, 5 - толщина линии в пикселях .
		HBRUSH hBrush = CreateSolidBrush(color);
		//4) Берем созданные карандаш и кисть:
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		//4) Рисуем квадрат
		Rectangle(hdc, 300, 300, 100+side, 100+side);

		//Освобождаем ресурсы:
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);
	}
};

class Triangle :public Shape
{
public:
	Triangle(Color color) :Shape(color){}
	~Triangle(){}

	virtual double get_height()const = 0;
};
class EquilateralTriangle :public Triangle
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	double set_side(double side)
	{
		if (side <= 0) side = 1;
		this->side = side;
		return this->side;
	}
	EquilateralTriangle(double side, Color color) :Triangle(color)
	{
		set_side(side);
	}
	~EquilateralTriangle()
	{

	}
	double get_height()const
	{
		return sqrt(3) / 2 * side;
	}
	double get_area()const
	{
		return get_height() * side/2;
	}
	double get_perimeter()const
	{
		return side * 3;
	}
	void draw()const
	{
		HWND hwnd = GetConsoleWindow();
		//hwnd = FindWindow(NULL, L"Enheritance - Microsoft Visual Studio");
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, 5, color);
		HBRUSH hBrush = CreateSolidBrush(color);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		unsigned int start_x = 350;
		unsigned int start_y = 350;

		POINT points[] =
		{
			{start_x,start_y+ side},
			{start_x + side, start_y + side},
			{start_x + side / 2, start_y + side - get_height()}
		};

		Polygon(hdc, points, sizeof(points) / sizeof(POINT));


		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);
	}
};

void main()
{

	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_BLUE);
	//cout << hex << shape.get_color() << endl;

	Square square(100, Color::RED);
	cout << "Длина стороны: " << square.get_side() << endl;
	cout << "Площадь: " << square.get_area() << endl;
	cout << "Периметр: " << square.get_perimeter() << endl;
	square.draw();
	
	EquilateralTriangle e3(100, Color::GREEN);
	cout << "Длина стороны: " << e3.get_side() << endl;
	cout << "Площадь: " << e3.get_area() << endl;
	cout << "Периметр: " << e3.get_perimeter() << endl;
	e3.draw();
	cin.get();


}