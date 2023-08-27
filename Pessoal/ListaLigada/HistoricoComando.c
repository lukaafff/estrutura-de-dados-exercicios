#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Comando {
    char comando[100];
    struct Comando* anterior;
    struct Comando* proximo;
} Comando;

Comando* adicionarComando(Comando* inicio, const char* comando) {
    Comando* novoComando = (Comando*)malloc(sizeof(Comando));
    strcpy(novoComando->comando, comando);
    novoComando->anterior = NULL;

    if (inicio != NULL) {
        inicio->anterior = novoComando;
    }

    novoComando->proximo = inicio;
    return novoComando;
}

Comando* irParaComandoAnterior(Comando* atual) {
    if (atual == NULL || atual->anterior == NULL) {
        return atual;
    } else {
        return atual->anterior;
    }
}

Comando* irParaComandoProximo(Comando* atual) {
    if (atual == NULL || atual->proximo == NULL) {
        return atual;
    } else {
        return atual->proximo;
    }
}

void imprimirComandos(Comando* inicio) {
    Comando* atual = inicio;
    while (atual != NULL) {
        printf("%s\n", atual->comando);
        atual = atual->proximo;
    }
}

int main() {
    Comando* historico = NULL;
    Comando* atual = NULL;

    char comando[100];
    int sair = 1;

    while (sair) {
        printf("\n------------------------------------------------\n");
        printf("Digite um comando: ");
        fgets(comando, sizeof(comando), stdin);
        comando[strlen(comando) - 1] = '\0';

        if (strcmp(comando, "anterior") == 0) {
            atual = irParaComandoAnterior(atual);
        } else if (strcmp(comando, "proximo") == 0) {
            atual = irParaComandoProximo(atual);
        } else {
            historico = adicionarComando(historico, comando);
            atual = historico;
        }

        if (atual != NULL) {
            printf("------------------------------------------------\n");
            printf("Comando atual: %s", atual->comando);
            printf("\n------------------------------------------------\n");
        } else {
            printf("\n------------------------------------------------\n");
            printf("Nenhum comando no momento");
            printf("\n------------------------------------------------\n");
        }
    }

    Comando* comandoAtual = historico;
    while (comandoAtual != NULL) {
        Comando* comandoProximo = comandoAtual->proximo;
        free(comandoAtual);
        comandoAtual = comandoProximo;
    }

    return 0;
}