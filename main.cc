#include <iostream>
#include "AVL-Tree.h"

int main(){
	
	AVL_Tree<int> avl;
	avl.insert(5);
	avl.insert(10);
	avl.insert(1);
	avl.insert(4);
	avl.insert(6);
	std::cout << "AVL-TREE!" << std::endl;
	avl.print();
	return 0;
}
