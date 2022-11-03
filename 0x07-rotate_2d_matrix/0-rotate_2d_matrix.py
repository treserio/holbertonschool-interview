#!/usr/bin/python3
''' rotate a 2d matrix 90 derees clockwise
'''


def rotate_2d_matrix(matrix):
    ''' this will rotate a 2d matrix in place
    '''
    matrix[:] = [list(tup) for tup in zip(*matrix[::-1])]
