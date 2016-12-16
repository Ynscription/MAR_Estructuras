#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree.h"

void testBTree ();
void testAVL();

int main () {
	testAVL();
	return 0;
}

void testBTree () {

}


void testAVL () {
	AVLTree *tree;
	tree = new AVLTree (NULL, 15, NULL);
	printTree(0, tree);
	printf("\n");
	for (int i = 6; i >= 0; i--) {
		tree = insert (i*2 + 1, tree);
		printTree(0, tree);
		printf("\n");
	}
	tree = insert (2, tree);
	printTree(0, tree);
	printf("\n");
	tree = insert (4, tree);
	printTree(0, tree);
	printf("\n");

	tree = remove (9, tree);
	printTree(0, tree);
	printf("\n");

	delete (tree);
}
