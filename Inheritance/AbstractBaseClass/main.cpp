#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;	//��� ����� ����������� �����, 
	//� ��������� ��� ����� 'Vehicle' �������� �����������
};

class GroundVehicle :public Vehicle {};

class Bulldozer :public GroundVehicle
{
public:
	void move()
	{
		cout << "����� ��� ������ �� ���������� ����" << endl;
	}
};
class Car :public GroundVehicle{};
class SportCar :public Car
{
public:
	void move()
	{
		cout << "����� �� ������� �������� �� ��������� ������" << endl;
	}
};
class Jeep :public Car
{
public:
	void move()
	{
		cout << "����� ��� ������" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	
	//Vehicle v;
	//GroundVehicle gv;
	Bulldozer bull;
	bull.move();

	SportCar bmw;
	bmw.move();

	Jeep jeep;
	jeep.move();
}