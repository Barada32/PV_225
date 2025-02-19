﻿//Academy
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

#define HUMAN_TAKE_PARAMETERS	const std::string& last_name, const std::string& first_name, int year, int month, int day
#define HUMAN_GIVE_PARAMETERS	last_name, first_name, year, month, day

class Human
{
	std::string last_name;
	std::string first_name;
	tm birth_date;	//tm - timepoint
protected:
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 10;
	static const int SPECIALTY_WIDTH = 22;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	tm get_birth_date()const
	{
		return birth_date;
	}
	unsigned int get_age()const
	{
		time_t t_today = time(NULL);	//Получаем текущие дату/время в формате Timestamp
		//cout << today << endl;
		tm* tm_today = localtime(&t_today);
		unsigned int age = tm_today->tm_year - birth_date.tm_year;
		if (tm_today->tm_mon < birth_date.tm_mon)age--;
		if (tm_today->tm_mon == birth_date.tm_mon && tm_today->tm_mday < birth_date.tm_mday)age--;
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(int year, int month, int day)
	{
		birth_date.tm_year = year - 1900;
		birth_date.tm_mon = month - 1;
		birth_date.tm_mday = day;
	}

	//				Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_birth_date(year, month, day);
		cout << "HConstructors:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructors:\t" << this << endl;
	}

	//					Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		os.width(LAST_NAME_WIDTH);
		os << left;
		os << last_name;
		os.width(FIRST_NAME_WIDTH);
		os << first_name;
		os.width(3);
		os << get_age();
		return os;
		//return os << last_name << " " << first_name << " " << get_age();
	}
	virtual std::ofstream& info(std::ofstream& ofs)const
	{
		ofs.width(LAST_NAME_WIDTH);
		ofs << left;
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << first_name;
		//ofs.width(12);
		ofs << birth_date.tm_year + 1900 << ".";
		ofs << birth_date.tm_mon << ".";
		ofs << birth_date.tm_mday << "\t";
		return ofs;
		//return os << last_name << " " << first_name << " " << get_age();
	}

	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name;
		ifs >> birth_date.tm_year; ifs.ignore();
		ifs >> birth_date.tm_mon;  ifs.ignore();
		ifs >> birth_date.tm_mday; ifs.ignore();
		birth_date.tm_year -= 1900;
		return ifs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.info(ofs);
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}

#define STUDENT_TAKE_PARAMETERS	const std::string& specialty, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS	specialty, group, rating, attendance
class Student : public Human
{
	static const int GROUP_WIDTH = 8;
	std::string specialty;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->specialty = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//						Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS)
		:Human(HUMAN_GIVE_PARAMETERS)//Вызов конструктора базового класса
	{
		set_speciality(specialty);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student
	(
		const Human& human,
		const std::string& specialty, const std::string& group, double rating, double attendance
	) :Human(human)
	{
		set_speciality(specialty);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	std::ostream& info(std::ostream& os)const override
	{
		Human::info(os);
		os << left;
		os.width(SPECIALTY_WIDTH);
		os << specialty;
		os.width(GROUP_WIDTH);
		os << group;
		os.width(GROUP_WIDTH);
		os << rating;
		os.width(GROUP_WIDTH);
		os << attendance;
		return os;
		//return Human::info(os) << " " << specialty << " " << group << " " << rating << " " << attendance;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		char buffer[SPECIALTY_WIDTH + 1] = {};
		ifs.read(buffer, SPECIALTY_WIDTH);
		//Удаляем лишние пробелы в конце строки:
		for (int i = SPECIALTY_WIDTH - 1; buffer[i] == ' '; i--)buffer[i] = 0;
		this->specialty = buffer;

		ifs >> group;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Human::info(ofs);
		ofs << left;
		ofs.width(SPECIALTY_WIDTH);
		ofs << specialty;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(GROUP_WIDTH);
		ofs << rating;
		ofs.width(GROUP_WIDTH);
		ofs << attendance;
		return ofs;
		//return Human::info(os) << " " << specialty << " " << group << " " << rating << " " << attendance;
	}
};

#define TEACHER_TAKE_PARAMETERS	const std::string& specialty, unsigned int experience
class Teacher :public Human
{
	static const int EXPERIRENCE_WIDTH = 3;
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//				Constructor:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	std::ostream& info(std::ostream& os)const
	{
		Human::info(os);
		os.width(25);
		os << specialty;
		os.width(3);
		os << experience;
		return os;
		//return Human::info(os) << " " << specialty << " " << experience << " лет.";
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		char buffer[SPECIALTY_WIDTH + 1] = {};
		ifs.read(buffer, SPECIALTY_WIDTH);
		for (int i = SPECIALTY_WIDTH - 1; buffer[i] == ' '; i--)buffer[i] = 0;
		specialty = buffer;
		ifs >> experience;
		return ifs;
	}
	std::ofstream& info(std::ofstream& os)const
	{
		Human::info(os);
		os.width(SPECIALTY_WIDTH);
		os << specialty;
		os.width(3);
		os << experience;
		return os;
		//return Human::info(os) << " " << specialty << " " << experience << " лет.";
	}

};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	std::ostream& info(std::ostream& os)const
	{
		return Student::info(os) << " " << subject;
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Student::info(ofs) << " " << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

template<typename T>void print(T group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << "\n--------------------------------------------\n";
	}
}
template<typename T>void save(T group[], const int n, const char* filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
}
Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, 0, 0, "", "", 0, 0);
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, 0, 0, "", 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, 0, 0, "", "", 0, 0, "");
}
Human** load(int& n, const char* filename)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//1) Определяем количество участников группы:
		std::string buffer;
		while (!fin.eof())
		{
			buffer.clear();
			std::getline(fin, buffer);
			if (buffer.size() == 0)continue;
			n++;
		}
		cout << "В группе " << n << " участников\n";
		//2) Выделяем память под массив:
		group = new Human*[n] {};

		//3) Возвращаемся в начало файла, чтобы загрузить строки в массив:
		cout << "Текущая позиция курсора после чтения файла:   " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Теперь курсор должен вернуться в начало файла:" << fin.tellg() << endl;

		//4) Выполняем чтение файла, и загрузку объектов в массив:
		for (int i = 0; i < n; i++)
		{
			std::string type;
			std::getline(fin, type, ':');
			if (type.empty())continue;
			group[i] = HumanFactory(type);
			fin.ignore();
			fin >> *group[i];
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	return group;
}

