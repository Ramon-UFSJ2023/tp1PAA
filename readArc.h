#ifndef readArc
#define readArc

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int verify(int* vector);
int verifyNumPecas(int *pecasPlayer1, int *pecasPlayer2, int *tamanho, char c);
int verifyDia(int linhas, int colunas, int matriz[linhas][colunas], int i, int j);
void readVector(int vector[], FILE *arq);
void readMatriz(int linha, int coluna, int matriz[linha][coluna], FILE *arq);
int algForBru(int linha, int coluna, int matriz[linha][coluna]);
void copMat(int linha, int coluna, Board *t, int matriz[linha][coluna]);


#endif