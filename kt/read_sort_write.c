#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    FILE *fptr;
    
    char filename[100], c;
    
    printf("Sisesta failinimi:\n");
    scanf("%s", filename);
    
    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Faili ei saa avada.\n");
        exit(0);
    }
    
    // Read contents
    c = fgetc(fptr);
    while (c != EOF) {
        numbers[i] = c;
        printf("%c", c);
        c = fgetc(fptr);
    }
    
    return 0;
}
