//lista ligada
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[50];
    int numero[9];
    struct Contato* proximo;
} Contato;

Contato* criarContato(Contato* lista, char nome[], int numero[]) {
    Contato* novoContato = (Contato*)malloc(sizeof(Contato));
    strcpy(novoContato->nome, nome);
    //converte o número inteiro em uma string e armazena no campo 'numero'
    sprintf(novoContato->numero, "%d", numero); 
    novoContato->proximo = NULL;
    return novoContato;
}

Contato* inserirContato(Contato* inicio, Contato* novoContato) {
    if (inicio == NULL) {
        return novoContato;
    }

    Contato* atual = inicio;
    //percorrer lista até chegar no ultimo nó
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    //ultimo nó da lista aponta para o novoContato
    atual->proximo = novoContato;
    //certificar que seja o ultimo nó
    novoContato->proximo = NULL;

    return inicio;
}

Contato* removerContato(Contato* inicio, char nome[]) {
    Contato* atual = inicio;
    Contato* anterior = NULL;

    //percorrer lista
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //nao encontrou o contato
    if (atual == NULL) {
        printf("Contato não encontrado");
        return inicio;
    } 

    //achou, retira nó da lista
    if (anterior == NULL) {
        //retira no do inicio da lista
        inicio = atual->proximo;
    }
    else {
        //retira nó do meio da lista
        anterior->proximo = atual->proximo;
    }
    free(atual);
    return inicio;
}

void imprimirContato(Contato* inicio) {
    printf("\n---------- LISTA DE CONTATO ----------\n\n");
    Contato* atual = inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Numero: %s\n", atual->numero);
        printf("\n");
        atual = atual->proximo;
    }
}

int main() {
    Contato* listaContato = NULL;

    Contato* contato1 = criarContato(NULL, "Laura", 990191968);
    Contato* contato2 = criarContato(NULL, "Luiza", 994255826);
    Contato* contato3 = criarContato(NULL, "Marcos", 965447112);
    Contato* contato4 = criarContato(NULL, "Paulo", 745889300);
    Contato* contato5 = criarContato(NULL, "Amanda", 856320114);

    listaContato = inserirContato(listaContato, contato1);
    listaContato = inserirContato(listaContato, contato2);
    listaContato = inserirContato(listaContato, contato3);
    listaContato = inserirContato(listaContato, contato4);
    listaContato = inserirContato(listaContato, contato5);

    printf("\n------------------------------------------------\n");
    printf("Antes de remover o contato");
    printf("\n------------------------------------------------\n");
    imprimirContato(listaContato);

    listaContato = removerContato(listaContato, "Luiza");

    printf("\n------------------------------------------------\n");
    printf("Apos remover o contato Luiza");
    printf("\n------------------------------------------------\n");
    imprimirContato(listaContato);

    listaContato = removerContato(listaContato, "Paulo");

    printf("\n------------------------------------------------\n");
    printf("Apos remover o contato Paulo");
    printf("\n------------------------------------------------\n");
    imprimirContato(listaContato);

    listaContato = removerContato(listaContato, "Amanda");

    printf("\n------------------------------------------------\n");
    printf("Apos remover o contato Amanda");
    printf("\n------------------------------------------------\n");
    imprimirContato(listaContato);

    Contato* atual = listaContato;
    while (atual != NULL)
    {
        Contato* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}