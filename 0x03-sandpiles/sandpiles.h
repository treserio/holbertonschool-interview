#ifndef SANDPILES_H
#define SANDPILES_H

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void combine_piles(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3], int grid2[3][3]);
int balance_check(int grid1[3][3]);
static void print_grid(int grid[3][3]);

#endif
