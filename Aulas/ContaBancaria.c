#include <stdio.h>
#include <stdlib.h> // Para usar a função system()
#include <string.h> //trabalhar com string()

typedef struct {
    char nome[50];
    int numero;
    double saldo;
} contabancaria;

void inicia (contabancaria* conta, char* nome, int numero, double saldo) {
    //strncpy é uma função para copiar uma sequencia de caracters de uma fonte para um destino com um limite máximo
    strncpy(conta->nome, nome, sizeof(conta->nome));
    //        destino    fonte   numero de caracteres a serem copiados   
     
    (*conta).numero = numero;
    (*conta).saldo = saldo;
}

void deposito(contabancaria* conta) {
    double valor;
    printf("\n===============================\n");
    printf("Qual valor deseja depositar?\n");
    printf("===============================\n");

    while (1) {
        if (scanf("%lf", &valor) != 1 || valor <= 0 ) {
            // Limpar o buffer de entrada em caso de erro
            while (getchar() != '\n');
            printf("\n==========================================\n");
            printf("Valor para depositar e invalido. Tente novamente: ");
            printf("\n==========================================\n");
        } else {
            break;
        }
    }
}

/*
void deposito (contabancaria* conta, double valor) {
    (*conta.saldo += valor);
}
*/

void saque(contabancaria* conta) {
    double valor;
    printf("\n===============================\n");
    printf("Qual valor deseja sacar?\n");
    printf("===============================\n");

    while (1) {
        if (scanf("%lf", &valor) != 1 || valor <= 0 || valor > conta->saldo) {
            // Limpar o buffer de entrada em caso de erro
            while (getchar() != '\n');
            printf("\n==========================================\n");
            printf("Valor para sacar e invalido. Tente novamente: ");
            printf("\n==========================================\n");
            
        } else {
            break;
        }
    }

    conta->saldo -= valor;
    printf("===============================\n");
    printf("\nSaque feito com sucesso!\n");
    printf("===============================\n");
}

/*
void saque (contabancaria* conta, double valor) {
    (*conta.saldo -= valor);
}
*/

void imprime(contabancaria conta) {
    printf("\n======= CONTA BANCARIA =======\n");
    printf("Conta de: %s\n", conta.nome);
    printf("Numero da conta: %d\n", conta.numero);
    printf("Saldo disponivel: %.2f\n", conta.saldo); //.2 formatação apos virgula
}

int main() {
    contabancaria minhaConta;
    inicia(&minhaConta, "Luiza", 24052003, 0.0);

    imprime(minhaConta);

    int opcao;

    while (1)
    {
        printf("\n===== SELECIONE UMA OPCAO =====");
        printf("\n1 - Depositar");
        printf("\n2 - Sacar");
        printf("\n3 - Sair");
        printf("\n===============================\n");

        if (scanf("%d", &opcao) != 1){
            // Limpar o buffer de entrada em caso de erro
            while (getchar() != '\n');
            printf("\n==========================================\n");
            printf("Opcao invalida. Tente novamente: ");
            printf("\n==========================================\n");
        } else {

            switch (opcao)
        {
            case 1:
                system("clear");
                deposito(&minhaConta);
                imprime(minhaConta);
                break;

            case 2:
                system("clear");
                saque(&minhaConta);
                imprime(minhaConta);
                break;

                case 3:
                system("clear");
                printf("\n===============================\n");
                printf("Saindo da conta...");
                printf("\n===============================\n");
                return 0;
                break;
            
            default:
                printf("\n===============================\n");
                 printf("Opcao invalida. Tente novamente.\n");
                 printf("==============================\n");
                break;
        }

    }
        }
        
    return 0;
}