#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 255

/*
 void *memset(void *str, int c, size_t n)
 str- pointer block for memory fill
 c- value to be set, andmed saadetakse int, aga konverteeritakse char
 n- number of bytes to be set to the value
 
 */

//Funktsioon paneb etteantud stringi 6igesse j2rjekorda
void countSort(char *array) {
    
    // Output character array, mis sorteeritakse
    char output[strlen(array)];
    
    // Count array individuaalsete karakterite loendamiseks
    // Count array 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    
    // Salvesta iga karakteri arv (loenda)
    for (i = 0; array[i]; i++) {
        ++count[array[i]];
    }
    
    // Muuda count[i] seni, kuni count [i] sisaldab tegelikku positsioon
    // outputis
    for (i = 1; i <= RANGE; i++) {
        count[i] += count[i - 1];
    }
    
    // Output array
    for (i = 0; array[i]; i++) {
        output[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }
    
    // Kopeeri output array array'sse, et seal oleks sorteeritud karakterid
    for (i = 0; array[i]; i++) {
        array[i] = output[i];
    }
}

int main() {
    char array[] = "teremaolenvarstikoolis";
    
    countSort(array);
    
    printf("Sorteeritud character array on %s\n", array);
    
    return 0;
}
