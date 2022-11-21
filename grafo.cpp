#ifndef GRAFO_CPP
#define GRAFO_CPP   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 6

float **criaVizinhos (Cidade *c, float d){
    
    // Variáveis Auxiliares
    int i, j, k = 0;
    // Declarando uma matriz de ponteiros de float
    float **mat = (float**) malloc(SIZE*sizeof(float*));
    for(i = 0; i < SIZE; i++)
        mat[i] = (float*) malloc(SIZE*sizeof(float));
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) 
            mat[i][j] = NULL;
    }


    // Testando se as cidades são vizinhas
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < i; j++) {
            if (i == j) {
                mat[i][j] = -1;
            }
            else { 
                // Variáveis para calcular a diferença de distância
                float dif = sqrt(pow(c[i].la-c[j].la,2)+pow(c[i].lo-c[j].lo,2));
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
    return mat;
}
}

void printMat(float **mat){
    for (int i = 0; i < SIZE; i++) {
        printf("\n");
        for (int j  = 0; j < SIZE; j++) {
            printf("%.2f\t", mat[i][j]);
        }
    }
} 
// printCidadeSemVizinhos(G, D);
// printTodasDistancias(G, D);
// printCidadeComMaisVizinhos(G, D);

#endif