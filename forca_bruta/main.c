#include <stdio.h>
#include <stdlib.h>
#include "readArc.h"
#include <math.h>

int main(){
    int NM[2], contPlayer1=0, contPlayer2=0, contLine=0, contColun=0, contEnter=0, aux=0, MaxPecas=0;
    char charOfSecondLine;
    FILE *arq = fopen("ent.txt", "r");

    if(arq == NULL){
        printf("Error, Arquivo Inexistente.\n");
        return 0;
    }


    while(1){
        if((fscanf(arq, "%d %d", &NM[0], &NM[1])) != 2) break; // Leio o tamanho de linha e colunas do txt
        fgetc(arq); // captura o \r que so tem no win
        fgetc(arq); // captura o \n
        contPlayer1 = 0;
        contPlayer2 = 0;
        contLine =0;
        contEnter=0;
        
        if(verify(NM) == 0) break;
         // função que verifica as condições
        //int **matriz;
        int matriz[NM[0]][NM[1]];
        
        //constMatriz(&matriz, NM); // função que aloca a matriz multiplicando N*M
        printf("%d %d \n", NM[0], NM[1]);
        for(int i=0; i< NM[0];i++){
            for(int j = 0; j < NM[1]; j++){
                if((i+j)%2 == 0){
                    if((fscanf(arq, "%d ", &matriz[i][j])) != 1) break;
                }else{
                    matriz[i][j] = -1;
                }
            }    
        }        
        for(int i=0; i< NM[0];i++){
            for (int j=0; j< NM[1];j++){
                printf("%d ", matriz[i][j]);
                if(matriz[i][j] == 1){ // percorre a matriz até achar uma das minhas peças
                    int vec[2] = {i,j};
                    verifyDia(matriz, vec, &MaxPecas); // modifico diretamente o valor de MaxPecas(Numero de peças comidas)
                    if(MaxPecas > aux) aux = MaxPecas; //verifico qual peça minha consegue comer mais peças inimifas e coloco em aux
                }
            }
            printf("\n");
        }
        //liberarMatriz(matriz, NM);
        //printf("%d \n", MaxPecas);
    }
    fclose(arq);
    return 0;
}