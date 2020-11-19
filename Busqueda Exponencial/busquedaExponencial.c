#include <stdio.h>
#include <stdlib.h>

int busquedaExponencial(int *A, int n, int x) {
	int anterior = 0, actual = 1;
	int i = 0;

	if(A[0] == x)
		return 1;

	while((actual < n) && (A[actual] < x)) {
		anterior = actual;
		actual *= 2;
	}

	return busquedaBinaria(A, n, x, anterior, actual);
}

int busquedaBinaria(int* A, int n, int x){
    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(A[mid] == x)
            return 1;
        (A[mid] < x) ?
            (left = mid + 1) : (right = mid - 1);
    }

    return 0;
}

int main(){
	int n, x, i;
	
    scanf("%d %d", &n, &x);
    
    int *A = malloc(sizeof(int) * n);
    
    for(i = 0; i < n; ++i)
        scanf("%d", &A[i]);
        
	int encontrado;
	
	encontrado = busquedaExponencial(A,n,x); //Si encuentra el numero retornara 1
											 //Si no lo encuentra devolvera 0
	
	printf("\n%d",encontrado);
	
	return 0;
}
