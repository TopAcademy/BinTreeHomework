
#include <iostream>
#include <string>
#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::string;


int main()
{
	BinaryTree<int> tree(3);
	tree << 1;
	tree << 2;
	tree << 8;
	tree << 0;
	tree << 7;
	tree << 12;
	tree << 45;
	tree << 9;
	tree << 5;
	tree << 6;
	/*
	tree.add_node(1);
	tree.add_node(2);
	tree.add_node(8);
	tree.add_node(0);
	tree.add_node(7);
	tree.add_node(12);
	tree.add_node(45);
	tree.add_node(9);
	tree.add_node(5);
	tree.add_node(6);
	*/
	// Show tree
	tree.show_no_rec();
	cout << endl;
	tree.show_tree();

}







