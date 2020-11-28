//*****************************************************************
//EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//ESCUELA SUPERIOR DE CÓMPUTO - IPN
//(C) Marzo 2013
//Ejemplo del empleo de Threads
//Compilación: ""gcc -lm -lpthread -o ejemplo_thread ejemplo_thread.c"
//Ejecución: "./ejemplo_thread 4"
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads;			//Número de threads
int N, x, ans = 0;

//********************************************************************************
//COMPORTAMIENTO DE LOS THREADS
//********************************************************************************

//********************************************************************************
//1 Saludar 
//********************************************************************************
void* saludar(void* id)
{
	printf("\nHola desde Saludar\tSoy el thread %d",(int)id);
}

//********************************************************************************
//2 Realizar un procesamiento
//********************************************************************************
void* procesar(void* id)
{	
	int n_thread=(int)id;
	int inicio,fin,i,a;

	//Revisar la parte de los datos a procesar	
	inicio=(n_thread*N)/NumThreads;
	if(n_thread==NumThreads-1)	
		fin=N;
	else
		fin=((n_thread+1)*N)/NumThreads-1;

	printf("\nHola desde procesar\tSoy el thread %d\tInicio %d\tTermino %d",n_thread,inicio,fin);
	for(i=inicio;i<=fin;i++)
		a=i*i;		
		//printf("\nProcesando dato %d",i);

	printf("\nBye desde procesar\tSoy el thread %d\tHe terminado",n_thread);

}

void buscar(int* arr, x) {
    for(int i = 0; i < N/2; ++i)
        if(arr[i] == x)
            ans = 1;
}
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i,j,k; 	//Variables auxiliares para loops
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************	
	
	//********************************************************************************
	//Obtener el número de threads a usar y el arreglo para la identificacion de los mismos
	//********************************************************************************
	pthread_t *thread;

	NumThreads = 2;
	thread = malloc(NumThreads*sizeof(pthread_t));
	scanf("%d %d", &N, &x);

    int *a;
    int *b;
    a = malloc(sizeof(int) * N/2);
    b = malloc(sizeof(int) * N/2);

    for(int i = 0; i < N/2; ++i) {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
    }


	//***************************************************************************************************************************
	//1 Saludar desde cada hilo "saludar"
	//***************************************************************************************************************************
	//Crear los threads con el comportamiento "segmentar"
	pthread_create (&thread[1], NULL, buscar, b, x);
	
	//El main ejecuta el thread 0
	buscar(a, x);
	
	//Esperar a que terminen los threads (Saludar)
	pthread_join (thread[1], NULL);
				
	if(ans)
        printf("SI\n");
    else
        printf("NO\n");

	uswtime(&utime1, &stime1, &wtime1);
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	exit (0);	
}
