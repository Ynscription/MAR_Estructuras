#include <stdlib.h>
#include "AVL_Tree.h"

#include <stdio.h>

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
	moved = 0;
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
AVLTree* AVLTree::copy () {
	AVLTree *l = NULL; //The left child of the new tree
	if (left != NULL) //If the left child is NULL we can not copy it
		l = left-> copy();

	AVLTree *r = NULL; //The right child of the new tree
	if (right != NULL) //If the right child is NULL we can not copy it
		r = right->copy();

	return new AVLTree (l, value, r);
}

/* insert
· Inserts the element x into the tree as a new node, the new tree balanced.
· Returns the new tree, or NULL if the element x was already present in the tree.*/
AVLTree* AVLTree::insert (int x) {
	AVLTree **tgt;
	AVLTree* ret = NULL;

	if (x > value) //If the value of x is greater than the value of this tree, then it must be inserted in the right child
		tgt = &right;
	else if (x < value)	//Otherwise the value of x is smaller than the value of this tree, so it must be inserted in the left child
		tgt = &left;

	if (*tgt == NULL) { //If the child is NULL then creates a new child with value x
		*tgt = new AVLTree (NULL, x, NULL);
		ret = this;

	}else {	//If the child is not NULL inserts the value x in the child, and then balances the child.
		*tgt = (*tgt)->insert(x);
		ret = balance();
	}
	height = maxHeight (left, right) + 1;
	return ret;
}

//TODO DELETE THIS!!!!!!!!
/* print
· Prints the tree to console*/
void AVLTree::print(int level) {
	printf("%d: {%d}, h: %d\n", level, value, height);
	if (left != NULL)
		left->print (level+1);
	if (right != NULL)
		right->print (level+1);
}





// PRIVATE
/* balance
· Balances the tree according to AVL invariants.
· Returns the root of the new balanced tree*/
AVLTree* AVLTree::balance () {
	AVLTree *root = this;

	int hl, hr;
	hl = getHeight (left);	//The height of the left child of this tree
	hr = getHeight (right);	//The height of the right child of this tree

	if (hl - hr > 1) { //If the left child is 2 nodes, or more, higher than the right child, a left rotation is required
		if (hr == getHeight(left->left)) { //LR rotation
			root = left->right;
			left->right = root->left;
			root->left =left;
			left = root->right;
			root->right = this;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->left->moved = 1;
			root->right->moved = 1;

		}
		else {	//LL rotation
			root = left;
			left = root->right;
			root->right = this;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->right->moved = 1;

		}
	}
	else if (hl - hr < -1) { //If the right child is 2 nodes, or more, higher than the left child, a right rotation is required
		if (hl == getHeight(right->right)) { //RL
			root = right->left;
			right->left = root->right;
			root->right =right;
			right = root->left;
			root->left = this;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->left->moved = 1;
			root->right->moved = 1;
		}
		else { //RR
			root = right;
			right = root->left;
			root->left = this;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->left->moved = 1;
		}
	}
	return root;

}

/* maxHeight
· Returns the height of the heighest tree*/
int AVLTree::maxHeight (AVLTree *t1, AVLTree *t2) {
	int h1, h2;
	h1 = getHeight (t1);
	h2 = getHeight (t2);

	if (h1 > h2)
		return h1; //Returns the heighest value
	else
		return h2;
}

/* height
· Returns the height of the tree t. If t is NULL returns 0.*/
int AVLTree::getHeight (AVLTree* t) {
	if (t == NULL)
		return 0;
	if (t->moved) {
		t->height = maxHeight (t->left, t->right) + 1;
		t->moved = 0;
	}
	return t->height;
}
