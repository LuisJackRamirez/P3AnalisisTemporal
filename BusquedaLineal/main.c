#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int busquedaLineal(int n, int *A, int x);

int main() {
    int n, x, i;
    scanf("%d %d", &n, &x);
    int *A = malloc(sizeof(int) * n);
    for(i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    busquedaLineal(n, A, x) ?
        printf("YES\n") : printf("NO\n");
    return  0;
}

int busquedaLineal(int n, int *A, int x) {
    int i;
    for(i = 0; i < n; ++i)
        if(A[i] == x)
            return TRUE;
    return FALSE;
}