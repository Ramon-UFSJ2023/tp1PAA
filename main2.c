#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "capture.h"

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-i") != 0) {
        printf("Usage: ./tp1 -i input.txt\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int n, m;
    while (fscanf(file, "%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        Board *t = createBoard(n, m);
        readBoard(t, file);

        int max_captures = findMaxCaptures(t, 1);
        printf("%d\n", max_captures);

        free(t);
    }

    fclose(file);
    return 0;
}
