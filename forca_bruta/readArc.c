
#include "readArc.h"

int verify(int* vector){
    int positionVector=0;
    if(vector[positionVector] == vector[positionVector+1] == 0) return 0;
    if(vector[positionVector]<3||vector[positionVector+1]<3) return 0;
    if(vector[positionVector]>20||vector[positionVector+1]>20) return 0;
    if(vector[positionVector]*vector[positionVector]>200) return 0;
    return 1;
}

int verifyNumPecas(int *player1, int *player2, int *tamanho, char C){
    int sizeMatriz = tamanho[0]*tamanho[1];
    if(C == '1') *player1++;
    if(C == '2') *player2++;

    if(sizeMatriz/4 < *player1 || sizeMatriz/4 < *player2) return 0;
    return 1;
}

void verifyDia(int **matriz, int* vector, int *contPecas){
    int i = vector[0];
    int j = vector[1];
    int aux1, aux2, aux3, aux4;

    if(matriz[i++][j++] == 2 && matriz[i+2][j+2] == 0){ // diagonal superior a direita
        (*contPecas)++;
        int aux1=*contPecas;
        verifyDia(matriz, vector, aux1);
    }

    if(matriz[i--][j--] == 2 && matriz[i-2][j-2] == 0){ // diagonal inferior a esquerda
        (*contPecas)++;
        int aux2=*contPecas;
        verifyDia(matriz, vector, aux2);
    }

    if(matriz[i++][j--] == 2 && matriz[i+2][j-2] == 0){ // diagonal superior a esquerda
        (*contPecas)++;
        int aux3=*contPecas;
        verifyDia(matriz, vector, aux3);
    }

    if(matriz[i--][j++] == 2 && matriz[i-2][j+2] == 0){ // diagonl inferior a direita
        (*contPecas)++;
        int aux4=*contPecas;
        verifyDia(matriz, vector, aux4);
    }
    if(aux1 > aux2 && aux1> aux3 && aux1 > aux4) *contPecas = aux1;
    if(aux2> aux3 && aux2 >aux4) *contPecas = aux2;
    if(aux3 > aux4){*contPecas = aux3;}
        else{ 
            *contPecas = aux4; 
        }
    
    return;
}

