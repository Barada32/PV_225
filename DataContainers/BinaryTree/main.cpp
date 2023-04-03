#include<iostream>
#include<ctime>
#include<chrono>
using namespace std;

#define delimiter "\n-----------------------------------------------\n"

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	int minValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int Count(Element* Root)
	{
		if (Root == nullptr)return 0;
		else return Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	int Sum(Element* Root)
	{
		if (Root == nullptr)return 0;
		else return Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	double Avg()
	{
		return (double)Sum(Root) / Count(Root);
	}

	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

class UniqueTree :public Tree
{
public:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n = 100000;
	cout << typeid(std::chrono::steady_clock::now()).name() << endl;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	///////////////////////		Time:		///////////////////////
	std::chrono::steady_clock::time_point ch_start = std::chrono::steady_clock::now();
	clock_t c_start = clock();
	static time_t t_start = time(NULL);
	//-------------------------------------------------------------
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	///////////////////////		Time:		///////////////////////
	std::chrono::steady_clock::time_point ch_end = std::chrono::steady_clock::now();
	std::chrono::duration<double> delta = ch_end - ch_start;
	clock_t c_end = clock();
	static time_t t_end = time(NULL);
	cout << delimiter << endl;
	cout << "elapsed time chrono:  " << delta.count() << endl;
	cout << "elapsed time time():  " << t_end - t_start << endl;
	cout << "elapsed time clock(): " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
	cout << delimiter << endl;
	//-------------------------------------------------------------
	//tree.print(tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;
	system("PAUSE");
	//////////////////////////////////////////////////////////////////////////////////////////
	ch_start = std::chrono::steady_clock::now();
	t_start = time(NULL);
	c_start = clock();
	cout << "Количество элементов дерева: " << tree.Count(tree.getRoot()) << endl;
	ch_end = std::chrono::steady_clock::now();
	t_end = time(NULL);
	c_end = clock();
	cout << delimiter << endl;
	delta = ch_end - ch_start;
	cout << "elapsed time chrono:  " << delta.count() << endl;
	cout << "elapsed time time():  " << t_end - t_start << endl;
	cout << "elapsed time clock(): " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
	cout << delimiter << endl;
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////////////////////
	ch_start = std::chrono::steady_clock::now();
	t_start = time(NULL);
	c_start = clock();
	cout << "Сумма элементов дерева: " << tree.Sum(tree.getRoot()) << endl;
	ch_end = std::chrono::steady_clock::now();
	t_end = time(NULL);
	c_end = clock();
	cout << delimiter << endl;
	delta = ch_end - ch_start;
	cout << "elapsed time chrono:  " << delta.count() << endl;
	cout << "elapsed time time():  " << t_end - t_start << endl;
	cout << "elapsed time clock(): " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
	cout << delimiter << endl;
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
	cout << "Сумма элементов дерева: " << tree.Sum(tree.getRoot()) << endl;
	cout << "Среднее-арифметическое элементов дерева: " << tree.Avg() << endl;
	//system("PAUSE");
	//cout << "Время подсчета: " << difftime(t_end, t_start) << " c" << endl;
	//cout << "Время подсчета: " << t_end - t_start << " c" << endl;
	//cout << start << endl;
	//cout << end << endl;
	//cout << "Время подсчета: " << double(end - start) / CLOCKS_PER_SEC << endl;

	UniqueTree tree2;
	for (int i = 0; i < n; i++)
	{
		tree2.insert(rand() % 100, tree2.getRoot());
	}
	/*while (tree2.Count(tree2.getRoot()) < n)
	{
		tree2.insert(rand() % 100, tree2.getRoot());
	}*/
	//tree2.print(tree2.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree2.minValue(tree2.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree2.maxValue(tree2.getRoot()) << endl;
	cout << "Количество элементов дерева: " << tree2.Count(tree2.getRoot()) << endl;
	cout << "Сумма элементов дерева: " << tree2.Sum(tree2.getRoot()) << endl;
	cout << "Среднее-арифметическое элементов дерева: " << tree2.Avg() << endl;
}