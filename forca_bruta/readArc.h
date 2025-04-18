#ifndef readArc
#define readArc

#include <stdio.h>
#include <stdlib.h>

int verify(int* vector);
void constMatriz(int ***matriz, int* vector);
int verifyNumPecas(int *pecasPlayer1, int *pecasPlayer2, int *tamanho, char c);
void liberarMatriz(int ***matriz, int* vector);
void verifyDia(int ***matriz, int* vector, int *contPeca);

#endif