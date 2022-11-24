#ifndef LERARQUIVOS_CPP
#define LERARQUIVOS_CPP

#include <stdio.h> // Ler e Inserir dados
#include <stdlib.h> // Operações de prompt
#include <string> // Auxiliar com caracteres
#include "estrutura.cpp" // Estrutura da cidade
#include "grafo.cpp" // TAD que contém as funções do grafo

// Variável auxiliar para a leitura do arquivo
#define MAX 167

// Declarando as funções
Cidade *getCidades(char *arquivo);
void printCidades(Cidade *dado);

/**
 * @brief Lê o arquivo passado como parametro e retorna uma estrutura Cidade
 * @param arquivo 
 * @return cidade* 
 */
Cidade *getCidades(char *arquivo){

    // Abre o arquivo
    FILE *f = fopen(arquivo, "r");
    // Aloca o espaço para todas as cidades
    Cidade *dados = (Cidade*) malloc(MAX*sizeof(Cidade));

    // Informa se o arquivo não for aberto
    if (!f) {
        perror("\nErro na Abertura do Arquivo!\n");
        return NULL;
    }

    // Variáveis auxiliares para a leitura do arquivo
    unsigned int id;
    char *uf;
    char *cid;
    latitude la;
    longitude lo;
    int i = 0;

    // Percore o arquivo salvando as informações 
    while (!feof(f)) {
        uf = (char *)malloc(2 * sizeof(char));
        cid = (char *)malloc(40 * sizeof(char));

        fscanf(f, "%d %f %f %s", &id, &la, &lo, uf);
        fgets(cid, 40 * sizeof(char), f);

        dados[i].id = id; // ID da cidade
        dados[i].estado = uf; // Estado
        dados[i].cidade = cid; // Cidade
        dados[i].la = la; // Latitude
        dados[i].lo = lo; // Longitude        
        i++;
    }
    return dados; // Retorna a estrutura
}

/**
 * Função que imprime as cidades lidas no arquivo
 * @param dado
*/
void printCidades(Cidade *dado){
    for (int i = 0; i < MAX; i++) {
        printf(" %d -> %.2f %.2f %s %s \n\n\n", dado[i].id, dado[i].la, dado[i].lo, dado[i].estado, dado[i].cidade);
    }
}

#endif