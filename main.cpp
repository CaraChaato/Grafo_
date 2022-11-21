/**
 * ATEN��O: Este arquivo � apenas um modelo de como pretendo que as respostas finais sejam apresentadas por voc�s.
*/
#include <stdio.h>
/**
 * O Arquivo estrutura.cpp inclui todas as fun��es que definem o Grafo e ser�o utilizadas neste arquivo main.cpp.
 */

#include "estruturas.cpp"
#include "grafo.cpp"
#include "lerarquivos.cpp"


int main() {

    
    char *arquivo = (char *)"Cidades.txt";
    Cidade *Dados = getCidades(arquivo);

    float D[] = {0.05, 0.1, 0.15, 0.20, 0.25};

    float **mat = criaVizinhos(Dados, D[1]);

    //printCidades(Dados);

    printf("\nDeu certo!\n");
    

    /*
    

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
   return 0;
}