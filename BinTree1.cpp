
#include <iostream>
#include "BinaryTree.h"
using std::cout;
using std::endl;



int main()
{
	BinaryTree tree(3);
	tree.add_node(1);
	tree.add_node(2);
	tree.add_node(45);
	tree.add_node(8);
	tree.add_node(0);
	tree.add_node(7);
	tree.add_node(12);
	tree.add_node(9);
	tree.add_node(5);
	tree.add_node(6);
	// Show tree
	tree.show_no_rec();
	cout << endl;
	tree.show_tree();

}
