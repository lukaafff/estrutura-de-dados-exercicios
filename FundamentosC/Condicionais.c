#include <stdio.h>

int main () {

    int a = 10;
	// linha
	if(a==10) printf("%s \n", "verdade"); else printf("%s \n", "falsidade");
	// sem chaves
	if(a==10) 
		printf("%s \n", "verdade"); 
	else 
		printf("%s \n", "falsidade");	
	// com chaves
	if(a==10) {
		printf("%s \n", "verdade"); 
	}
	else {
		printf("%s \n", "falsidade");
	}	
	// encadeado
	if(a==10) {
		printf("%s \n", "verdade"); 
	}
	else if(a==20){
		printf("%s \n", "outra opção"); 
	}
	else {
		printf("%s \n", "falsidade");
	}
	// aninhado
	if(a==10) {
		printf("%s \n", "verdade"); 
		 if(a==20){
			printf("%s \n", "outra opção"); 
		} else {
			printf("%s \n", "falsidade");
		}
	} else {
		printf("%s \n", "falsidade");
	}

    return 0;
}