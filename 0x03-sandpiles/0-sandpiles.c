#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"


/**
 * sandpiles_sum - add two sandpiles together, and topple the result until
 * it's stable. Without
 * @grid1: 3x3 grid that must be stable at the end
 * @grid2: 3x3 grid added to grid1
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	combine_piles(grid1, grid2);

	while (unbalance_check(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1, grid2);
	}
}

/**
 * combine_piles - add two sandpiles together
 * @grid1: 3x3 grid that must be stable at the end
 * @grid2: 3x3 grid added to grid1
 */
void combine_piles(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; ++x)
		for (y = 0; y < 3; ++y)
			grid1[x][y] = grid1[x][y] + grid2[x][y];
}

/**
 * topple - add two sandpiles together
 * @grid1: 3x3 grid to topple
 * @grid2: 3x3 grid to maintain values
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int x, y, shifted;

	/* reset grid2 to zeros */
	for (x = 0; x < 3; ++x)
		for (y = 0; y < 3; ++y)
			grid2[x][y] = 0;
	/* find our shifted sand and remaining value for grid1[x][y] */
	for (x = 0; x < 3; ++x)
		for (y = 0; y < 3; ++y)
			if (grid1[x][y] > 3)
			{
				shifted = grid1[x][y] / 4;
				grid1[x][y] = grid1[x][y] % 4;
				if (x > 0)
					grid2[x - 1][y] += shifted;
				if (x < 2)
					grid2[x + 1][y] += shifted;
				if (y > 0)
					grid2[x][y - 1] += shifted;
				if (y < 2)
					grid2[x][y + 1] += shifted;
			}
	/* now combine the results */
	combine_piles(grid1, grid2);
}

/**
 * unbalance_check - confirm a grid is unbalanced
 * @grid1: a 3x3 grid to check for balance
 * Return: bool, True(1) if unbalanced else False(0)
 */
int unbalance_check(int grid1[3][3])
{
	int x, y;

	for (x = 0; x < 3; ++x)
		for (y = 0; y < 3; ++y)
			if (grid1[x][y] > 3)
				return (1);
	return (0);
}

/**
 * print_grid - Print 3x3 grid
 * had to make a 2nd copy because of static label from code provided.../sigh
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
