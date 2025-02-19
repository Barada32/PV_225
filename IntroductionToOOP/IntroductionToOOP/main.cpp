﻿//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------\n"

//				КЛАСС - ЭТО ТИП ДАННЫХ!!!
//				СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!

class Point	//Создавая структуру или класс, мы создаем новый тип данных.
{			//Классы и структуры еще называют пользовательскими (составными) типами данных.
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//					Constructors:
	/*Point()
	{
		x = y = 0;
		//RAII - Resource Aqulisation - Is Initialisation
		//		(Выделение ресурсов - значит инициализация)
		cout << "DefConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//					Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	//					Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

//					Comparison operators:
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!=(const Point& left, const Point& right)
{
	return left.get_x() != right.get_x() || left.get_y() != right.get_y();
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}
std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj(x, y);
	return is;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
				//Объявление объекта 'A' структуры 'Point'
				//Создание экземпляра 'A' структуры 'Point'
	//Объекты часто называют экземплярами класса или структуры.
	//A.x = 2;
	//A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	//p  - Pointer
	//pA - Pointer to 'A'
	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F  
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(2, 3);
	B.print();

	Point C = 4;//Single-Argument constructor
	C.print();

	Point D = C;//Copy constructor
	//Deep copy - побитовое копирование, побайтовое копирование, поэлементное копирование.
	//Shallow copy - поверхностное копирование, т.е., копирование адреса памяти, вместо содержимого памяти.
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment
	Point A(2, 3);
	A.print();
	Point B = A;	//CopyConstructor
	B.print();
	Point C;
	C = B;			//Assignment operator
	C.print();
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2, 3) - явный вызов конструктора, и этот конструктор создает временный безымянный объект.
	//Временные безымянные объекты существую в пределах одного выражения.
	cout << delimiter << endl;
	/*cout << "Begin" << endl;
	Point(2, 3);
	cout << "End" << endl;*/
#endif // ASSIGNMENT_CHECK_2

	/*int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B + A + B;
	C.print();
	cout << delimiter << endl;
	C++;
	cout << delimiter << endl;
	C.print();*/

	/*Point A(2, 3);
	Point B(4, 5);
	cout << (A != B) << endl;*/

	Point A(2, 3);
	A.print();
	
	/*A.set_x(12);
	A.set_y(13);*/
	A(22, 33);
	//A.print();
	cout << A << endl;

	cout << "Введите координаты точки: "; 
	
	cin >> A;
	
	cout << A << endl;
}

/*
--------------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
--------------------------------------------
*/

/*
--------------------------------------------
1. Инкапсуляция (Encapsulation);
Модификаторы доступа:
private:	закрытые поля, доступны только внутри класса
public:		открытые поля, доступные из любого места программы
protected:	защищенные поля, доступны внутри нашего класса и его дочерних классов
			(этот модификатор доступа используется только при наследовании)
get/set-методы - обеспечивают доступ извне к закрытым переменным в классе.
get (взять, получить) - позволяют получить (взять) значение переменной
						(открывают доступ на чтение к переменным членам класса)
set (назначить, задать, установить) - позволяют задать значение переменной в классе
						(открывают доступ к переменным членам класса на запись).

2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
--------------------------------------------
*/

/*
--------------------------------------------
1. Constructor - это метод, который создает объект
2. ~Destructor - это метод, который уничтожает объект, по истечении его времени жизни
3. Assingment operator
--------------------------------------------
*/

/*
--------------------------------------------
1. Перегрузить можно только существующие операторы,
   невозможно создавать новые операторы.
   Например:
	+  - перегружается;
	++ - перегружается;
	*  - перегружается;
	** - НЕ перегружается;
2. НЕ все существующие операторы можно перегрузить.
   НЕ перегружаются:
	?: - Conditional ternary
	:: - Scope operator (Оператор разрешения видимости)
	.  - Point operator (Оператор прямого доступа)
	.* - Pointer to member selection
	#  - Preprocessor directive
	## - Preprocessor concatenation
3. Переопределить поведение операторов над встроенными типами НЕВОЗМОЖНО!
4. Перегруженные операторы сохраняют приоритет.
--------------------------------------------
*/