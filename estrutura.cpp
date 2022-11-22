#ifndef ESTRUTURA_CPP
#define ESTRUTURA_CPP // ESTRUTURA_CPP é chamado multiplas vezes, para que esse só seja declarado uma vez usamos o #define

typedef float latitude;
typedef float longitude;

/**
 * Estrutura que representa a cidade
*/
typedef struct{
    int id; // Chave primária de uma cidade
    char *estado; // UF do estado
    char *cidade; // Nome da cidade
    latitude la; // Latitude da cidade 
    longitude lo; // Longitude da cidade
} Cidade;

#endif