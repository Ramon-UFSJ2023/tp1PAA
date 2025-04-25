#include <stdio.h>
#include <stdlib.h>
#include "readArc.h"
#include "board.h"
#include "capture.h"
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

int main(){
    int NM[2], FBruta, Euristico;
    char charOfSecondLine;
    FILE *arq = fopen("ent.txt", "r");

    struct timeval time_start1, time_end1, time_start2, time_end2;

    if(arq == NULL){
        printf("Error, Arquivo Inexistente.\n");
        return 0;
    }
    int choose=0;
    printf("Escolha 1 para algoritmo Euristico\nEscolha 2 para algoritmo ForçaBruta\n");
    scanf("%d", &choose);

    while(1){

        readVector(NM, arq); // leitura da primeira linha feita pelo Ramon
        if(verify(NM) == 0) break; // Verificação das condições impostas no PDF do tp

        Board *t = createBoard(NM[0], NM[1]); // função criada pela Julia
        readBoard(t, arq); // utilizei a leitura da linha subsequente a da definição do tabuleiro feita pela julia
        int matriz[NM[0]][NM[1]];
        copMat(NM[0],NM[1], t, matriz); // função feita para copiar a matriz e poder utiliza nos dois algoritmos

        switch (choose){

        case 1:
            printf("Tempo com algoritmo Euristico: \n");
            if (gettimeofday(&time_start1, NULL) != 0) {
                perror("gettimeofday");
                exit(EXIT_FAILURE);
            }

            int max_captures = findMaxCaptures(t, 1); //Algoritmo Euristico
            printf("%d\n", max_captures);

            if (gettimeofday(&time_end1, NULL) != 0) {
                perror("gettimeofday");
                exit(EXIT_FAILURE);
            }
            long sec1=time_end1.tv_sec-time_start1.tv_sec;
            break;

        case 2:
            printf("Tempo com algoritmo Força Bruta: \n");
            if (gettimeofday(&time_start2, NULL) != 0) {
                perror("gettimeofday");
                exit(EXIT_FAILURE);
            }

            int maxPecas = algForBru(NM[0], NM[1], matriz); //algoritmo força bruta
            printf("%d \n", maxPecas);

            if (gettimeofday(&time_end2, NULL) != 0) {
                perror("gettimeofday");
                exit(EXIT_FAILURE);
            }
            long sec2=time_end2.tv_sec-time_start2.tv_sec;
            break;

        default:
            break;
        }

    }
    fclose(arq);
    return 0;
}