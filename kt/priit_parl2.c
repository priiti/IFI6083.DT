#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main() {

    int numbers1[100];
    int numbers2[100];
    
    char answer[5];
    int n = 0;
    int x1 = 0;
    int value, x2;
    int i = 0;
    float percent1, percent2;
    
    strcpy(answer, "jah");
    
    while (strcmp(answer, "jah") == 0) {
        n++;
        printf("Sisesta arv: \n");
        scanf("%d", &numbers1[i]);
        printf("Kas soovid veel? [jah / ei]\n");
        scanf("%s", answer);
        i++;
    }
    
    print_array(numbers1, n);
    
    for (i = 0; i < n; i++) {
        if (numbers1[i] % 2 == 0) {
            numbers2[x1] = numbers1[i];
            x1++;
        }
    }
    x2 = n - x1;
    
    percent1 = (float)x1 / n * 100;
    percent2 = (float)x2 / n * 100;
    printf("\n");
    
    printf("Sisestatud arvudest oli %0.2f protsenti paaris arvud.\n", percent1);
    printf("Sisestatud arvudest oli %0.2f protsenti paaritud arvud.\n", percent2);
    
    printf("Sisestatud paarisarvud on:\n");
    print_array(numbers2, x1);
    
    return 0;
}



