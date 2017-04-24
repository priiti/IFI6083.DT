#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *fptr;
    
    char filename[100], c;
    
    printf("Sisesta failinimi: \n");
    scanf("%s", filename);
    
    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Ei saa faili avada \n");
        exit(0);
    }
    
    // Read contents
    c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }
    
    fclose(fptr);
    return 0;
}
