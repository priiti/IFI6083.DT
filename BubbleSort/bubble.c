/*
 Põhiidee: Omavahel võrreldakse paarikaupa kirjeid. Kui kaks kõrvuti asetsevat kirjet on vales järjekorras, tuleb nad vahetada. Peale ühekordset massiivi läbimist ei pruugi veel kõik kirjed paigas olla, kuid suurim on kindlasti sattunud viimasele positsioonile, st oma õigele kohale.
 
 Keerukus: Halvimal juhul O(n2), parimal juhul O(n), keskmiseks loetakse siiski O(n2).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 25

void bubbleSort(int *array, int length) {
    int next, start, changes, i, temp;
    next = 0;
    changes = true;
    while (next < length && changes) {
        changes = false; // changes n2itab, kas vahetusi toimus
        for (i = 0; i < length - next; i++) {
            if (array[i] > array[i + 1]) {
                changes = true;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        next += 1;
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
    
    bubbleSort(numbers, length);
    
    printArray(numbers, length);
    
    return 0;
}
