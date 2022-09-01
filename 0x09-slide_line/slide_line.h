#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void left_shift(int *line, size_t size, size_t x);
void right_shift(int *line, size_t x);
void right_move(int *line, size_t size);

#endif
