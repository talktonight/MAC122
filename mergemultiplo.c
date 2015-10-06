#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char *argv[]) {
	int numArquivos, i, x;
	FILE *entrada[100];
	numArquivos = argc - 1; /* arrumar quando tiver modulo e arquivo de saida! */
	printf("%d \n", numArquivos);
	for (i = 1; i < argc - 1; i ++)
		entrada[i] = fopen (argv[i], "r");
	fscanf(entrada[1], "%d", &x);
	printf("%d", x);
	return 0;
}
