#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int array[],int n){
    int temp;
    //Bucle para recorrer el arreglo
    for (int i = 0; i < n-1; i++) {
        //Bucle interno para comparar elementos adyacentes
        for (int j = 0; j < n-i-1; j++) {
            //Si el elemento actual es mayor que el siguiente, se intercambian
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arreglo[], int n) {
    int minimo, temp;
    
    //Bucle para recorrer el arreglo
    for (int i = 0; i < n - 1; i++) {
        minimo = i;  //Esto asume que el primer elemeto es el mas pequeño para luego comparar
        
        //Bucle para encontrar el índice del elemento más pequeño en la parte no ordenada
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[minimo]) {
                minimo = j;  // Actualizamos el índice del mínimo
            }
        }
        
        //Intercambiamos el elemento mas pequeño encontrado con el primero no ordenado
        if (minimo != i) {
            temp = arreglo[i];
            arreglo[i] = arreglo[minimo];
            arreglo[minimo] = temp;
        }
    }
}
int main(){
    int tamano;
    printf("Digite el tamaño del arreglo:\n");
    scanf("%i",&tamano);
    int arreglo_1[tamano]; //matriz que se va a usar con bubble sort
    int arreglo_2[tamano]; //matriz que se va a usar con selection sort
    srand(time(NULL));
    //LLeno a ambas matrices con valores aleatorios
    for (int i = 0; i < tamano; i++){
        arreglo_1[i] = rand();
        arreglo_2[i] = arreglo_1[i];
    }
    /*printf("El arreglo generado es: \n");
    for (int i = 0; i < tamano; i++){
        printf("%d ",arreglo_1[i]);
    }*/
    printf("\n");
    clock_t start = clock();
    bubbleSort(arreglo_1,tamano);
    clock_t end = clock();
    double bubbleSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*printf("El arreglo ordenado con bubbleSort es: \n");
    for (int i = 0; i < tamano; i++){
        printf("%d ",arreglo_1[i]);
    }
    printf("\n");*/
    start = clock();
    selectionSort(arreglo_2,tamano);
    end = clock();
    double selectionSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    /*
    printf("El arreglo ordenado con Selection Sort es :\n");
    for (int i = 0; i < tamano; i++){
        printf("%d ",arreglo_2[i]);
    }
    printf("\n");*/
    //Imprimo los tiempos de ejecucion
    printf("Tiempo de ejecución de Bubble Sort: %.6f segundos\n", bubbleSortTime);
    printf("Tiempo de ejecución de Selection Sort: %.6f segundos\n", selectionSortTime);
    return 0;
}