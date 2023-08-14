#include <stdio.h>

int main () {
    printf("Tamanho de char: %lu bytes\n", sizeof(char));
    printf("Tamanho de int: %lu bytes\n", sizeof(int));
    printf("Tamanho de short: %lu bytes\n", sizeof(short));
    printf("Tamanho de long: %lu bytes\n", sizeof(long));
    printf("Tamanho de float: %lu bytes\n", sizeof(float));
    printf("Tamanho de double: %lu bytes\n", 
    sizeof(double));
    printf("Tamanho de long double: %lu bytes\n", 
    sizeof(long double));

    return 0;
}