#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree.h"

void testBTree ();
void testAVL();

int main () {
	testBTree();
	return 0;
}

void testBTree () {

}


void testAVL () {
	AVLTree *tree;
	tree = new AVLTree (NULL, 15, NULL);
	tree->print(0);
	printf("\n");
	for (int i = 6; i >= 0; i--) {
		tree = tree->insert (i*2 + 1);
		tree->print(0);
		printf("\n");
	}
	tree = tree->insert (2);
	tree->print(0);
	printf("\n");
	tree = tree->insert (4);
	tree->print(0);
	printf("\n");

	tree = tree->remove (9);
	tree->print(0);
	printf("\n");

	delete (tree);
}
