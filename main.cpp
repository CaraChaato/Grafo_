/**
 * ATEN��O: Este arquivo � apenas um modelo de como pretendo que as respostas finais sejam apresentadas por voc�s.
*/
#include <stdio.h>
/**
 * O Arquivo estrutura.cpp inclui todas as fun��es que definem o Grafo e ser�o utilizadas neste arquivo main.cpp.
 */

#include "estruturas.cpp"
#include "grafo.cpp"

void initDados(Dados &d){
    for(int i = 0; i < SIZE; i++){
        d[i] = NULL;
    }
}

int lerArquivos(Dados &d){
    FILE *file = fopen("Cidades.txt","r");
    
    int id;
    latitude la;
    longitude lo;
    char* estado;
    char* cidade;
    for(int i = 0 ; i < SIZE; i++){
        fscanf(file, "%d %.2f %.2f %s %s", d[i]->id, d[i]->la, d[i]->lo, d[i]->estado, d[i]->cidade);
        printf("%d %.2f %.2f %s %s\n", d[i]->id, d[i]->la, d[i]->lo, d[i]->estado, d[i]->cidade);
    }
    fclose(file);
    return 0;
}

int main() {

    Dados d;
    initDados(d);
    
    lerArquivos(d);

    printf("deu certo!\n");
    //initGrafo(g);

    //Grafo G = criarGrafo("Cidades.txt");

    /*
    float *D = {0.05, 0.1, 0.15, 0.20, 0.25};
    // Quest�o I
    for (size_t i = 0; i < 5; i++) {
        printTodasDistancias(G, D);
    }

    //Quest�o II
    for (size_t i = 0; i < 5; i++) {
        printCidadeComMaisVizinhos(G, D);
    }

    //Quest�o III
    for (size_t i = 0; i < 5; i++) {
        printCidadeSemVizinhos(G, D);
    }
    */
}