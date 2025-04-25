#include <stdbool.h>
#include "capture.h"

bool isValidPosition(Board *t, int row, int col) {
    return row >=0 && row <t->rows && col >=0 && col <t->cols;
}

void dfsCapture(Board *t, int row, int col, bool captured[MAX_DIM][MAX_DIM], int *max_captures, int current_captures, int player) {
    int opponent =(player == 1) ? 2 : 1;
    int directions[4][2] ={{-1,-1}, {-1, 1}, {1,-1}, {1, 1}};
    bool can_capture=false;

    for (int d=0; d<4; d++) {
        int mid_row = row + directions[d][0];
        int mid_col = col +directions[d][1];
        int dest_row = row + 2 *directions[d][0];
        int dest_col = col+ 2 * directions[d][1];

        if (isValidPosition(t, mid_row, mid_col) &&
            isValidPosition(t, dest_row, dest_col) &&
            t->board[mid_row][mid_col] == opponent &&
            !captured[mid_row][mid_col] &&
            t->board[dest_row][dest_col] == 0) {
            can_capture = true;
            captured[mid_row][mid_col]= true;
            t->board[dest_row][dest_col] = player;
            t->board[row][col] =0;

            dfsCapture(t, dest_row, dest_col, captured,max_captures, current_captures+1, player);

            t->board[row][col]= player;
            t->board[dest_row][dest_col]= 0;
            captured[mid_row][mid_col] = false;
        }
    }

    if (!can_capture && current_captures >(*max_captures)) {
        *max_captures = current_captures;
    }
}

int findMaxCaptures(Board *t, int player) {
    int max_captures = 0;
    for (int i =0; i <t->rows;i++) {
        for (int j= 0; j <t->cols;j++) {
            if (t->board[i][j] == player) {
                bool captured[MAX_DIM][MAX_DIM] = {false};
                dfsCapture(t, i, j, captured, &max_captures, 0, player);
            }
        }
    }
    return max_captures;
}
