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
	· Inserts the element x into the tree as a new node, returning the success of the operation.
	· Returns -1 if the element x was already in the tree, or 0 otherwise.*/
	int insert (int x, AVLTree *root);

	/* remove
	· Removess the element x from the tree and its node, returning the success of the operation.
	· Returns -1 if the element x was not found in the tree, or 0 otherwise*/
	int remove (int x);

	/* print
	· Prints the tree to console*/
	void print(int level);

private:
	/* maxHeight
	· Returns the height of the heighest tree*/
	int maxHeight (AVLTree *t1, AVLTree *t2);


	/* balance
	· Balances the tree according to AVL invariants*/
	void balance (AVLTree *root);


};


#endif /* _MAR_AVLTREE_H */
