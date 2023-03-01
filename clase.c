#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000  // número de elementos en el vector

// Función para intercambiar dos elementos en un vector
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Algoritmo de ordenación de burbuja para ordenar el vector de números
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int nums[N];
    int i, max, min;
    clock_t start, end;
    double time_taken;

    // Inicializa la semilla del generador de números aleatorios
    srand(time(NULL));

    // Genera N números aleatorios y los almacena en el vector nums
    for (i = 0; i < N; i++) {
        nums[i] = rand() % 1000 + 1;  // genera un número aleatorio entre 1 y 1000
    }

    // Método 1: Algoritmo de ordenación de burbuja
    start = clock();
    bubbleSort(nums, N);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    max = nums[N-1];
    min = nums[0];
    printf("Método 1: Algoritmo de ordenación de burbuja\n");
    printf("Máximo: %d\nMínimo: %d\n", max, min);
    printf("Tiempo de ejecución: %f segundos\n", time_taken);


    // Genera N números aleatorios y los almacena en el vector nums
    for (i = 0; i < N; i++) {
        nums[i] = rand() % 1000 + 1;  // genera un número aleatorio entre 1 y 1000
    }

    // Método 2: Comparación secuencial
    start = clock();
    max = nums[0];
    min = nums[0];
    for (i = 1; i < N; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nMétodo 2: Comparación secuencial\n");
    printf("Máximo: %d\nMínimo: %d\n", max, min);
    printf("Tiempo de ejecución: %f segundos\n", time_taken);

    return 0;
}
