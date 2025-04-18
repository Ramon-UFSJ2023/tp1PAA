#ifndef readArc
#define readArc

#include <stdio.h>
#include <stdlib.h>

int verify(int* vector);
int verifyNumPecas(int *pecasPlayer1, int *pecasPlayer2, int *tamanho, char c);
void verifyDia(int linhas, int colunas,int matriz[linhas][colunas], int *vec, int *contPecas);

#endif