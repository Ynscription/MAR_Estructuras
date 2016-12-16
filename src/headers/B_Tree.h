#ifndef _MAR_BTREE_H
#define _MAR_BTREE_H


template <typename T> class BTree {
public:

	T* values;			//The array of values for this node.

	BTree** children;	//The array for the children of this node.

	/*Constructor
	**Constructs the tree with n values and n+1 children slots.
	**All children slots are initialized to NULL.
	*/
	BTree (int n);

	/*Destructor
	**Destroys this tree, and all subtrees.
	**Use with caution.
	**If children must not be deleted, make sure to set the children pointers to NULL.
	*/
	~BTree ();


private:
	int size;			//The number of values in this tree.
	int filledValues;	//The number of value slots filled.

};

/*get
**Checks wether the element elem is in the tree tree.
**Returns a pointer to a copy of the element if the element is contained in the tree, NULL otherwise.
*/
template <typename T>
T get (T elem, BTree<T>* tree);

/*insert
**Inserts the element elem in the appropiate place in the tree tree.
**Ensures the tree is balanced after insertion.
**Returns a pointer to the new tree with the element inserted.
*/
template <typename T>
BTree<T>* insert (T elem, BTree<T>* tree);

/*remove
**Removes the element from the tree tree.
**Ensures the tree is balanced after deletion.
**Returns a pointer to the new tree with the element removed.
*/
template <typename T>
BTree<T>* remove (T elem, BTree<T>* tree);




#endif /* _MAR_BTREE_H */
