#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct No* esquerda; //ponteiro filho
    struct No* direita; //ponteiro filho
} No;

No* criarNo(int valor) {
//aloca memoria para um novo no e preenche com valor inteiro
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    //inicia os pontiros como nulos
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

void inserirNo(No** raiz, int valor) {
    //Se a raiz for nula, um novo nó é criado
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        //se nao for nulo significa que existe um nó na arvore e aqui decide se vai ser inserido na esquerda ou direita
    } else if (valor <= (*raiz)->valor) {
        //Se o valor a ser inserido for menor ou igual ao valor do nó atual, insere na esquerda
        inserirNo(&((*raiz)->esquerda), valor);
        //*raiz é o ponteiro que aponta para o nó atual da árvore.
        //(*raiz)->esquerda é o ponteiro que aponta para o filho esquerdo do nó atual.
        //&((*raiz)->esquerda) é um ponteiro para o ponteiro que aponta para o filho esquerdo do no atual
        //valor é o valor a ser inserido na subárvore esquerda.
    } else {
        //Se o valor a ser inserido for maior ou igual ao valor do nó atual, insere na direita
        inserirNo(&((*raiz)->direita), valor);
    }
}

void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    No* arvore = NULL;

    inserirNo(&arvore, 5);
    inserirNo(&arvore, 3);
    inserirNo(&arvore, 8);
    inserirNo(&arvore, 1);
    inserirNo(&arvore, 4);
    inserirNo(&arvore, 7);
    inserirNo(&arvore, 9);
    inserirNo(&arvore, 2);
    inserirNo(&arvore, 6);
    inserirNo(&arvore, 10);

    printf("\n------------------------------------------------\n");
    printf("Numeros ordenados: ");
    printf("\n------------------------------------------------\n");
    percorrerEmOrdem(arvore);
    printf("\n------------------------------------------------\n");

    return 0;
}