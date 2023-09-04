#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musicas {
    char nomeMusica[50];
    char nomeArtista[50];
    struct Musicas* proximo;
} Musicas;

Musicas* adiconarMusicas(Musicas* lista, char nomeMusica[], char nomeArtista[]) {
    Musicas* novaMusica = (Musicas*)malloc(sizeof(Musicas));
    strcpy(novaMusica->nomeMusica, nomeMusica);
    strcpy(novaMusica->nomeArtista, nomeArtista);
    novaMusica->proximo = NULL;

    if (lista == NULL) {
        //se lista vazia, a nova musica se torna o primeiro elemento
        return novaMusica;
    } else {
        Musicas* atual = lista;
        //percorrer até chegar no último nó
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        //insere musica no final
        atual->proximo = novaMusica;
        return lista;
    }
}

Musicas* removerMusica(Musicas* inicio, char nomeMusica[]) {
    Musicas* atual = inicio;
    Musicas* anterior = NULL;

    //percorrer lista
    while (atual !=NULL && strcmp(atual->nomeMusica, nomeMusica) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //nao achou a musica
    if (atual == NULL) {
        printf("Música não encontrada\n");
        return inicio;
    }

    //achou, retira nó da lista
    if (anterior == NULL) {
        //retira nó do inicio da lista
        inicio = atual->proximo;
    } else {
        //retira nó do meio da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return inicio;
}

void imprimirMusicas(Musicas* inicio) {
    printf("\n---------- LISTA DE MUSICAS ----------\n\n");
    Musicas* atual = inicio;
    while (atual != NULL) {
        printf("Nome da musica: %s\n", atual->nomeMusica);
        printf("Nome do artista: %s\n", atual->nomeArtista);
        printf("\n");
        atual = atual->proximo;
    }
}

int main() {
    Musicas* listaMusicas = NULL;

    listaMusicas = adiconarMusicas(listaMusicas, "Inabalavel", "LetoDie");
    listaMusicas = adiconarMusicas(listaMusicas, "Lobos nao usam coleira", "LetoDie");
    listaMusicas = adiconarMusicas(listaMusicas, "Resiliencia", "Tribo da periferia");
    listaMusicas = adiconarMusicas(listaMusicas, "Um dia apos o outro", "Tiago Iorc");
    listaMusicas = adiconarMusicas(listaMusicas, "Sonho", "Atitude 67");


    printf("\n------------------------------------------------\n");
    printf("Antes remover a musica");
    printf("\n------------------------------------------------\n");
    imprimirMusicas(listaMusicas);

    listaMusicas = removerMusica(listaMusicas, "Inabalavel");

    printf("\n------------------------------------------------\n");
    printf("Apos remover a musica Inabalavel");
    printf("\n------------------------------------------------\n");
    imprimirMusicas(listaMusicas);

    listaMusicas = removerMusica(listaMusicas, "Um dia apos o outro");

    printf("\n------------------------------------------------\n");
    printf("Apos remover a musica Um dia apos o outro");
    printf("\n------------------------------------------------\n");
    imprimirMusicas(listaMusicas);

    Musicas* atual = listaMusicas;
    while (atual != NULL)
    {
        Musicas* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}