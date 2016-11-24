#ifndef _MAR_AVLTREE_H
#define _MAR_AVLTREE_H

class AVLTree {
public:
	//FIELDS
	int value; //The value of this tree.
	int height; //The height of this tree.

	AVLTree *left; //The left child of this tree. If this tree has no left child its value is NULL.
	AVLTree *right; //The left child of this tree. If this tree has no left child its value is NULL.


	//FUNCTIONS
	/* Constructor
	· Constructor creates an AVL tree with l as left child, r as right child and x as the root value.*/
	AVLTree (AVLTree *l, int x, AVLTree *r);
	/* Destructor
	· Destructor frees all memory of the tree recursively, effectively destroying it and its children.*/
	~AVLTree ();

	/* copy
	· Returns an independent copy of this tree. Useful, since deleting a tree will delete all references to it*/
	AVLTree* copy ();

	/* insert
	· Inserts the element x into the tree as a new node, the new tree balanced.
	· Returns the new tree, or NULL if the element x was already present in the tree.*/
	AVLTree* insert (int x);

	/* remove
	· Removess the element x from the tree and its node, returning the success of the operation.
	· Returns -1 if the element x was not found in the tree, or 0 otherwise*/
	int remove (int x);

	/* print
	· Prints the tree to console*/
	void print(int level);

private:
	int moved; //Flag to determine if this node was moved during balancing, to recalculate its height.

	/* balance
	· Balances the tree according to AVL invariants.
	· Returns the root of the new balanced tree*/
	AVLTree* balance ();

	/* maxHeight
	· Returns the height of the heighest tree*/
	int maxHeight (AVLTree *t1, AVLTree *t2);

	/* height
	· Returns the height of the tree t. If t is NULL returns 0.*/
	int getHeight (AVLTree* t);

};


#endif /* _MAR_AVLTREE_H */
