#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario {
    char nomeUsuario[50];
    char senha[50];
    struct Usuario* esquerda;
    struct Usuario* direita;
} Usuario;

Usuario* criarUsuario(char nomeUsuario[], char senha[]) {
    Usuario* novoUsuario = (Usuario*)malloc(sizeof(Usuario));
    strcpy(novoUsuario->nomeUsuario, nomeUsuario);
    strcpy(novoUsuario->senha, senha);
    novoUsuario->esquerda = NULL;
    novoUsuario->direita = NULL;
    return novoUsuario;
}

Usuario* inserirUsuario(Usuario* raiz, char nomeUsuario[], char senha[]) {
    if (raiz == NULL) {
        return criarUsuario(nomeUsuario, senha);
    }
    int comparacao = strcmp(nomeUsuario, raiz->nomeUsuario);
    if (comparacao < 0) {
        raiz->esquerda = inserirUsuario(raiz->esquerda, nomeUsuario, senha);
    } else if (comparacao > 0) {
        raiz->direita = inserirUsuario(raiz->direita, nomeUsuario, senha);
    }
    return raiz;
}

Usuario* buscarUsuario(Usuario* raiz, char nomeUsuario[]) {
    if (raiz == NULL || strcmp(nomeUsuario, raiz->nomeUsuario) == 0) {
        return raiz;
    } else if (strcmp(nomeUsuario, raiz->nomeUsuario) < 0) {
        return buscarUsuario(raiz->esquerda, nomeUsuario);
    } else {
        return buscarUsuario(raiz->direita, nomeUsuario);
    }
}

int autenticarUsuario(Usuario* raiz, char nomeUsuario[], char senha[]) {
    Usuario* usuario = buscarUsuario(raiz, nomeUsuario);
    if (usuario != NULL && strcmp(senha, usuario->senha) == 0) {
        return 1; // Autenticação bem-sucedida
    } else {
        return 0; // Autenticação falhou
    }
}

int main() {
    Usuario* listaUsuarios = NULL;

    listaUsuarios = inserirUsuario(listaUsuarios, "laura", "senha");
    listaUsuarios = inserirUsuario(listaUsuarios, "lais", "skafe");
    listaUsuarios = inserirUsuario(listaUsuarios, "luiza", "luiza");
    listaUsuarios = inserirUsuario(listaUsuarios, "marcos", "qwert");
    listaUsuarios = inserirUsuario(listaUsuarios, "carlos", "123");

    char nomeUsuario[50];
    char senha[50];

    printf("\n------------------------------------------------\n");
    printf("Digite o nome de usuario: ");
    gets(nomeUsuario);
    printf("\n------------------------------------------------\n");
    printf("Digite a senha: ");
    gets(senha);

    if (autenticarUsuario(listaUsuarios, nomeUsuario, senha)) {
        system("clear");
        printf("\n------------------------------------------------\n");
        printf("Autenticacao bem-sucedida. Bem-Vindo, %s!ka", nomeUsuario);
        printf("\n------------------------------------------------\n");
    } else {
        system("clear");
        printf("\n------------------------------------------------\n");
        printf("Autenticacao falhou. Usuario ou senha incorretos.");
        printf("\n------------------------------------------------\n");
    }

    return 0;
}