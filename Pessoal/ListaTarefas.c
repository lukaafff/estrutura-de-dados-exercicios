#include <stdio.h>
#include <stdlib.h>

typedef struct Tarefa {
    char titulo[50];
    char descricao[100];
    struct Tarefa* proximo;
} Tarefa;

//inicar lista de tarefas nula
Tarefa* inicia() {
    return NULL;
}

//criar tarefa
Tarefa* criarTarefa(const char* titulo, const char* descricao) {
    Tarefa* nova_tarefa = (Tarefa*)malloc(sizeof(Tarefa));

    //verifica se tem espaço disponivel na memoria
    if (nova_tarefa == NULL) {
        perror("Falha ao alocar memória para a tarefa");
        return 1;
    }

    //copiar os caracters do "titulo" para o campo "titulo" da nova tarefa
    for (int i = 0; i < 50 && titulo[i] != '\0'; i++) {
        nova_tarefa->titulo[i] = titulo[i];
    }

    //copiar os caracters da "descrição" para o campo "descrição" da nova tarefa
    for (int i = 0; i < 100 && descricao[i] != '\0'; i++) {
        nova_tarefa->descricao[i] = descricao[i];
    }

    nova_tarefa->proximo = NULL;
    return nova_tarefa;
}

    //inserir nova tarefa no inicio da lista
    //inicio é o ponteiro para a primeira tarefa na lista
    Tarefa* inserirTarefa(Tarefa* inicio, Tarefa* novaTarefa) {
        novaTarefa->proximo = inicio;
        return novaTarefa;
    }

    void imprimeTarefas(Tarefa* inicio) {
        printf("\n---------- LISTA DE TAREFAS ----------\n\n");
        Tarefa* atual = inicio;
        while (atual != NULL) {
            printf("Titulo: %s\n", atual->titulo);
            printf("Descricao: %s\n", atual->descricao);
            printf("\n");
            atual = atual->proximo;
        }
    }

int main() {

    Tarefa* listaTarefas;
    listaTarefas = inicia();

    Tarefa* tarefa1 = criarTarefa("Comprar mantimentos", "Leite, ovos, pao");
    Tarefa* tarefa2 = criarTarefa("Finalizar relatorio", "Prazo na proxima semana");
    Tarefa* tarefa3 = criarTarefa("Ir para a academia", "Treino de cardio");

    listaTarefas = inserirTarefa(listaTarefas, tarefa1);
    listaTarefas = inserirTarefa(listaTarefas, tarefa2);
    listaTarefas = inserirTarefa(listaTarefas, tarefa3);

    imprimeTarefas(listaTarefas);

    //liberar memória alocada
    Tarefa* atual = listaTarefas;
    while (atual != NULL)
    {
        Tarefa* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    

    return 0;
}