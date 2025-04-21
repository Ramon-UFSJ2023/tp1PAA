#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

#define MAX_DIM 20

typedef struct {
    int board[MAX_DIM][MAX_DIM];
    int rows;
    int cols;
} Board;

Board* createBoard(int n, int m);
void readBoard(Board *t, FILE *file);

#endif
