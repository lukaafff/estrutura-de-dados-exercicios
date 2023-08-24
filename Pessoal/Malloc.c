#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int capacidade = 2;
    int tamanhoAtual = 0;

    char **listaNomes = (char **)malloc(capacidade * sizeof(char *));
    //listaNomes = variavel para armazenar um array de ponteiros de caracters
    //a listaNomes vai receber a alocação de um ponteiro para um bloco de memória
    //capacidadeInicial * sizeof(char *) - calcula o tamanho necessario de memoria que deve ser alocada através da multiplicação
        //capacidadeInicial = numeros de ponteiros de caracters que queremos armazenar
        //char* - tamanho do ponteiro de caracters

    //quando nao tiver espaço disponivel na memoria
    if(listaNomes == NULL) {
        printf("Erro na alocacao de memoria");
        return 1; //codigo de erro
    }

    printf("\nMemoria alocada para a lista inicial\n");

    //adicionar nomes na lista
    while(1) {
        char nome[50];
        printf("Digite um nome (ou 'sair' para encerrar o programa): ");
        scanf("%s", nome);

        //se a string digitada for igual a "sair" o programa para
        if(strcmp(nome, "sair") == 0) {
            break;
        }

        //verifica se tem espaço sem precisar realocar memoria
        if(tamanhoAtual >= capacidade) {
        //dobramos o valor da capacidade para poder adicionar mais nomes no futuro sem precisar realocar memoria imediatamente
        capacidade *= 2;

        printf("\nDobrando o tamanho da capacidade");

        //realloc é usado mais redimensionar dinamicamente o array listaNomes para uma nova capacidade
        listaNomes = (char **)realloc(listaNomes, capacidade * sizeof(char *));
        }
            if(listaNomes == NULL ) {
                printf("Erro na realocacao de memoria");
                return 1;
            }
            printf("\nMemoria realocada para a capacidade: %d\n", capacidade);

        //alocar memoria para armazenar um nome na ultima posição (tamanhoAtual) do array de ponteiros listaNomes
            //listaNomes[tamanhoAtual] = ponteiro na ultima posição (tamanhoAtual)
            //strlen(nome) = retorna o tamanho da string  e adiciona 1 para ter um caractere nulo ao final
        listaNomes[tamanhoAtual] = (char *)malloc(strlen(nome) + 1);
        //strcpy = usado para copiar a string listaNomes para a memoria alocada em listaNomes[tamanhoAtual]
            //faz com que a copia da string digitada seja alocada no array listaNomes
        strcpy(listaNomes[tamanhoAtual], nome);
        tamanhoAtual ++;
    }

    //imprime lista de nomes
    printf("\nLista de nomes:\n");
    for (int i = 0; i < tamanhoAtual; i++) {
        printf("%s\n", listaNomes[i]);
        free(listaNomes[i]);
    }

    free(listaNomes);

    return 0;
}