#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 5

typedef struct pilha {
    int itens[TAMANHO_MAX];
    int topo;
} Pilha;

void inicia(Pilha *pilha) {
    pilha->topo = -1; //indica que a pilha esta vazia
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1; //verifica se a pilha esta vazia comparando com -1
}

int estaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAX -1; //verifica se a pilha esta cheia comparando com o tamanho maximo
}

void empilhar(Pilha *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("\n------------------------------------------------\n");
        printf("A pilha esta cheia. Nao é possivel empilhar %d", valor);
        printf("\n------------------------------------------------\n");
        return;
    } else {
        //colocar no topo da pilha
        pilha->itens[++pilha->topo] = valor;
    }
} 

int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("\n------------------------------------------------\n");
        printf("A pilha esta vazia. Nao é possivel desempilhar");
        printf("\n------------------------------------------------\n");
        return -1;
    } else {
        //tira do topo da pilha
        return pilha->itens[pilha->topo--];
    }
}

int main () {
    Pilha pilhaNumeros;
    inicia(&pilhaNumeros);

    printf("\n------------------------------------------------\n");
    printf("Empilhando e desempilhando");
    printf("\n------------------------------------------------\n");

    empilhar(&pilhaNumeros, 10);
    empilhar(&pilhaNumeros, 20);
    empilhar(&pilhaNumeros, 30);
    empilhar(&pilhaNumeros, 40);
    empilhar(&pilhaNumeros, 50);

    printf("\n------------------------------------------------\n");
    printf("Numeros empilhados: ");
    printf("\n------------------------------------------------\n");
    for (int i = 0; i <= pilhaNumeros.topo; i++) {
        printf("%d\n", pilhaNumeros.itens[i]);
    }

    printf("\n------------------------------------------------\n");
    printf("Numeros desempilhados: ");
    printf("\n------------------------------------------------\n");
    while (!estaVazia(&pilhaNumeros)) {
        int numero = desempilhar(&pilhaNumeros);
        printf("%d\n", numero);
    }
    
    return 0;
}