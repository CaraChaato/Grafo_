#include "estrutura.cpp"   // TAD para a estrutura das cidade
#include "grafo.cpp"       // TAD onde acontece a manipulação do grafo
#include "lerArquivos.cpp" // TAD onde lemos o arquivo e salvamos na esrutura

/**
 * Função que testa a execução do grafo 
*/
int main() { 
    // arquivo que vai servir para ler Cidades.txt 
    char *arquivo = (char *)"Cidades.txt";
    Cidade *Dados = getCidades(arquivo);

    // D é um vetor que armazena as variações de distância
    float D[] = {0.05, 0.1, 0.15, 0.20, 0.25, 1, 1.5, 2};

    // mat é a variável que representa a matriz de adjacência do grafo
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
