#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - Slides a line of integers to the left or right
 * @line: Pointer to the array of integers of size
 * @size: Number of elements in line
 * @direction: Direction to slide the line (either SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 if successful, 0 if not
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t x, y;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	/* Remove all zeros from array to put non-zeroes at left/start of array */
	for (x = 0, y = 0; x < size; x++)
		if (line[x] != 0)
			line[y++] = line[x];

	/* Fill in remainder of array with zeros */
	for (; y < size; y++)
		line[y] = 0;

	if (direction == SLIDE_LEFT)
	{
		for (x = 0; x < size - 1; x++)
			if (line[x] == line[x + 1])
				left_shift(line, size, x);
	}
	if (direction == SLIDE_RIGHT)
	{
		right_move(line, size);
		for (x = size - 1; x > 0; x--)
			if (line[x] == line[x - 1])
				right_shift(line, x);
	}
	return (1);
}

/**
 * left_shift - Shifts an array to the left by one
 * @line: Pointer to the array to shift
 * @size: Number of elements in array
 * @x: Index of the element to shift
 */
void left_shift(int *line, size_t size, size_t x)
{
	/* Double value of current element */
	line[x] *= 2;
	/* Shift all other elements to the left */
	for (x = x + 1; x < size - 1; x++)
		line[x] = line[x + 1];
	/* Set last element to 0 */
	line[size - 1] = 0;
}

/**
 * right_shift - Shifts an array to the right by one
 * @line: Pointer to the array to shift
 * @x: Index of the element to shift
 */
void right_shift(int *line, size_t x)
{
	/* Double value of current element */
	line[x] *= 2;
	/* Shift all other elements to the right */
	for (x = x - 1; x > 0; x--)
		line[x] = line[x - 1];
	/* Set first element to 0 */
	line[0] = 0;
}

/**
 * right_move - Moves non-zeros in array to far right, filling start with zeros
 * @line: Pointer to the array to shift
 * @size: Number of elements in array
 */
void right_move(int *line, size_t size)
{
	size_t x, y;
	int temp;

	temp = line[0];
	/* Pull all zeroes to front of array */
	for (x = size - 1, y = 0; x > 0; x--)
	{
		/* Find last non-zero value */
		if (!y)
			y = x;
		/* Move all non-zero values to the right */
		if (line[x] != 0)
			line[y--] = line[x];
	}
	line[y] = temp;
	/* Fill in start of array with zeros */
	for (; y > 0; y--)
		line[y - 1] = 0;
}
