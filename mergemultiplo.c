#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void *mallocc (size_t nbytes)
{
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == NULL) {
      printf ("Socorro! malloc devolveu NULL!\n");
      exit (EXIT_FAILURE);
   }
   return ptr;
}

void intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = mallocc ((r - p) * sizeof (int));
    for (i = 0, k = p; k < q; ++i, ++k) w[i] = v[k];
    for (j = r - p - 1, k = q; k < r; --j, ++k) w[j] = v[k];
    i = 0; j = r - p - 1;
    for (k = p; k < r; ++k) {
        if (w[i] <= w[j]) v[k] = w[i++];
        else v[k] = w[j--];
    }
    free (w);
}

void mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergesort (p, q, v);
        mergesort (q, r, v);
        intercala (p, q, r, v);
    }
}

int main (int argc, char *argv[]) {
    int numArquivos, i, minimos[100], minimosOrdenados[100];
    FILE *entrada[100];
    numArquivos = argc - 1; /* arrumar quando tiver modulo e arquivo de saida! */
    printf("%d \n", numArquivos);
    for (i = 0; i < numArquivos; i++)
        entrada[i] = fopen (argv[i + 1], "r");
    /* leitura dos minimos */
    for (i = 0; i < 100; i++) {
        fscanf (entrada[i], "%d", &minimos[i]);
        minimosOrdenados[i] = minimos[i];
    }
    /* ordena minimos */
    mergesort (0, 1, minimosOrdenados);

    for (i = 0; i < 1; i++) printf("%d \n", minimosOrdenados[i]);

    return 0;
}
