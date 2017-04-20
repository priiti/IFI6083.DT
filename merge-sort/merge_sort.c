// Mergesort

#include <stdio.h>
#include<stdlib.h>
#define N 7

void merge(int *array, int left, int middle, int right) {
    
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    // Ajutised massiivid
    int L[n1], R[n2];
    
    // Kopeeri andmed ajutistesse massiividesse
    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[middle + 1 + j];
    }
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

/*
 L on vasak indeks ja R on parem index sub- array off array, mida sortida
*/

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        // Keskpunkt
        int middle = left + (right - left) / 2;
        
        // Sorteeri esimesed ja teised pooled
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        
        merge(array, left, middle, right);
    }
}

void print_array(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int numbers[N] = {4, 6, 1, 3, 5, 7, -4};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    print_array(numbers, length);
    
    
    merge_sort(numbers, 0, length - 1);
    
    print_array(numbers, length);
    
    return 0;
}
