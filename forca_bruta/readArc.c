
#include "readArc.h"

int verify(int* vector){
    int positionVector=0;
    if(vector[positionVector] == vector[positionVector+1] == 0) return 0;
    if(vector[positionVector]<3||vector[positionVector+1]<3) return 0;
    if(vector[positionVector]>20||vector[positionVector+1]>20) return 0;
    if(vector[positionVector]*vector[positionVector]>200) return 0;
    return 1;
}

void constMatriz(int ***matriz, int* vector){
     *matriz = malloc(vector[0]* sizeof(int *));
        for(int i=0; i< vector[0];i++)
            (*matriz)[i] = malloc(sizeof(int) * vector[1]);
}

int verifyNumPecas(int *player1, int *player2, int *tamanho, char C){
    int sizeMatriz = tamanho[0]*tamanho[1];
    if(C == '1') *player1++;
    if(C == '2') *player2++;

    if(sizeMatriz/4 < *player1 || sizeMatriz/4 < *player2) return 0;
    return 1;
}

void liberarMatriz(int ***matriz, int *vector){
    for (int i = 0; i < vector[0]; i++) // Liberando a Matriz
        free(*matriz[i]);
    free(*matriz);
}

void verifyDia(int ***matriz, int* vector, int *contPecas){
    int i = vector[0];
    int j = vector[1];

    if(*matriz[i++][j++] == 1 && matriz[i+2][j+2] == 0){ // diagonal superior a direita
        *contPecas++;
        verifyDia(matriz, vector, contPecas);
    }

    if(*matriz[i--][j--] == 1 && matriz[i-2][j-2] == 0){ // diagonal inferior a esquerda
        *contPecas++;
        verifyDia(matriz, vector, contPecas);
    }

    if(*matriz[i++][j--] == 1 && matriz[i+2][j-2] == 0){ // diagonal superior a esquerda
        *contPecas++;
        verifyDia(matriz, vector, contPecas);
    }

    if(*matriz[i--][j++] == 1 && matriz[i-2][j+2] == 0){ // diagonl inferior a direita
        *contPecas++;
        verifyDia(matriz, vector, contPecas);
    }
    return;
}

