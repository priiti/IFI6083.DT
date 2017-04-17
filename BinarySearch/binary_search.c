#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUES 999

// Binary search
void binary_search(int *array, int length, int value_to_find) {
    int first, last, middle;
    first = 0; // Massiivi esimene element
    last = length - 1; // Massiivi viimane element
    middle = (first + last) / 2; // Massiivi keskkoht
    
    // While tsykkel kestab, kuni esimene on v2iksem v v6rne viimasega.
    // Nt: 0 kuni 16...1, 2, 3...16
    while (first <= middle) {
        // Keskmine on v2iksem, kui otsitav
        if (array[middle] < value_to_find) {
            first = middle + 1; // Uus algus on keskpunkt + 1
        } else if (array[middle] == value_to_find) { // keskpunkt == otsitav
            printf("Otsitav %d leitud kohal %d.\n", value_to_find, middle + 1);
            break; // Leitud, v2ljume while tsyklist
        } else {
            // otsitav on keskmisest v2iksem
            // uus viimane element on keskmine - 1
            last = middle - 1;
        }
        // uus keskmine = (uus) algus v6i (uus l6pp) / 2
        // tsykkel algab uuesti samal p6him6ttel
        middle = (first + last) / 2;
    }
    // oleme otsinud kogu massiivist, aga elementi ei leitud
    if (first > last) {
        printf("Otsitavat %d ei leitud listist.\n", value_to_find);
    }
}

// Selection sort
void selection_sort(int *array, int length) {
    int i, j, current_min, temp;
    
    for (i = 0; i < length; i++) {
        current_min = i;
        for (j = i; j < length; j++) {
            if (array[j] < array[current_min]) {
                current_min = j;
            }
        }
        temp = array[i];
        array[i] = array[current_min];
        array[current_min] = temp;
    }
}

// O(n log n) - average; O(n2) - worst case
void quicksort(int *array, int first, int last) {
    int i, j, pivot, temp;
    // Sorteerime, kui esimene massiivis on elemente
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        
        while (i < j) {
            while (array[i] <= array[pivot] && i < last) {
                i++;
            }
            while (array[j] > array[pivot]) {
                j--;
            }
            if (i < j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quicksort(array, first, j - 1);
        quicksort(array, j + 1, last);
    }
}

void print_array(int *array, int length) {
    int i;
    printf("Arvud on: ");
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    
    int numbers[MAX_VALUES];
    int i, n, searchable;
    srand(time(0));
    
    printf("Mitu numbrit soovid lisada?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        numbers[i] = rand() % MAX_VALUES; // random 0 - 99
    }
    
    print_array(numbers, n);
    printf("\n");
    printf("Sorteeritud arvud on:\n");
    quicksort(numbers, 0, n - 1);
    //selection_sort(numbers, n - 1);
    print_array(numbers, n);
    
    // Otsitav
    printf("Sisesta otsitav number:\n");
    scanf("%d", &searchable);
    
    binary_search(numbers, n - 1, searchable);
    // print_array(numbers, n);
    
    return 0;
}
