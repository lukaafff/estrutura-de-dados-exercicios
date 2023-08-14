#include <stdio.h>

int fatorial(int n) {
    int i;
    int fat = 1;

    for(i = 1; i <= n; i++)
        fat *= i;
    return fat;
}

int main() {
    int a;
    int b;
    int combinacao;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    combinacao = fatorial(a) / (fatorial(b) * fatorial(a - b));
    printf("Combinacao em %d", combinacao);

    return 0;
}
