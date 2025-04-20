
#include "readArc.h"

int verify(int* vector){
    int positionVector=0;
    if(vector[positionVector] == 0 && vector[positionVector+1] == 0) return 0;
    if(vector[positionVector]<3||vector[positionVector+1]<3) return 0;
    if(vector[positionVector]>20||vector[positionVector+1]>20) return 0;
    if(vector[positionVector]*vector[positionVector]>200) return 0;
    return 1;
}

int verifyNumPecas(int *player1, int *player2, int *tamanho, char C){
    int sizeMatriz = tamanho[0]*tamanho[1];
    if(C == '1') (*player1)++;
    if(C == '2') (*player2)++;

    if(sizeMatriz/4 < *player1 || sizeMatriz/4 < *player2) return 0;
    return 1;
}

void verifyDia(int linhas, int colunas, int matriz[linhas][colunas], int* vec, int *contPecas){
    printf("ola\n");
    int i = vec[0], j = vec[1];
    int aux1=0, aux2=0, aux3=0, aux4=0;
    
    if(matriz[i++][j++] == 2 && matriz[i+2][j+2] == 0){ // diagonal superior a direita
        (*contPecas)++;
        aux1 = *contPecas;
        vec[0] = i+2;
        vec[1] = j+2;
        verifyDia(linhas, colunas,matriz, vec, &aux1);
    }

    if(matriz[i--][j--] == 2 && matriz[i-2][j-2] == 0){ // diagonal inferior a esquerda
        (*contPecas)++;
        aux2 = *contPecas;
        vec[0] = i-2;
        vec[1] = j-2;
        verifyDia(linhas, colunas,matriz, vec, &aux2);
    }

    if(matriz[i++][j--] == 2 && matriz[i+2][j-2] == 0){ // diagonal superior a esquerda
        (*contPecas)++;
        aux3 = *contPecas;
        vec[0] = i+2;
        vec[1] = j-2;
        verifyDia(linhas, colunas,matriz, vec, &aux3);
    }

    if(matriz[i--][j++] == 2 && matriz[i-2][j+2] == 0){ // diagonl inferior a direita
        (*contPecas)++;
        aux4 = *contPecas;
        vec[0] = i-2;
        vec[1] = j+2;
        verifyDia(linhas, colunas,matriz, vec, &aux4);
    }

    if(aux1 > aux2 && aux1> aux3 && aux1 > aux4) *contPecas = aux1;
    if(aux2> aux3 && aux2 >aux4) *contPecas = aux2;
    if(aux3 > aux4){*contPecas = aux3;}
        else{ *contPecas = aux4; }
    
    return;
}

