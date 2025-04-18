#include <stdio.h>
#include <stdlib.h>
#include "readArc.h"
#include "math.h"

int main(){
    int NM[2], contPlayer1=0, contPlayer2=0, contLine=0, contColun=0, contEnter=0, aux=0, pecas=0;
    int MaxPecas=0;
    char charOfSecondLine;
    
    FILE *arq = fopen("ent.txt", "r");

    if(arq == NULL){
        printf("Error, Arquivo Inexistente.\n");
        return 0;
    }


    while(1){
        for(int i=0; i<2;i++)
            fscanf(arq, "%d", &NM[i]); // Leio o tamanho de linha e colunas do txt
        fgetc(arq); //pego o \n que fica ao final

        if(verify(NM) == 0) break; // função que verifica as condições
        int **matriz;
        constMatriz(&matriz, NM); // função que aloca a matriz multiplicando N*M

        while((charOfSecondLine = fgetc(arq)) != '\n'){ // leio proxima linha da entrada
            if(contColun > NM[1]-1){
                contLine++;
                if(contLine % 2 == 0){
                    contColun = 0;
                }else{contColun = 1;} // garanto que as peças serão posicionadas em diagonal nas linhas
            }
            contEnter++; // numero total da entrada de descrições
            if(verifyNumPecas(&contPlayer1, &contPlayer2, NM, charOfSecondLine) == 0) exit(1);
            matriz[contLine][contColun]= charOfSecondLine-'0'; // necessario para conversão do caractere para Inteiro
            contColun+= 2;
        }

        if(contEnter != ceil((NM[0]*NM[1]/2))){ // problema aq
            liberarMatriz(matriz, NM);
            break;
        }

        for(int i=0; i< NM[0];i++){
            for (int j=0; j< NM[1];j++){ 
                if(matriz[i][j] == 1){ // percorre a matriz até achar uma das minhas peças
                    int vec[2] = {i,j};
                    verifyDia(&matriz, vec, &pecas); // modifico diretamente o valor de pecas(Numero de peças comidas)
                    if(pecas > aux) aux = pecas; //verifico qual peça minha consegue comer mais peças inimifas e coloco em aux
                }

            }
        }
        liberarMatriz(matriz, NM);
    }
    printf("%d \n", pecas);

    fclose(arq);
    return 0;
}