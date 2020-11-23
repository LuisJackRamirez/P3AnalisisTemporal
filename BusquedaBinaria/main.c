/*
       _______________________________________________________
     / \                                                      \.
    |   |    + Titulo: Busqueda Binaria                       |.
    \_  |    + Author: Luis Fernando Resendiz Chavez          |.
        |    + Version: 1.0                                   |.
        |    + Fecha: 20 noviembre 2020                       |.
        |    + Descripcion:                                   |.
        |       Buscar un elemento en un arreglo utilizando   |.
        |       el algoritmo de busqueda binaria.             |.
        |    + Entrada:                                       |.
        |       - Arreglo de numeros enteros                  |.
        |       - Longitud de dicho arreglo                   |.
        |       - Elemento a buscar                           |.
        |    + Salida:                                        |.
        |       - SI: en caso de que el elemento SI           |.
        |           haya sido encontrado en el arreglo.       |.
        |       - NO: en caso de que el elemento NO           |.
        |           haya sido encontrado en el arreglo.       |.
        |   __________________________________________________|___
        |  /                                                     /.
        \_/_____________________________________________________/.
*/


/* =^..^= *** =^..^= ***** LIBREARIAS UTILIZADAS ***** =^..^= *** =^..^= */
#include <stdio.h>
#include <stdlib.h>

/* =^..^= *** =^..^= ***** DEFINICIONES ***** =^..^= *** =^..^= */
#define TRUE 1
#define FALSE 0

/* =^..^= *** =^..^= ***** PROTOTIPOS DE FUNCIONES ***** =^..^= *** =^..^= */
int busquedaBinaria(int n, int* A, int x);

/* =^..^= *** =^..^= ***** FUNCION PRINCIPAL ***** =^..^= *** =^..^= */
int main() {
    // Se crean n para el tamano del arreglo, x elemento a buscar y un iterador =^..^= */
    int n, x, i;
    // Se reciben dichas variables =^..^= */
    scanf("%d %d", &n, &x);
    // Se crea un arreglo dinamico de n elementos enteros =^..^= */
    int *A = malloc(sizeof(int) * n);
    // Se reciben los datos del arreglo =^..^= */
    for(i = 0; i < n; ++i)
        scanf("%d", &A[i]);

    // Se ejecuta la funcion busquedaBinaria y se imprime dependiendo el resultado =^..^= */
    busquedaBinaria(n, A, x) ?
        printf("YES\n") : printf("NO\n");
    return 0;
}


/* =^..^= *** =^..^= ***** FUNCION BUSQUEDA BINARIA ***** =^..^= *** =^..^= */
int busquedaBinaria(int n, int* A, int x) {
    // Se crean dos apuntadores a la primera y ultima posicion del arreglo actual =^..^= */
    int left = 0;
    int right = n-1;
    // Mientras la izq sea menor que la der ejecutamos el while =^..^= */
    while(left <= right) {
        // Obtenemos la posicion del elemento en el centro del arreglo =^..^= */
        int mid = left + (right - left) / 2;
        // Si el elemento en esa posicion es igual al que estamos buscando retornamos TRUE =^..^= */
        if(A[mid] == x)
            return TRUE;
        // Si es menor actualizamos el auntador izq, si es mayor actualizamos el apuntador der =^..^= */
        (A[mid] < x) ?
            (left = mid + 1) : (right = mid - 1);
    }

    // Si no enccontramos el elemento retornamos FALSE =^..^= */
    return FALSE;
}