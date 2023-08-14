#include <stdio.h>

int main () {

    int a = 2;
	int b;
	b = a++;
	printf("%u \n", a);
	printf("%u \n", b);
	b = ++a;
	printf("%u \n", a);
	printf("%u \n", b);

    return 0;
}