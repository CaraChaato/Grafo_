#ifndef GRAFO_CPP
#define GRAFO_CPP   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 167

float **criaVizinhos (Cidade *c, float d){
    
    // Variáveis Auxiliares
    int i, j, k = 0;
    // Declarando uma matriz de ponteiros de float
    float **mat = (float**) malloc(SIZE*sizeof(float*));
    for(i = 0; i < SIZE; i++){
        mat[i] = (float*) malloc(SIZE*sizeof(float));
    }
    
    // Testando se as cidades são vizinhas
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < i; j++) {
            if (i == j) {
                mat[i][j] = -1;
            }
            else { 
                // Variáveis para calcular a diferença de distância
                float difla = c[i].la - c[j].la;
                float diflo = c[i].lo - c[j].lo;
                // Se a diferença de latitude for menor q a diferença recebida (d) a diferença de longitude será analizada
                if (difla <= d) {
                    // Se a diferença de longitude for menor q a diferença recebida (d) ela será considera vizinha 
                    if(diflo <= d){
                        // A posição da matriz relacionada as cidades vão reseber a diferença de distância entre elas
                        mat[i][j] = (c[i].la - c[j].la) + (c[i].lo - c[j].lo);
                        mat[j][i] = (c[i].la - c[j].la) + (c[i].lo - c[j].lo);
                    }
                }
                else{
                    // Caso as cidades n sejam vizinhas
                    mat[i][j] = -1;
                    mat[j][i] = -1;
                }

            }
        }
    }

    return mat;
}
// printCidadeSemVizinhos(G, D);
// printTodasDistancias(G, D);
// printCidadeComMaisVizinhos(G, D);

#endif