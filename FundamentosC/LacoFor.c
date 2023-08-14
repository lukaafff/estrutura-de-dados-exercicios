#include <stdio.h>

int main () {

    for (int i = 0; i < 10; i++) {
	  printf("%u \n", i); 
	}
	system("pause");
	
	for (int i = 0; i <= 10; i++) {
	  printf("%u \n", i); 
	}
	system("pause");
	
	for (int i = 10; i > 0; i--) {
	  printf("%u \n", i); 
	}
	system("pause");
	 
	for (int i = 0; i < 1000; i = i + 30) {
	  printf("%u \n", i); 
	}
	system("pause");

    return 0;
}