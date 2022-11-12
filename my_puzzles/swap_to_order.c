#include <stdlib.h>
#include <stdio.h>

/**
 * swap_to_order: confirm whether an ordered list can be found after swapping
 * only one value
 * Return: boolean (true if one swap == sorted list, else false)
*/
int swap_to_order(int *list, unsigned int size) {
	int i, cnt, last = *list;

	for (i = 1, cnt = 0; i < size; ++i) {
		if (last > *(list + i))
			++cnt;

		last = *(list + i);
	}

	return cnt < 2;
}

/**
 * main: setup for running swat_to_order, values of my_list can be adjusted
 * for testing.
*/
void main() {
	int my_list[] = {1, 1, 2, 1, 5, 4};
	if (swap_to_order(
		my_list,
		sizeof(my_list)/sizeof(my_list[0])
	))
		printf("swap_to_order = true\n");
	else
		printf("swap_to_order = false\n");
}
