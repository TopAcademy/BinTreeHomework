
#include <iostream>
#include <string>
#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::string;


int main()
{
	BinaryTree<string> tree("Nicolas");
	tree << "Biden";
	tree << "Swarzenegger";
	tree << "Obama";
	tree << "Trump";
	tree << "Putin";
	// Show tree
	tree.show_no_rec();
	cout << endl;
	tree.show_tree();

}







