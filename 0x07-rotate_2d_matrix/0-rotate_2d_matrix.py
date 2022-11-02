def rotate_2d_matrix(matrix):
    flipped = list(zip(*matrix[::-1]))
    for i in range(len(flipped)):
        matrix[i] = list(flipped[i])
