#!/usr/bin/python3
''' Create a function def island_perimeter(grid): that returns the perimeter
    of the island described in grid:

    is a list of list of integers:
        0 represents water
        1 represents land
        Each cell is square, with a side length of 1
        Cells are connected horizontally/vertically (not diagonally).
        grid is rectangular, with its width and height not exceeding 100
    is completely surrounded by water
    There is only one island (or nothing).
    The island doesn't have “lakes” (water inside that isn't connected to the
        water surrounding the island).
'''


def island_perimeter(grid):
    ''' find the perimeter of the island in the grid
    '''
    perim = 0
    size = len(grid)

    for row_index, row in enumerate(grid):
        for col_index, isLand in enumerate(row):
            # check for first and last row
            if (not row_index or row_index == size - 1) and isLand:
                perim += 1
            # check for first and last columns
            if (not col_index or col_index == size - 1) and isLand:
                perim += 1
            # check all the adjacent land between first & last rows
            if isLand:
                if row_index > 0:
                    if not row[row_index - 1]:
                        perim += 1
                if row_index < size:
                    if not row[row_index + 1]:
                        perim += 1
                # check all the adjacent land between first & last columns
                if col_index > 0:
                    if not row[col_index - 1]:
                        perim += 1
                if col_index < size:
                    if not row[col_index + 1]:
                        perim += 1

    return perim
