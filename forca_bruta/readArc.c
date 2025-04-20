
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

int verifyDias(int linhas, int colunas, int matriz[linhas][colunas], int* vec){
    printf("ola\n");
    int i = vec[0], j = vec[1];
    int x = i, y = j;
    int melhor = 0;
    
    if(matriz[x++][y++] == 2 && matriz[x+2][i+2] == 0){ // diagonal superior a direita
        vec[0] = i+2;
        vec[1] = j+2;
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }else if(matriz[x--][y--] == 2 && matriz[x-2][y-2] == 0){ // diagonal inferior a esquerda
        vec[0] = i-2;
        vec[1] = j-2;
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }else if(matriz[x++][y--] == 2 && matriz[x+2][y-2] == 0){ // diagonal superior a esquerda

        vec[0] = i+2;
        vec[1] = j-2;
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }else if(matriz[x--][y++] == 2 && matriz[x-2][y+2] == 0){ // diagonl inferior a direita
        vec[0] = i-2;
        vec[1] = j+2;
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }
    return melhor;
}
