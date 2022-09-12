
#include <iostream>
#include <string>
#include <vector>
#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::string;
using NODE_TYPE = int;

int main()
{
	BinaryTree<NODE_TYPE> tree(10);
	tree << 5;
	tree << 24;
	tree << 2;
	tree << 8;
	tree.show_no_rec();
	cout << endl;
	(++tree).show_tree();

}







