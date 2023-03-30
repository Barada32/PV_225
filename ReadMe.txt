https://github.com/okovtun/PV_225.git
https://www.youtube.com/watch?v=-kE_L8tb7Z8&list=PLeqyOOqxeiINREtQ3speFZN7xeXLV8gj7

Books:
https://github.com/AllonsiWho/Books.git
https://github.com/AllonsiWho/Book

https://github.com/AllonsiWho/Geometri/blob/master/ConsoleDrawing%2020150725093727_3339f8ece8c.pdf

https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

Tasks:
https://leetcode.com/
codewars.com

https://github.com/okovtun/PV_224
https://github.com/okovtun/SPD_121
https://github.com/okovtun/OOPAstrakhan

TODO:
	int minValue();	DONE
	int maxValue();	DONE
	int Count();	DONE
	int Sum();		DONE
	int Avg();		DONE
	int Depth();	//возвращает глубину дерева
	void Clear();	//Удаляет все элементы из Бинарного дерева
	void Erase();	//удаляет из дерева заданное значение

	Обеспечить вызов методов без неаобходимости пердавать в них корень дерева
		tree.print(tree.GetRoot()) => tree.print();

DONE:
1. Выяснить, почему в Дереве не появляются элементы;
2. В классе Tree написать метод print(), который выводит дерево на экран;

DONE:
От ветки 'TemplatedList2' создать ветку 'SeparatedList2' и в ней разделить класс 'List' на файлы.

DONE:
1. Написать методы insert() и erase();
2. Оптимизировать методы добавления элементов;	DONE
3. Функции print() и reverse_print() должны заработать;

DONE:
1. Проверочный код в секции HOME_WORK_1 должен заработать:
	https://github.com/okovtun/PV_225/blob/e27ac0456e5ae4235e83725eac11cf455de28748/DataContainers/ForwardList/main.cpp#L245
2. В классе ForwardList написать метод reverse(), 
   который меняет порядок следования элементов на противоположный.

DONE:
В класс ForwardList добавить следующие методы:
	void pop_front();	//удаляет элемент c начала списка	DONE
	void pop_back();	//удаляет элемент c конца списка	DONE

	void insert(int Data, int Index);	//вставляет элемент в список по заданному индексу	DONE
	void erase(int Index);				//удаляет элемент из списка по заданному индексу

	Оптимизировать методы ДОБАВЛЕНИЯ элементов, таким образом, как мы оптимизировали push_front() DONE

	Деструктор дожен очищать список перед удалением		DONE

	CopyMethods;
	MoveMethods;

DONE:
Реализовать иерархию геометрических фигур: квадрат, треугольник, прямоугольник, круг и т.д.
Для каждой фигуры необходимо вывести ее первичные свойства, такие как радиус, длина стороны, и т.д.
и вторичные свойства такие как площадь, периметр, так же каждую фигуру нужно нарисовать.
Для рисования фигуры нужно задать начальные координаты, по которым фигура будет выводится.
	https://learn.microsoft.com/en-us/windows/win32/api/_gdi/
	https://learn.microsoft.com/en-us/windows/win32/gdi/windows-gdi
	https://learn.microsoft.com/en-us/windows/win32/gdi/about-filled-shapes
	https://learn.microsoft.com/en-us/windows/win32/gdi/about-ellipses
	https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-ellipse

DONE:
1. Сохранить групу в файл;
2. Загрузить группу из файла;

TODO:
1. Есть файл 201 RAW.txt, из этого файла нужно создать другой файл 201 ready.txt, 
   в котором столбик с IP-адресом и MAC-адресом будут поменяны местами;
	https://github.com/okovtun/PV_225/blob/master/Inheritance/Files/NetworkTask/201%20RAW.txt
2. Из файла 201 RAW.txt создать файл формата 201.dhcpd
	https://github.com/okovtun/PV_225/blob/master/Inheritance/Files/NetworkTask/201.dhcpd

DONE:
Добить вывод на экран в проекте Academy.

DONE:
Перегрузить констуктор класса Student таким образом, 
чтобы студента можно было создать из уже существующего человека.

DONE:
Создать ветку FractionSeparation и в этой ветке разделить класс Fraction на файлы;

DONE:
Реализовать класс Matrix, описывающий матрицу, и написать все необходимые методы для этого класса.

DONE:
Проверочный код должен заработать:
	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;	//Конкатенация (слияние) строк
	cout << str3 << endl;

TOREAD:https://legacy.cplusplus.com/doc/tutorial/classes2/

DONE:
Проверочный код должен заработать:
1. DONE https://github.com/okovtun/PV_225/blob/b48f47bdc82c4e7a324e8b90a0ff37822259298c/IntroductionToOOP/Fraction/main.cpp#L349;
2. https://github.com/okovtun/PV_225/blob/b48f47bdc82c4e7a324e8b90a0ff37822259298c/IntroductionToOOP/Fraction/main.cpp#L355

TODO:
ВЫУЧИТЬ ТЕОРИЮ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
В классе Fraction реализовать:
	1. Конструкторы и вывод на экран;	DONE
		5;		//double a = 5;
		1/2;
		2(3/4);
	2. Написать методы:
		Fraction& to_improper();	//целую часть интегрирует в числитель
		Fraction& to_proper();		//выделяет целую часть из числителя
		Fraction& reduce();			//сокращает дробь https://www.webmath.ru/poleznoe/formules_12_7.php
	3. Перегрузить арифметические операторы: +, -, *, /;		DONE
	4. Перегрузить присваивания:	=, +=, -=, *=, /=;			DONE
	5. Перегрузить операторы ++/--;
	6. Перегрузить операторы сравнения: ==, !=, >, <, >=, <=;	DONE
	7. Перегрузить оператор ввода с клавиатуры;

DONE:
1. В классе Point написать get/set-методы;	DONE
2. В классе Point написать метод ??? distance(???), который возвращает расстояние до указанной точки;
3. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками;