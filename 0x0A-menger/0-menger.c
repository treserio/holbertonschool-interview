#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, x, y, i, j, k;

	if (level < 0)
		return;
	size = pow(3, level);
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			i = x;
			j = y;
			for (k = 0; k < level; k++, i /= 3, j /=3)
				if (i % 3 == 1 && j % 3 == 1)
					break;
			if (k == level)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
