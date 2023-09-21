//bibliotecas
#include <stdio.h>
#include<stdlib.h>

//estrutura principal
typedef struct no {
    int info;
    struct no* proximo; //ponteiro que aponta para o proximo nó
} No;

//retorna ponteiro nulo, indicando lista vazia
No* inicia() {
    return NULL;
}

//inserir elementos na lista
No* insere(No* lista, int num) { //assinaturas da função (ponteiro para o inicio da lista, inteito armazenará valor do novo no)
    No* novo_no = (No*)malloc(sizeof(No)); //alocar quantidade necessária de memória para o novo no

    // o valor passado como parametro é colocado dentro do num
    novo_no->info = num;

    //aponta para o no que estava no inicio da lista, e insere o novo o no inicio
    novo_no->proximo = lista;

    //o novo no se rorna o novo inicio da lista
    return novo_no;
}

No* retira(No* lista, int num) {
    No* anterior = NULL; /* ponteiro para o no anterior */
    No* aux = lista; /* ponteiro auxiliar para percorrer
	lista */

    /* procura o no na lista, guardando o no anterior */
    //verifica se o ponteiro aux nao é nulo e se o campo info que é apontado pelo aux nao é igual o valor do num que etsamos procurando
    //se for verdadeira nao é o numero que estamos procurando
    while(aux != NULL && aux->info != num) {
        anterior = aux;
        aux = aux->proximo;
    }

    /* Verifica se achou o no */
    if (aux == NULL) {
        return lista; /* nao achou, retorna lista original */
    }

    /* achou, retira o no da lista */
    if (anterior == NULL) {
        lista = aux->proximo; /* retira no do inicio da lista */
    }

    /* retira no do meio da lista */
    else {
        anterior->proximo = aux->proximo;
    }

    /* libera espaco na memoria usado para alocar a variavel */
    free(aux);

    //retorna para o ponteiro da lista atualizada apos remoção
    return lista;
}

No* busca(No* lista, int num) { //assinatura da lista (lista é o ponteiro do inicio da lista e num é o numero que estamos buscando)
    No* aux; //ponteiro auxiliar para percorrer a lista
    //onde começa -   ate onde vai  -  o que faz
    //inicio da lista - ate aux for vazio - aponta para o proximo no  
    for (aux = lista; aux !=NULL; aux = aux->proximo) {
        //verifica se o valor do no atual é igual ao numero que buscamos
        if (aux->info == num) {
            //se sim, rertonar o ponteiro para o no
            return aux;
        } else {
            //nao foi encontrado, retorna ponteiro vazio
            return NULL;
        }
    }
}

void imprime(No* lista) {
	No* aux; /* variavel auxiliar para percorrer a lista */
	for (aux = lista; aux != NULL; aux = aux->proximo)
		printf("\n Numero: %d\n", aux->info);
}

int main() {
    printf("Listas Ligadas\n\n");

    No* lista;
    lista = inicia();
    lista=insere(lista, 23);
	lista=insere(lista, 56);
	lista=insere(lista, 45);
	lista=insere(lista, 90);
	
	printf("\n %x \n", &lista);
	imprime(lista);
	
	lista=retira(lista, 45);
	printf("Apos remocao do 45 \n\n");
	imprime(lista);
	
	return 0;
}