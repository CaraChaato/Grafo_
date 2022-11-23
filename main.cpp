/**
 * ATEN��O: Este arquivo � apenas um modelo de como pretendo que as respostas finais sejam apresentadas por voc�s.
*/
#include <stdio.h>
/**
 * O Arquivo estrutura.cpp inclui todas as fun��es que definem o Grafo e ser�o utilizadas neste arquivo main.cpp.
 */

#include "estrutura.cpp"
#include "grafo.cpp"
#include "lerArquivos.cpp"


int main() {

    char *arquivo = (char *)"Cidades.txt";
    Cidade *Dados = getCidades(arquivo);

    float D[] = {0.05, 0.1, 0.15, 0.20, 0.25, 1, 1.5, 2};

    float **mat = criaVizinhos(Dados, D[4]);

    printf("\nQuestão 01:");
    printMat(mat);// Matriz de Adjacência de todas as cidades, questão 1.
    printf("\nQuestão 02:");
    printMaisVizinhos(mat,Dados); //Cidade com mais vizinhos, questão 2.
    printf("\nQuestão 03:");
    printSemVizinhos(mat,Dados);// Cidade sem vizinhos, questão 3.
    printf("\nQuestão 04:");
    printMaiorDistancia(Dados);// Maior distância, questão 4.
    
   return 0;
}
