#include <stdio.h>
#include <stdlib.h>
#include "readArc.h"
#include "board.h"
#include "capture.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <math.h>

int main(){
    int NM[2];
    FILE *arq = fopen("ent.txt", "r");
    FILE *arqOut = fopen("saida.txt", "w");

    struct timeval time_start, time_end;
    struct rusage ru_start, ru_end;


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
            getrusage(RUSAGE_SELF, &ru_start);
            gettimeofday(&time_start, NULL);
            
            int max_captures = findMaxCaptures(t, 1); //Algoritmo Euristico
            fprintf(arqOut, "%d\n", max_captures);

            getrusage(RUSAGE_SELF, &ru_end);
            gettimeofday(&time_end, NULL);

            printf("Tempo de Usuario: %ld\n", (ru_end.ru_utime.tv_sec-ru_start.ru_utime.tv_sec));
            printf("Tempo de Sistema: %ld\n", (time_end.ru_stime.tv_sec-time_start.ru_stime.tv_sec));

            break;

        case 2:
            getrusage(RUSAGE_SELF, &ru_start);
            gettimeofday(&time_start, NULL);

            int maxPecas = algForBru(NM[0], NM[1], matriz); //algoritmo força bruta
            fprintf(arqOut, "%d\n", max_captures);

            getrusage(RUSAGE_SELF, &ru_end);
            gettimeofday(&time_end, NULL);
            
            printf("Tempo de Usuario: %ld\n", (ru_end.ru_utime.tv_sec-ru_start.ru_utime.tv_sec));
            printf("Tempo de Sistema: %ld\n", (time_end.ru_stime.tv_sec-time_start.ru_stime.tv_sec));

            break;

        default:
            break;
        }
        printf("Tempo com algoritmo Euristico: \n");
        printf("")

        printf("Tempo com algoritmo Força Bruta: \n");



    }

    fclose(arq);
    return 0;
}