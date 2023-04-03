#include <iostream>
#include <string>


template <typename T>
class BinaryTree
{
	class Branch
	{
	private:
		static void addBranch(Branch *&branch, T newData)
		{
			if (!branch) {
				branch = new Branch(newData);
			}
			else {
				branch->add(newData);
			}
		}
	public:
		T data;
		Branch *pLeft, *pRight;

		explicit Branch(T data, Branch *pLeft = nullptr, Branch *pRight = nullptr)
		{
			this->data = data;
			this->pLeft = pLeft;
			this->pRight = pRight;
		}

		void add(T newData)
		{
			if (this->dataMoreThan(newData)) {
				Branch::addBranch(this->pLeft, newData);
			}
			else {
				Branch::addBranch(this->pRight, newData);
			}
		}

		bool dataMoreThan(T newData)
		{
			return this->data > newData;
		}

		bool isLeaf()
		{
			return !this->pLeft && !this->pRight;
		}
	};

	Branch *root = nullptr;
public:
	void insert(T data)
	{
		if (!this->root) {
			this->root = new Branch(data);
		}
		else {
			this->root->add(data);
		}
	}

	void print()
	{
		BinaryTree::printBranch(this->root);
	}

	static void printBranch(Branch *branch, int depth = 0)
	{
		const int TAB_SIZE = 6;
		const std::string tabOffset(depth * TAB_SIZE, ' ');

		if (branch->pLeft) {
			printBranch(branch->pLeft, depth + 1);
		}
		else if (!branch->isLeaf()) {
			std::cout << tabOffset << std::string(TAB_SIZE, ' ') << "NULL" << std::endl;
		}

		std::cout << tabOffset << branch->data;

		if (branch->isLeaf()) {
			std::cout << " Leaf";
		}

		std::cout << std::endl;

		if (branch->pRight) {
			printBranch(branch->pRight, depth + 1);
		}
		else if (!branch->isLeaf()) {
			std::cout << tabOffset << std::string(TAB_SIZE, ' ') << "NULL" << std::endl;
		}
	}
};

typedef BinaryTree<int> IntBinTree;


int main() {
	IntBinTree tree;

	tree.insert(3);
	tree.insert(6);
	tree.insert(5);
	tree.insert(8);
	tree.insert(10);

	tree.insert(-2);
	tree.insert(-4);
	tree.insert(0);

	tree.print();

	return 0;
}