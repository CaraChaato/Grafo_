#ifndef GRAFO_CPP
#define GRAFO_CPP   

// Bibliotecas declaradas aqui servem para todo o código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "estrutura.cpp"

// Variável que limita o tamanho da matriz de adjacência do grafo
#define SIZE 167

// Declaração das funções do código
float **criaVizinhos (Cidade *c, float d);
void printMaisVizinhos(float **G, Cidade *c);
void printMaiorDistancia(Cidade *c);
int printSemVizinhos(float **G, Cidade *c);
void printMat(float **mat);

/**
 * Função que cria a matriz de adjacência do Grafo
 * @param c
 * @param d
 * @return **float
*/
float **criaVizinhos (Cidade *c, float d){
    
    // Variáveis Auxiliares
    int i, j;

    // Matriz de Adjacência
    float **mat = (float**) malloc(SIZE*sizeof(float*));
    for(i = 0; i < SIZE; i++)
        mat[i] = (float*) malloc(SIZE*sizeof(float));

    // Limpando os slots da matriz
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) 
            mat[i][j] = 0;
    }

    // Testando se as cidades são vizinhas
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < i+1; j++) {

            // Se a linha for igual a coluna o local vai receber -1 pois a cidade não pode ser vizinha dela mesma
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

/**
 * Função que imprime a cidade com a maior quantidade de vizinhos de acordo com a matriz
 * @param G
 * @param c
*/
void printMaisVizinhos(float **G, Cidade *c){
    size_t tmp = 0, highest[2] = {0,0};
    /*
        tmp = variável temporária.
        highest = variável vetor de tamanho 2 que armazena a cidade com mais vizinhos.
    */

    for (size_t i = 0; i < SIZE; i++) { // Linhas da matriz
        for (size_t y = 0; y < SIZE; y++) // Colunas da matriz; Percorre as colunas de acordo com as linhas
            tmp = (G[i][y]>0) ? tmp+1: tmp; // Armazena na var tmp a quantidade de vizinhas presente nessa linha    

        if(tmp>highest[1]){ // Analisa se o total de vizinhaças desse iterando é maior que o da cidade atual
            highest[0] = i; // Armazena o id da cidade
            highest[1] = tmp; // Armazena juntamente a sua quantidade de vizinhos
        }

        tmp*=0; // Zera a var tmp para recomeçar a contagem de vizinhaças em uma nova cidade
    }
    printf("\n\nA cidade com mais vizinhos(%lu vizinhos): %s",highest[1],c[highest[0]].cidade);
    // Por fim, dita qual foi a cidade com maior quantidade de vizinhaças de acordo com o Cidade *c passado
}

/**
 * Imprime a maior distância para que todas as cidades sejam vizinhas
 * @param c
*/
void printMaiorDistancia(Cidade *c){
    // Variáveis Auxiliares
    float dif, maior = 0; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != j){
                dif = sqrt(pow((c[i].la-c[j].la),2)+pow((c[i].lo-c[j].lo),2)); // calculo da diferênça de distância entre duas cidades.
                if(dif > maior) // caso a diferença seja maior que o anterior, será renovado.
                    maior = dif;
            }
        }
    }
    printf("\nA maior diferença é %.2f\n", maior);
}

/**
 * Imprime as cidades que não possuem vizinhos
*/
int printSemVizinhos(float **G, Cidade *c){
    size_t tmp = 0, i, y;

    for (i = 0; i < SIZE; i++) { // Linhas da matriz
        for (y = 0; y < SIZE; y++){ // Colunas da matriz; Percorre as colunas de acordo com as linhas   
            if(G[i][y]<0){ // Analisa se essa coluna é menor que 0, ou seja, se não é um vizinho.
                tmp=0;
            }else{
                tmp=1;
                break; // Caso tenha vizinho então já pode pular para a próxima cidade (linha) através do break neste for.
            }
        }
        if(tmp==0) // Ao terminar a iteração dentro dessa linha é julgado se a cidade tem ou não vizinhos
           printf("\nCidade sem vizinho encontrada:%s", c[i].cidade);
    }
    
    return 0;

}

void imprimirParaArquivo(float **M, Cidade *c){
    char* tmp;
    size_t length;
    FILE *file = fopen("output.txt","w+");
    for (size_t i = 0; i < SIZE; i++) {
        length = strlen(c[i].cidade)-2;
        tmp = (char*) malloc(sizeof(char)*length);
        strncpy(tmp,c[i].cidade,length);
        fprintf(file,"[%s ]\n",tmp);
        for(size_t y = 0; y < SIZE; y++){
            if(M[i][y]>0){
                length = strlen(c[y].cidade)-2;
                tmp = (char*) malloc(sizeof(char)*length);
                strncpy(tmp,c[y].cidade,length);
                fprintf(file,"\t-> %s",tmp);
            }
        }
        fprintf(file,"\n");
    }
    fclose(file);
}

/**
 * Imprime a matriz de incidência
*/
void printMat(float **mat){
    for (int i = 0; i < SIZE; i++) {
        printf("\n ");
        for (int j  = 0; j < SIZE; j++) {
            mat[i][j] == -1? printf("%.1f\t", mat[i][j]): printf("%.2f\t", mat[i][j]);
            // Operador ternário para printar a matriz com maior uniformidade
        }
    }
} 

#endif
