#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree.h"


int main () {
	AVLTree *tree;
	tree = new AVLTree (NULL, 8, NULL);
	tree = tree->insert (5);
	tree = tree->insert (3);


	tree->print(0);

	delete (tree);
	return 0;
}
