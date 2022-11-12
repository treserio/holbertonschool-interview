#include <stdlib.h>
#include <stdio.h>

/**
 * In an unsorted array of size n, find the duplicate and missing values from 1
 * to n. Use pointer arithmetic to order our values in a new array, and search
 * for our duplicate value while doing so. Then search our sorted list for the
 * missing value.
*/

void main() {
	unsigned int list[] = {10, 2, 1, 3, 6, 4, 5, 8, 7, 1};
	unsigned int size = sizeof(list)/sizeof(int);
	unsigned int *home = malloc(size * sizeof(int *));
	unsigned int *iter = home;
	unsigned int i, dup, missing;

	// organize values into malloced array, and find duplicate value
	for (i = 0; i < size; ++i) {
		// need array value - 1 to match index with value for later
		printf("expect 0, %d received\n", *(home + list[i] -1));
		// check for existing entries
		if (*(home + list[i] - 1))
			dup = list[i];
		else
			*(home + list[i] - 1) = list[i];
	}

	printf("\n");

	// now that our values are sorted we can find which one is missing
	for (i = 0; i < size; i++, iter++) {
		printf("%d=%d\n", *iter, i + 1);
		// find our missing value
		if (*iter != i + 1) {
			missing = i + 1;
			break;
		}
	}

	printf("\ndup = %d, missing = %d\n", dup, missing);
	free(home);
}
