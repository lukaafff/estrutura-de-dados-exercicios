#include <stdio.h>

int main () {

    double nota1 = 5.5;
	double nota2 = 6.5;
	double nota3 = 9.0;
	double media = nota1 + nota2 + nota3 / 3;
	printf("%g \n", media);
	media = (nota1 + nota2 + nota3) / 3;
	printf("%g \n", media);

    return 0;
}