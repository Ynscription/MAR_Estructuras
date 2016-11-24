#include <stdio.h>
#include <stdlib.h>


int main () {
	int *a, *b;
	a = (int*) malloc(sizeof(int));
	b = (int*) malloc(sizeof(int));
	printf("Initial state: %d,%d\n", *a, *b);
	*a = 3;
	printf("A = 3: %d,%d\n", *a, *b);
	free (b);
	b = NULL;
	b = a;
	printf("B = A: %d,%d\n", *a, *b);
	*b = 5;
	printf("B = 5: %d,%d\n", *a, *b);

	return 0;
}
