
#include <iostream>
#include <string>
#include <vector>
#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::string;
using NODE_TYPE = string;

int main()
{
	BinaryTree<NODE_TYPE> tree("Nicolas");
	tree << "Biden";
	tree << "Swarzenegger";
	tree << "Obama";
	tree << "Trump";
	tree << "Putin";
	std::vector<NODE_TYPE> v;
	tree.make_vector(v);
	for (NODE_TYPE el : v) {
		cout << el << "; ";
	}


}







