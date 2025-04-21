#include <stdlib.h>
#include "board.h"

Board* createBoard(int n, int m) {
    Board *t = (Board*)malloc(sizeof(Board));
    t->rows = n;
    t->cols = m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t->board[i][j] = 0;
    return t;
}

void readBoard(Board *t, FILE *file) {
    for (int i = t->rows - 1; i >= 0; i--) {
        for (int j = 0; j < t->cols; j++) {
            if ((i + j) % 2 == 0) {
                int value;
                if (fscanf(file, "%d", &value) == 1) {
                    t->board[i][j] = value;
                }
            }
        }
    }
}
