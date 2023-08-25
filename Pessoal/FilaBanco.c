#include <stdio.h>
#include <stdlib.h>

#define MAX_CLIENTES 10

typedef struct cliente {
    char nome[50];
} Cliente;

typedef struct filaBanco {
    Cliente clientes[MAX_CLIENTES];
    int inicio;
    int fim;
} FilaBanco;

void entrarFila(FilaBanco *fila, const char *nome) {
    //se o numero de clientes na fila for menor que o limite
    if (fila->fim < MAX_CLIENTES) {
        //o nome é copiado para o array de clientes na posicao indicada por 'fim'
        strcpy(fila->clientes[fila->fim].nome, nome);
        printf("\n%s entrou na fila\n", nome);
        fila->fim++; //proxima posicao fila
    } else { //fila cheia
        printf("\n------------------------------------------------\n");
        printf("A fila esta cheia, %s nao pode entrar", nome);
        printf("\n------------------------------------------------\n");
    }
}

void atenderCliente(FilaBanco *fila) {
    //se o indice de inicio é menor que o indice de fim (tem clientes na fila)
    if (fila->inicio < fila->fim) {
        //o nome do cliente no inicio é exibido
        printf("\n%s foi atendido\n", fila->clientes[fila->inicio].nome);
        fila->inicio++; //proxima posicao fila
    } else {
        printf("\n------------------------------------------------\n");
        printf("Nao ha clientes na fila");
        printf("\n------------------------------------------------");
    }
}

int main() {
    FilaBanco fila;
    fila.inicio = fila.fim = 0;

    printf("\n------------------------------------------------\n");
    printf("Fila Banco");
    printf("\n------------------------------------------------\n");

    entrarFila(&fila, "Lais");
    entrarFila(&fila, "Diego");
    entrarFila(&fila, "Laura");
    entrarFila(&fila, "Marcos");

    printf("\n------------------------------------------------\n");

    atenderCliente(&fila);
    atenderCliente(&fila);
    atenderCliente(&fila);
    atenderCliente(&fila);
    atenderCliente(&fila);

    return 0;
}