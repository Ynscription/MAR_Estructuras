#include <stdlib.h>
#include "AVL_Tree.h"

#include <stdio.h>

/* FIELDS
int value; //The value of this tree.

AVLTree *left; //The left child of this tree. If this tree has no left child its value is NULL.
AVLTree *right; //The left child of this tree. If this tree has no left child its value is NULL.
*/


// PUBLIC=======================================================================================
/*Constructor
· Constructor creates an AVL tree with l as left child, r as right child and x as the root value.
· Calculates the height of this tree base on the heights of the children*/
AVLTree::AVLTree (AVLTree* l, int x, AVLTree* r) {
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

//BASIC FUNCTIONS=======================================================================================
/* insert
· Inserts the element x into the tree as a new node, the new tree balanced.
· Returns the new tree.*/
AVLTree* insert (int x, AVLTree* tree) {
	AVLTree** tgt = NULL;
	AVLTree* ret = NULL;

	if (x > tree->value) //If the value of x is greater than the value of this tree, then it must be inserted in the right child
		tgt = &(tree->right);
	else if (x < tree->value)	//Otherwise the value of x is smaller than the value of this tree, so it must be inserted in the left child
		tgt = &(tree->left);
	else		//If the vallue of x is equal to the value of this tree, we return this tree with no changes.
		return tree;

	if (*tgt == NULL) { //If the child is NULL then creates a new child with value x
		*tgt = new AVLTree (NULL, x, NULL);
		ret = tree;

	}else {	//If the child is not NULL inserts the value x in the child, and then balances the tree.
		*tgt = insert(x, *tgt);
		ret = balance(tree);
	}
	tree->height = maxHeight (tree->left, tree->right) + 1;
	return ret;
}

/* remove
· Removes the element x from the tree and its node, returning the success of the operation.
· Returns -1 if the element x was not found in the tree, or 0 otherwise*/
AVLTree* remove (int x, AVLTree* tree) {
	AVLTree* ret = tree;
	AVLTree** tgt;
	*tgt = NULL;
	if (x < tree->value)
		tgt = &(tree->left);
	else if (x > tree->value)
		tgt = &(tree->right);
	else {

		AVLTree* target;
		if (getHeight(tree->left) >= getHeight (tree->right)) {
			tree->value = removeMin (tree->left, 0);
		}else {
			tree->value = removeMin (tree->right, 1);
		}
		tree->moved = true;
		ret = balance(tree);

		return ret;
	}

	if (*tgt  != NULL){
		*tgt = remove(x, *tgt);
		ret = balance(tree	);
	}
	return ret;
}


//AUXILIAR FUNCTIONS=======================================================================================
/* balance
· Balances the tree according to AVL invariants.
· Returns the root of the new balanced tree*/
AVLTree* balance (AVLTree* tree) {
	AVLTree* root = tree;
	int hl, hr;
	hl = getHeight (tree->left);	//The height of the left child of this tree
	hr = getHeight (tree->right);	//The height of the right child of this tree

	if (hl - hr > 1) { //If the left child is 2 nodes, or more, higher than the right child, a left rotation is required
		if (hr == getHeight(tree->left->left)) { //LR rotation
			root = tree->left->right;
			tree->left->right = root->left;
			root->left = tree->left;
			tree->left = root->right;
			root->right = tree;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->left->moved = 1;
			root->right->moved = 1;

		}
		else {	//LL rotation
			root = tree->left;
			tree->left = root->right;
			root->right = tree;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->right->moved = 1;

		}
	}
	else if (hl - hr < -1) { //If the right child is 2 nodes, or more, higher than the left child, a right rotation is required
		if (hl == getHeight(tree->right->right)) { //RL
			root = tree->right->left;
			tree->right->left = root->right;
			root->right =tree->right;
			tree->right = root->left;
			root->left = tree;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->left->moved = 1;
			root->right->moved = 1;
		}
		else { //RR
			root = tree->right;
			tree->right = root->left;
			root->left = tree;

			//Set the moved flags to 1 in order to update the height.
			root->moved = 1;
			root->left->moved = 1;
		}
	}
	return root;

}

/* removeMin
· Finds the best value to ovewrite the root, and deletes the node.
· Returns the value.*/
int removeMin(AVLTree* t, int lr) {
	AVLTree* target = NULL;
	int ret;

	if (!lr) { //This is the left tree, so we have to descend to the right
		target = t->right;
	}else {
		target = t->left;
	}

	if (target == NULL) {		//If this tree does not have a target child, then this is the best value, return this value, and delete this tree.
		ret = t->value;
		delete (t);
	}else {
		ret = removeMin(target, lr);
		t->moved = true;
	}

	return ret;
}


//USEFUL FUNCTIONS=======================================================================================
/*Copy
· Returns an independent copy of this tree. Useful, since deleting a tree will delete all references to it*/
AVLTree* copy (AVLTree* tree) {
	AVLTree* l = NULL; //The left child of the new tree
	if (tree->left != NULL) //If the left child is NULL we can not copy it
		l = copy(tree->left);

	AVLTree *r = NULL; //The right child of the new tree
	if (tree->right != NULL) //If the right child is NULL we can not copy it
		r = copy(tree->right);

	return new AVLTree (l, tree->value, r);
}

/* maxHeight
· Returns the height of the heighest tree*/
int maxHeight (AVLTree* t1, AVLTree* t2) {
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
int getHeight (AVLTree* t) {
	if (t == NULL)
		return 0;
	if (t->moved) {
		t->height = maxHeight (t->left, t->right) + 1;
		t->moved = 0;
	}
	return t->height;
}

//TODO DELETE THIS!!!!!!!! (Or make it properly with a queue, whatever suits.)
/* print
· Prints the tree to console*/
void printTree(int level, AVLTree* tree) {
	printf("%d: {%d}, h: %d\n", level, tree->value, tree->height);
	if (tree->left != NULL)
		printTree (level+1, tree->left);
	if (tree->right != NULL)
		printTree (level+1, tree->right);
}
