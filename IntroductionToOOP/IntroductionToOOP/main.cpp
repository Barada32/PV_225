//IntroductionToOOP
#include<iostream>
using namespace std;

//				����� - ��� ��� ������!!!
//				��������� - ��� ��� ������!!!

class Point	//�������� ��������� ��� �����, �� ������� ����� ��� ������.
{			//������ � ��������� ��� �������� ����������������� (����������) ������ ������.
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

	//					Methods:
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;		//���������� ���������� 'a' ���� 'int'
	Point A;	//���������� ���������� 'A' ���� 'Point'
				//���������� ������� 'A' ��������� 'Point'
				//�������� ���������� 'A' ��������� 'Point'
	//������� ����� �������� ������������ ������ ��� ���������.
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

	cout << "���������� �� ����� A �� ����� B: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << "���������� ����� ������� A � B:   " << distance(A, B) << endl;
	cout << "���������� ����� ������� B � A:   " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
}

/*
--------------------------------------------
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
--------------------------------------------
*/

/*
--------------------------------------------
1. ������������ (Encapsulation);
������������ �������:
private:	�������� ����, �������� ������ ������ ������
public:		�������� ����, ��������� �� ������ ����� ���������
protected:	���������� ����, �������� ������ ������ ������ � ��� �������� �������
			(���� ����������� ������� ������������ ������ ��� ������������)
get/set-������ - ������������ ������ ����� � �������� ���������� � ������.
get (�����, ��������) - ��������� �������� (�����) �������� ���������� 
						(��������� ������ �� ������ � ���������� ������ ������)
set (���������, ������, ����������) - ��������� ������ �������� ���������� � ������
						(��������� ������ � ���������� ������ ������ �� ������).

2. ������������ (Inheritance);
3. �����������  (Polymorphism);
--------------------------------------------
*/

/*
--------------------------------------------
1. Constructor - ��� �����, ������� ������� ������
2. ~Destructor - ��� �����, ������� ���������� ������, �� ��������� ��� ������� �����
3. Assingment operator
--------------------------------------------
*/