/*
       _______________________________________________________
     / \                                                      \.
    |   |    + Titulo: Busqueda Lineal                        |.
    \_  |    + Author: Luis Fernando Resendiz Chavez          |.
        |    + Version: 1.0                                   |.
        |    + Fecha: 20 noviembre 2020                       |.
        |    + Descripcion:                                   |.
        |       Buscar un elemento en un arreglo utilizando   |.
        |       el algoritmo de busqueda lineal.              |.
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
int busquedaLineal(int n, int *A, int x);

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

    // Se ejecuta la funcion busquedaLineal y se imprime dependiendo el resultado =^..^= */
    busquedaLineal(n, A, x) ?
        printf("YES\n") : printf("NO\n");
    return  0;
}


/* =^..^= *** =^..^= ***** FUNCION BUSQUEDA LINEAL ***** =^..^= *** =^..^= */
int busquedaLineal(int n, int *A, int x) {
    // Se crea una variable iteradora =^..^= */
    int i;
    // Se comparan todas las posiciones del arreglo en busca del elemento x =^..^= */
    for(i = 0; i < n; ++i)
        // Si lo encontramos, retornamos TRUE =^..^= */
        if(A[i] == x)
            return TRUE;

    // Si no lo encontramos, retornamos FALSE =^..^= */
    return FALSE;
}