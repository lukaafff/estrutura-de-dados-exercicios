#include <stdio.h>

typedef struct {
    int numero;
    double saldo;
} contabancaria;

void inicia (contabancaria* conta, int numero, double saldo) {
    (*conta).numero = numero;
    (*conta).saldo = saldo;
}

void deposito(contabancaria* conta, double valor) {
    conta->saldo += valor;
}

/*
void deposito (contabancaria* conta, double valor) {
    (*conta.saldo += valor);
}
*/

void saque(contabancaria* conta, double valor) {
    conta->saldo -= valor;
}

/*
void saque (contabancaria* conta, double valor) {
    (*conta.saldo -= valor);
}
*/

void imprime(contabancaria conta) {
    printf("Numero Conta: %d\n", conta.numero);
    printf("Saldo: %.2f\n", conta.saldo); //.2 formatação apos virgula
}

int main() {
    contabancaria minhaConta;
    inicia(&minhaConta, 2405, 0.0);

    deposito(&minhaConta, 10);
    saque(&minhaConta, 5);

    imprime(minhaConta);

    return 0;
}
