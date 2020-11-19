#include <stdio.h>
#include <stdlib.h>

int busquedaFibonacci(int *A, int n, int x){
	int i;
	
    int fibMMm2 = 0;   
    int fibMMm1 = 1;    
    int fibM = fibMMm2 + fibMMm1;  
  
    while (fibM < n){ 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
     
    int offset = -1; 
  
    while (fibM > 1){ 
        
        int i = min(offset+fibMMm2, n-1); 
  
        if (A[i] < x){ 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
        else if (A[i] > x){ 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
        else return i; 
    } 
  
    if(fibMMm1 && A[offset+1]==x)return offset+1; 
  
    return -1; 
}

int min(int x, int y){ 
	return (x<=y)? x : y; 
} 

int main(){
	int n, x, i;
	
    scanf("%d %d", &n, &x);
    
    int *A = malloc(sizeof(int) * n);
    
    for(i = 0; i < n; ++i)
        scanf("%d", &A[i]);
        
	int encontrado; 
	
	encontrado = busquedaFibonacci(A,n,x); //Si encuentra el numero devolvera la posicion
										  //Si no lo encuentra retorna -1
	
	printf("\n%d",encontrado);
	
	return 0;
}
