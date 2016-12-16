#ifndef _MAR_AVLTREE_H
#define _MAR_AVLTREE_H

//TODO Make AVLTree for templates

class AVLTree {
public:
	//FIELDS
	int value; //The value of this tree.
	int height; //The height of this tree.
	int moved; //Flag to determine if this node was moved during balancing, to recalculate its height.

	AVLTree *left; //The left child of this tree. If this tree has no left child its value is NULL.
	AVLTree *right; //The left child of this tree. If this tree has no left child its value is NULL.


	//FUNCTIONS
	/* Constructor
	· Constructor creates an AVL tree with l as left child, r as right child and x as the root value.*/
	AVLTree (AVLTree* l, int x, AVLTree* r);
	/* Destructor
	· Destructor frees all memory of the tree recursively, effectively destroying it and its children.*/
	~AVLTree ();

};


//BASIC FUNCTIONS
/* insert
· Inserts the element x into the tree as a new node, the new tree balanced.
· Returns the new tree.*/
AVLTree* insert (int x, AVLTree* tree);

/* remove
· Removess the element x from the tree and its node, returning the success of the operation.
· Returns the new tree.*/
AVLTree* remove (int x, AVLTree* tree);

//AUXILIAR FUNCTIONS
/* removeMin
· Finds the best node to move to the root, wich was just deleted.
· Returns the root of the new tree.*/
int removeMin(AVLTree* t, int lr);

/* balance
· Balances the tree according to AVL invariants.
· Returns the root of the new balanced tree*/
AVLTree* balance (AVLTree* tree);

//USEFUL FUNCTIONS
/* copy
· Returns an independent copy of the tree tree. Useful, since deleting a tree will delete all references to it*/
AVLTree* copy (AVLTree* tree);

/* maxHeight
· Returns the height of the heighest tree*/
int maxHeight (AVLTree* t1, AVLTree* t2);

/* height
· Returns the height of the tree t. If t is NULL returns 0.*/
int getHeight (AVLTree* t);

/* print
· Prints the tree to console*/
void printTree(int level, AVLTree* tree);


#endif /* _MAR_AVLTREE_H */
