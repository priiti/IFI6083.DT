/*
 Põhiidee: Mööda massiivi liigutakse vasakult paremale. Vasakule tekib sorteeritud massiiv. Igal sammul otsitakse järgmise elemendi kohale õiget (suuruselt sobivat) arvu, mis ühtlasi on sorteerimata osa kõige väiksem arv.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void selectionSort(int *array, int length) {
    int min, i, j, temp;
    for (i = 0; i < length; i++) {
        min = i;
        for (j = i; j < length; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void printArray(int *array, int length) {
    int i;
    if (length == 0) {
        printf("Ei ole elemente!\n");
        return;
    }
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    
    int numbers[MAX], i, length;
    srand(time(0));
    
    for (i = 0; i < MAX; i++) {
        numbers[i] = rand() % 100;
    }
    
    length = sizeof(numbers) / sizeof(numbers[0]);
    
    printArray(numbers, length);
    
    selectionSort(numbers, length);
    
    printArray(numbers, length);
    
    return 0;
}
