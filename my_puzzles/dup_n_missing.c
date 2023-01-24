#include <stdlib.h>
#include <stdio.h>


/**
 * find_dup_n_missing - In an unsorted array of size n, find the duplicate and
 * missing values from 1 to n. Start by calculating the summation of N natural
 * numbers N(N + 1) / 2
 * Use pointer arithmetic to order our values in a new array searching for our
 * the duplicate value and subtracting each non-duplicate from our summation.
 * The remaining value will be our missing value from the array.
 * @list_pointer: pointer to the beginning of the N sized array
 * @size: the size of the N sized array
 * Return: a pointer to the Duplicate value, with the next pointer location
 * holding the Missing value. If all numbers are present returns 0, 0
*/
unsigned int *find_dup_n_missing(int *list_pointer, int size)
{
	unsigned int *home = malloc(size * sizeof(int *));
	unsigned int i, missing;
	static unsigned int dup_n_missing[2];

	/* find expected value, summation of N natural numbers */
	missing = (size * (size + 1)) / 2;

	/* organize values into malloced array, and find duplicate value */
	for (i = 0; i < size; ++i)
	{
		/* check for existing entries */
		if (*(home + *(list_pointer + i) - 1))
			dup_n_missing[0] = *(list_pointer + i);
		else
		{
			*(home + *(list_pointer + i) - 1) = *(list_pointer + i);
			/* subtract from the sumation here to find the missing value */
			missing -= *(list_pointer + i);
		}
	}
	/* setup our return value */
	dup_n_missing[1] = missing;

	free(home);
	return (&dup_n_missing[0]);
}

/**
 * main - find the duplicate and missing values in an array
 */
void main(void)
{
	unsigned int list[] = {10, 3, 1, 3, 6, 4, 5, 8, 7, 9};
	unsigned int size = sizeof(list) / sizeof(int);
	unsigned int *result;

	result = find_dup_n_missing(&list[0], size);

	printf("dup = %d, missing = %d\n", *result, *(result + 1));
}
