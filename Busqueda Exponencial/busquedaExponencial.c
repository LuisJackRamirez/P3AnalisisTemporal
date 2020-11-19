#include <stdio.h>
#include <stdlib.h>

int busquedaExponencial(int *A, int n, int x){
	int anterior = 0, actual = 1;
	int i = 0;

	if(A[0] == x)
		return 1;

	while((actual < n) && (A[actual] < x)){
		anterior = actual;
		actual *= 2;
	}

	return busquedaBinaria(A, n, x, anterior, actual);
}

int busquedaBinaria(int *A, int n, int x, int inf, int sup){
	int limInf = inf;
	int limSup = sup;
	int centro = (limSup+limInf)/2;
	int bandera = 0;

	while((limInf <= limSup) && (bandera == 0)){
		if(A[centro] == x)
			bandera = 1;
		else if(A[centro] < x)
			limInf = centro+1;
		else
			limSup = centro-1;

		centro = (limSup+limInf)/2;
	}

	return bandera;
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
