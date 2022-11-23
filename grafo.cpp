#ifndef GRAFO_CPP
#define GRAFO_CPP   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "estrutura.cpp"

#define SIZE 16

float **criaVizinhos (Cidade *c, float d){
    
    // Variáveis Auxiliares
    int i, j;
    // Declarando uma matriz de ponteiros de float
    float **mat = (float**) malloc(SIZE*sizeof(float*));
    for(i = 0; i < SIZE; i++)
        mat[i] = (float*) malloc(SIZE*sizeof(float));
    

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) 
            mat[i][j] = 0;
    }
    // Testando se as cidades são vizinhas
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < i+1; j++) {
            if (i == j) {
                mat[i][j] = -1;
            }
            else { 
                // Variáveis para calcular a diferença de distância
                float dif = sqrt(pow((c[i].la-c[j].la),2)+pow((c[i].lo-c[j].lo),2));
                // Se a diferença de latitude for menor q a diferença recebida (d) a diferença de longitude será analizada
                if (dif <= d) {
                        // A posição da matriz relacionada as cidades vão reseber a diferença de distância entre elas
                        mat[i][j] = dif;
                        mat[j][i] = dif;
                    }

                else {
                    // Caso as cidades n sejam vizinhas
                    mat[i][j] = -1;
                    mat[j][i] = -1;
                }

            }
        }
    
    }
    return mat;
}

void printMaisVizinhos(float **G, Cidade *c){

    size_t tmp = 0, highest[2] = {0,0};

    for (size_t i = 0; i < SIZE; i++) { // Linhas da matriz
        for (size_t y = 0; y < SIZE; y++) // Colunas da matriz; Percorre as colunas de acordo com as linhas
            tmp = (G[i][y]>0) ? tmp+1: tmp; // Armazena na var tmp a quantidade de vizinhas presente nessa linha    

        if(tmp>highest[1]){ // Analisa se o total de vizinhaças desse iterando é maior que o da cidade atual
            highest[0] = i;
            highest[1] = tmp;
        }
            tmp*=0; // Zera a var tmp para recomeçar a contagem de vizinhaças em uma nova cidade
    }
    printf("\n\nA cidade com mais vizinhos(%lu vizinhos): %s",highest[1],c[highest[0]].cidade);
    // Por fim, dita qual foi a cidade com maior quantidade de vizinhaças de acordo com o Cidade *c passado
}

void printMaiorDistancia(Cidade *c) {
    float dif, maior = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != j){
                dif = sqrt(pow((c[i].la-c[j].la),2)+pow((c[i].lo-c[j].lo),2));
                if(dif > maior){
                    maior = dif;
                }
            }
        }
    }
    printf("\nA maior diferença é %.2f\n", maior);
}

int printSemVizinhos(float **G, Cidade *c){

    size_t tmp = 0, i, y;

    for (i = 0; i < SIZE; i++) { // Linhas da matriz
        for (y = 0; y < SIZE; y++) // Colunas da matriz; Percorre as colunas de acordo com as linhas   

        if(G[i][y]<0){ // Analisa se o total de vizinhaças desse iterando é maior que o da cidade atual
            tmp=0;
        }
        else{
            tmp=1;
            break;
        }
    if (tmp==0){
        printf("\nCidade sem vizinho encontrada: %s", c[i].cidade);
    }
    }
    
    return 0;

    // Por fim, dita qual foi a cidade com maior quantidade de vizinhaças de acordo com o Cidade *c passado
}

void printMat(float **mat){
    for (int i = 0; i < SIZE; i++) {
        printf("\n ");
        for (int j  = 0; j < SIZE; j++) {
            mat[i][j] == -1? printf("%.1f\t", mat[i][j]): printf("%.2f\t", mat[i][j]);
        }
    }
} 

#endif