//#define TIME_CHECK
//#define INHERITANCE_CHECK
//#define POLYMORPHISM_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TIME_CHECK
	time_t t_today = time(NULL);	//Получаем текущие дату/время в формате Timestamp
	cout << t_today << endl;
	tm* tm_today = localtime(&t_today);
	cout << tm_today->tm_year + 1900 << "\t";
	cout << tm_today->tm_mon + 1 << "\t";
	cout << tm_today->tm_mday << "\n";
	cout << asctime(tm_today) << endl;
#endif // TIME_CHECK

#ifdef INHERITANCE_CHECK
	Human human("Тупенко", "Василий", 1990, 04, 01);
	human.info();

	//Student student("Тупенко", "Василий", 1990, 04, 01, "IT", "start", 60, 30);
	Student student(human, "IT", "start", 60, 30);
	student.info();

	Teacher teacher("Einstein", "Albert", 1879, 03, 14, "Atronomy", 120);
	teacher.info();

	Graduate graduate("Abignale", "Frank", 1920, 01, 02, "Artist", "Criminal", 98, 11, "Foregry documents");
	graduate.info();
#endif // INHERITANCE_CHECK

	//Polymorphism
#ifdef POLYMORPHISM_CHECK
			/*
----------------
Ad-Hoc polymorphism
----------------
1. Pointer to base class
	(Generalisation - Обобщение)
	Upcast - преобразование дочернего объекта в базовый тип.
2. Virtual methods;
*/

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 1990, 03,04, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 1960, 9, 20, "Chemistry", 25),
		new Graduate("Schrader", "Hank", 1970, 06,07, "Criminalistic", "WW_220", 75, 80, "How to catch Heizenberg"),
		new Student("Vercetty", "Tomas", 1970, 05, 25, "Criminalistic", "Vice", 90, 95),
		new Teacher("Diaz", "Ricardo", 1960, 03,03, "Weapons distribution", 20)
	};

	char filename[] = "group.txt";

	/*for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << "\n--------------------------------------------\n";
	}*/

	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), filename);


	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

	char sz_command[_MAX_FNAME] = "notepad ";
	strcat_s(sz_command, _MAX_FNAME, filename);
	system(sz_command);
#endif // POLYMORPHISM_CHECK

	int n = 0;
	Human** group = load(n, "group.txt");
	print(group, n);
}