#include "avl_tree.h"

/* FIELDS
int value; //The value of this tree.

AVLTree *left; //The left child of this tree. If this tree has no left child its value is NULL.
AVLTree *right; //The left child of this tree. If this tree has no left child its value is NULL.
*/


// PUBLIC
/*Constructor
· Constructor creates an AVL tree with l as left child, r as right child and x as the root value.
· Calculates the height of this tree base on the heights of the children*/
AVLTree::AVLTree (AVLTree *l, int x, AVLTree *r) {
	left = l;
	right = r;
	value = x;
	height = maxHeight (l, r) + 1; //The height of this tree is that of the heighest child + 1 for this level
}
/*Destructor
· Destructor frees all memory of this tree recursively, effectively destroying it and all of its children.*/
AVLTree::~AVLTree () {
	delete (left);
	left = NULL;
	delete (right);
	right = NULL;
}

/*Copy
· Returns an independent copy of this tree. Useful, since deleting a tree will delete all references to it*/
*AVLTree copy () {
	AVLTree *l = NULL; //The left child of the new tree
	if (left != NULL) //If the left child is NULL we can not copy it
		l = left-> copy();

	AVLTree *r = NULL; //The right child of the new tree
	if (right != NULL) //If the right child is NULL we can not copy it
		r = right->copy();

	return new AVLTree (l, value, r);
}

/* insert
· Inserts the element x into the tree as a new node, returning the success of the operation.
· Returns -1 if the element x was already in the tree, or 0 otherwise.*/
int insert (int x) {
	
}






// PRIVATE
/* maxHeight
· Returns the height of the heighest tree*/
int maxHeight (AVLTree *t1, AVLTree *t2) {
	int h1 = 0, h2 = 0; //The heights of each tree
	if (t1 != NULL) //If the tree is NULL the the height is 0
		h1 = t1->height;
	if (t2 != NULL)
		h2 = t2->height;

	if (h1 > h2)
		return h1; //Returns the heighest value
	else
		return h2;
}
