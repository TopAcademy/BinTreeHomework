
#include <iostream>
#include "BinaryTree.h"
using std::cout;
using std::endl;



int main()
{
	BinaryTree tree(3);
	tree.add_node(1);
	tree.add_node(8);
	tree.show_no_rec();

}
