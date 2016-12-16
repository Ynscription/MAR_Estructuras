#include <stdlib.h>
#include "B_Tree.h"



/*Constructor
**Constructs the tree with n values and n+1 children slots.
**All children slots are initialized to NULL.
*/
template <typename T>
BTree<T>::BTree (int n) {
	size = n;
	filledValues = 0;

	//Initialize values array.
	values = malloc (sizeof (T) * n);

	//Initialize children array. There is n+1 spots beetween n elements.
	children = malloc (sizeof (BTree*) * (n + 1));
	for (int i = 0; i <= size; i++) {
		//Initialize pointers to NULL
		children [i] = NULL;
	}

}

/*Destructor
**Destroys this tree, and all subtrees.
**Use with caution.
**If children must not be deleted, make sure to set the children pointers to NULL.
*/
template <typename T>
BTree<T>::~BTree () {
	//Free values array.
	free (values);
	values = NULL;

	//Free each BTree in the children array (the not NULL ones).
	for (int i = 0; i <= size; i++) {
		if (children != NULL) {
			free (children [i]);
			children [i] = NULL;
		}
	}

	//Free the children array
	free (children);

}

/*insert
**Inserts the element elem in the appropiate place in the tree tree.
**Ensures the tree is balanced after insertion.
**Returns a pointer to the new tree with the element inserted.
*/
template <typename T>
BTree<T>* insert (T elem, BTree<T>* tree) {


}
