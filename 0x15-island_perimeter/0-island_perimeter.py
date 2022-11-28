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
    last_row = len(grid) - 1
    last_column = len(grid[0]) - 1
    # print(last_row, last_column)

    for row_index, row in enumerate(grid):
        for col_index, isLand in enumerate(row):
            # print('r:', row_index, 'c:', col_index, 'land?:', isLand)
            # increase perimeter if we're on the first or last row or column,
            # otherwise check previous / next for land
            if isLand:
                if not row_index or not grid[row_index - 1][col_index]:
                    perim += 1
                if row_index == last_row or not grid[row_index + 1][col_index]:
                    perim += 1
                # check all the adjacent land between first & last column
                if not col_index or not row[col_index - 1]:
                        perim += 1
                if col_index == last_column or not row[col_index + 1]:
                        perim += 1
            # print('perim =', perim)

    return perim
