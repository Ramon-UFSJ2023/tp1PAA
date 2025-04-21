#include <stdio.h>
#include <stdlib.h>
#include "readArc.h"
#include <math.h>

int main(){
    int NM[2], aux, MaxPecas;
    char charOfSecondLine;
    FILE *arq = fopen("ent.txt", "r");

    if(arq == NULL){
        printf("Error, Arquivo Inexistente.\n");
        return 0;
    }


    while(1){
        readVector(NM, arq);
        if(verify(NM) == 0) break; // Verificação das condições impostas no PDF do tp
        
        MaxPecas = 0;
        aux =0;

        int matriz[NM[0]][NM[1]];
        readMatriz(NM[0], NM[1], matriz, arq);
        for(int i=0; i< NM[0];i++){
            for (int j=0; j< NM[1];j++){
                if(matriz[i][j] == 1){ // percorre a matriz até achar uma das minhas peças
                    int vec[2] = {i,j};
                    aux = verifyDia(NM[0],NM[1], matriz, i, j); // modifico diretamente o valor de MaxPecas(Numero de peças comidas)
                    if(aux > MaxPecas) MaxPecas = aux; //verifico qual peça minha consegue comer mais peças inimifas e coloco em aux
                }
            }
        }
        printf("%d \n", MaxPecas);
    }

    fclose(arq);
    return 0;
}