/* Faça um programa que preencha um vetor de inteiros de tamanho 10 pedindo valores ao usuario.
Em seguida, calcule e salve nun segundo vetor o quadrado de cada elemento do primeiro vetor.
Por fim, imprima os valores. */

int main() {

    int vetor1 [10];
    int vetor2 [10];
    int i;

for(i = 0; i < 10; i ++){
    printf("Digite o valor da posicao %d: ", i);
    scanf("%d", &vetor1[i]);
}

for(i = 0; i < 10; i++){
    vetor2[i] = vetor1[i] * vetor1[i];
}

printf("\nVetor 1: ");
for(i = 0; i <10; i++){
    printf("%5d ",vetor1[i]);
}

printf("\nVetor 2: ");
for(i = 0; i <10; i++){
    printf("%5d ",vetor2[i]);
}

    return 0;
}