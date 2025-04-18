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
        fscanf(arq, "%d %d", &NM[0], &NM[1]); // Leio o tamanho de linha e colunas do txt
        fgetc(arq); // captura o \r
        fgetc(arq); // captura o \n
        int contPlayer1 = contPlayer2 = contLine = contColun = contEnter= 0;
        if(verify(NM) == 0) break; // função que verifica as condições
        int **matriz;
        constMatriz(&matriz, NM); // função que aloca a matriz multiplicando N*M

        while((charOfSecondLine = fgetc(arq)) != '\n'){
            if (charOfSecondLine == '\r' || charOfSecondLine == EOF || contColun> NM[1] || contLine > NM[0]) break; // leio proxima linha da entrada
            if(contColun > NM[1]-1){
                contLine++;
                if(contLine % 2 == 0){
                    contColun = 0;
                }else{contColun = 1;} // garanto que as peças serão posicionadas em diagonal nas linhas
            }
            contEnter++; // numero total da entrada de descrições
            if(verifyNumPecas(&contPlayer1, &contPlayer2, NM, charOfSecondLine) == 0) exit(1);
            matriz[contLine][contColun]= charOfSecondLine -'0'; // necessario para conversão do caractere para Inteiro
            contColun+= 2;
        }

        if(contEnter != (int)ceil(NM[0]*NM[1]/2)){ // problema aq
            liberarMatriz(matriz, NM);
            break;
        }

        for(int i=0; i< NM[0];i++){
            for (int j=0; j< NM[1];j++){ 
                if(matriz[i][j] == 1){ // percorre a matriz até achar uma das minhas peças
                    int vec[2] = {i,j};
                    verifyDia(&matriz, vec, &MaxPecas); // modifico diretamente o valor de MaxPecas(Numero de peças comidas)
                    if(MaxPecas > aux) aux = MaxPecas; //verifico qual peça minha consegue comer mais peças inimifas e coloco em aux
                }

            }
        }
        liberarMatriz(matriz, NM);
        printf("%d \n", MaxPecas);

    }
    fclose(arq);
    return 0;
}