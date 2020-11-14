#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int busquedaBinaria(int n, int* A, int x);

int main() {
    int n, x, i;
    scanf("%d %d", &n, &x);
    int *A = malloc(sizeof(int) * n);
    for(i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    busquedaBinaria(n, A, x) ?
        printf("YES\n") : printf("NO\n");
    return 0;
}

int busquedaBinaria(int n, int* A, int x) {
    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(A[mid] == x)
            return TRUE;
        (A[mid] < x) ?
            (left = mid + 1) : (right = mid - 1);
    }

    return FALSE;
}