def rotate_2d_matrix(matrix):
    matrix[:] = [list(tup) for tup in zip(*matrix[::-1])]
