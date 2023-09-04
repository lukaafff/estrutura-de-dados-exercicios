#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estudantes {
    int matricula[6];
    char nome[50];
    double nota1[2];
    double nota2[2];
} Estudantes;

 Estudantes* inserirEstudante(Estudantes* lista, int matricula[], char nome[], double nota1[], double nota2[]){
    Estudantes* novoRegistro = (Estudantes*)malloc(sizeof(Estudantes));
 }