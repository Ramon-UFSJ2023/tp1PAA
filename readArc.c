
#include "readArc.h"
#include "board.h"

int verify(int* vector){
    int positionVector=0;
    if(vector[positionVector] == 0 && vector[positionVector+1] == 0) return 0;
    if(vector[positionVector]<3||vector[positionVector+1]<3) return 0;
    if(vector[positionVector]>20||vector[positionVector+1]>20) return 0;
    if(vector[positionVector]*vector[positionVector+1]>200) return 0;
    return 1;
}

 int verifyDia(int linhas, int colunas, int matriz[linhas][colunas], int i, int j){
    
    const int diagonaisSimples[4][2] = {{+1,+1},{+1,-1},{-1,+1},{-1,-1}};
    int melhorCaminho=0;

    for(int dia = 0; dia<4; dia++){
        int di = diagonaisSimples[dia][0]; // pega os valores das primeiras diagonais
        int dj = diagonaisSimples[dia][1];

        int posiIniI = i+di;// pega minha posição que é passada por I e J e coloca que a posição inimiga é a adjacente na diagonal
        int posiIniJ = j+dj; 

        int posiVagaI = i+(2*di); // faz a msm coisa explicada a cima só que posição vaga dps da peça inimiga
        int posiVagaJ = j+(2*dj);

        if((posiIniI < 0 || posiIniI >= linhas) || (posiIniJ <0 || posiIniJ >= colunas)) continue;// verificações de limite, separei em dois IFs para ficar legivel
        if((posiVagaI < 0 || posiVagaI >= linhas)||(posiVagaJ<0 || posiVagaJ>= colunas)) continue;

        if(matriz[posiIniI][posiIniJ] == 2 && matriz[posiVagaI][posiVagaJ] == 0){ // verifico se a posição atribuida a posiIni e posiVaga são as descritas na documentação 2 e 0 respectivamente
            int captura = 1 + verifyDia(linhas, colunas, matriz, posiVagaI, posiVagaJ); // adiciono uma captura e chamo a função recursiva
            if(captura > melhorCaminho) melhorCaminho = captura; // se a sequencia for melhor que a anterior vc atualiza qual é o melhor caminho a seguir
        }
    }
    return melhorCaminho;
}

int algForBru(int linha, int coluna, int matriz[linha][coluna]){
    int aux=0, max=0;
    for(int i=0; i< linha;i++){
        for(int j=0; j< coluna;j++){
            if(matriz[i][j] == 1){ // percorre a matriz até achar uma das minhas peças
                int vec[2] = {i,j};
                aux = verifyDia(linha,coluna, matriz, i, j); // modifico diretamente o valor de MaxPecas(Numero de peças comidas)
                if(aux > max) max = aux; //verifico qual peça minha consegue comer mais peças inimifas e coloco em aux
            }
        }
    }
    return max;
}

void readVector(int vector[], FILE *arq){
    if((fscanf(arq, "%d %d", &vector[0], &vector[1])) != 2){
        printf("Leitura deu errado.\n");
        return;
    } 
    int c;
    while((c = fgetc(arq)) != '\n' && c != EOF);
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
} // função feita para ler os arquivos e preencher a matriz no caso de força bruta, mas após a mesclas de codigos ela foi inutilizada, mas deixei aqui para caso necessario

void copMat(int linha, int coluna, Board *t, int matriz[linha][coluna]){
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            matriz[i][j] = t->board[i][j];
        }
    }
}