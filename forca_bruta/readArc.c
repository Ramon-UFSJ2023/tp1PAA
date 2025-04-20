
#include "readArc.h"

int verify(int* vector){
    int positionVector=0;
    if(vector[positionVector] == 0 && vector[positionVector+1] == 0) return 0;
    if(vector[positionVector]<3||vector[positionVector+1]<3) return 0;
    if(vector[positionVector]>20||vector[positionVector+1]>20) return 0;
    if(vector[positionVector]*vector[positionVector+1]>200) return 0;
    return 1;
}

int verifyNumPecas(int *player1, int *player2, int *tamanho, char C){
    int sizeMatriz = tamanho[0]*tamanho[1];
    if(C == '1') (*player1)++;
    if(C == '2') (*player2)++;

    if(sizeMatriz/4 < *player1 || sizeMatriz/4 < *player2) return 0;
    return 1;
}

int verifyDia(int linhas, int colunas, int matriz[linhas][colunas], int* vec){
    int i = vec[0], j = vec[1];
    int x = i, y = j;
    int melhor = 0;
    
    if(matriz[x++][y++] == 2 && (x++ < linhas && y++ < colunas)&& matriz[x+2][i+2] == 0 && (x+2 < linhas && y+2 < colunas)){ // diagonal superior a direita
        int NewVec[2] = {i+2, j+2};
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }
    if(matriz[x--][y--] == 2 && (x-- >= 0 && y-- >= 0) && matriz[x-2][y-2] == 0 && (x-2 >=0 && y-2 >=0)){ // diagonal inferior a esquerda
        int NewVec[2] = {i-2, j-2};
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }
    if(matriz[x++][y--] == 2 && (x++ < linhas && y-- >= 0) && matriz[x+2][y-2] == 0 && (x+2 < linhas && y-2 >=0)){ // diagonal superior a esquerda
        int NewVec[2] = {i+2, j-2};
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }
    if(matriz[x--][y++] == 2 && (x-- >= 0 && y++ < colunas)&& matriz[x-2][y+2] == 0 && (x+2 >=0 && y++ < colunas)){ // diagonl inferior a direita
        int NewVec[2] = {i-2, j+2};
        int captura = 1+verifyDia(linhas, colunas,matriz, vec);
        if(captura > melhor) melhor = captura;
    }
    return melhor;
}

void readVector(int vector[], FILE *arq){
    if((fscanf(arq, "%d %d", &vector[0], &vector[1])) != 2){
        printf("Leitura deu errado.\n");
        return;
    }
    fgetc(arq); // captura \r (Windowns)
    fgetc(arq);// captura \n
}

void readMatriz(int linha, int coluna, int matriz[linha][coluna], FILE *arq){
    for(int i=0; i < linha;i++){
        for(int j = 0; j < coluna; j++){
            if((i+j)%2 == 0){
                if((fscanf(arq, "%d ", &matriz[i][j])) != 1) break;
            }else{
                matriz[i][j] = -1;
            }
        }    
    }
}