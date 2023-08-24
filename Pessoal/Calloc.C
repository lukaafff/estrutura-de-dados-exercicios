#include <stdio.h>
#include <stdlib.h>

int main () {
    int diasMes = 30;
    int *vendasDiarias = (int *)calloc(diasMes, sizeof(int));

    if(vendasDiarias == NULL) {
        printf(|"Erro na alocacao de memoria");
        return 1;
    }

    //simular vendar (valores aleatorios)
    for (int i = 0; i < diasMes; i++ ) {
        vendasDiarias[i] = rand() % 100; //entre 0 e 99
    }

    //soma das vendas
    int totalVendas = 0;
    for (int i = 0; i < diasMes; i ++) {
        totalVendas += vendasDiarias[i];
    }

    printf("Total de vendas no mes foi de: %d", totalVendas);

    free(vendasDiarias);

    return 0;
}