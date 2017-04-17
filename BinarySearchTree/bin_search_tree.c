/* Viitadega kahendotsimispuu */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_VALUES 200

/* Kahendotsimispuu kujutatuna (Funktsionaalsused: lisamine ehk ehitamine, otsimine, kustutamine)
         (25)
       /       \
    (19)       (60)
   /   \      /   \
 (12)   (21)(41)  (63)
 
 */


// S6lme struktuur
// Lahtiseletatuna: sõlmes on kaks viidavälja (left ja right) ja täisarvuline võtmeväli (key).
struct node {
    int key;
    struct node *left, *right;
};

// Puu ehitamine ja lisamine andmeid etteantud massivist
// n - puu s6lmede (node) arv
//struct node *createTree(int n) {
//    struct node *new;
//    int nLeft, nRight;
//    if (n == 0) {
//        return NULL;
//        // kui lisatavate sõlmede arv on jõudnud 0-ni,
//        // tuleb tegevus pooleli jätta
//    } else {
//        nLeft = n / 2;
//        nRight = n - nLeft - 1;
//        
//        new = (struct node*)malloc(sizeof(node));
//        new->key = data[i];
//        i++;
//        new->left = NULL;
//        new->right = NULL;
//        new->left = createTree(nLeft);
//        new->right = createTree(nRight);
//        
//        return new;
//    }
//}

/*  Protseduur läbib etteantud puu inorder-järjekorras
 *  Protseduuri sisendiks on ühe sõlme aadress, esialgu ilmselt juure,
 *  järgmistel väljakutsetel  juba teiste sõlmede oma.
 */
struct node *search(struct node *node, int valueToFind) {
    if (node == NULL || node->key == valueToFind) {
        return node;
    }
    
    // Kui otsitav on suurem, kui juure v22rtus
    if (node->key < valueToFind) {
        return search(node->right, valueToFind);
    } else {
        return search(node->left, valueToFind); // Kui otsitav on v2iksem, kui juure v22rtus
    }
}

void Inorder(struct node *current) {
    if (current->left != NULL) {
        Inorder(current->left);
    }
    printf("%d ", current->key);
    if (current->right != NULL) {
        Inorder(current->right);
    }
}

// Loome uue s6lme, mille saame puusse lisada
struct node *newNode(int value) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    
    new->key = value;
    new->left = NULL;
    new->right = NULL;
    return new;
    
}

// Lisame uue s6lme puusse
struct node *insertIntoTree(struct node *node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    
    // V2iksem, liigume vasakule poole
    if (data < node->key) {
        node->left = insertIntoTree(node->left, data);
    } else if (data > node->key) { // Kui suurem, liigume paremale
        node->right = insertIntoTree(node->right, data);
    }
    return node;
}

int main() {
    int i, n, valueToFind;
    srand(time(0));
    
    printf("Kui palju numbreid lisame (random numbrid 0 - MAX_VALUES)?\n");
    scanf("%d", &n);
    int data[n];
    
    for (i = 1; i < n; i++) {
        data[i] = rand() % MAX_VALUES; // Random numbrid 0 - MAX_VALUES vahemik
    }
    
    struct node *root = NULL;
    root = insertIntoTree(root, 40);
    
    for (i = 1; i < n; i++) {
        insertIntoTree(root, data[i]);
    }
    
    Inorder(root);
    
    printf("\n");
    printf("Sisesta otsitav v22rtus:\n");
    scanf("%d", &valueToFind);
    
    if (search(root, valueToFind)) {
        printf("V22rtus %d leitud!\n", valueToFind);
    } else {
        printf("V22rtust %d ei leitud!\n", valueToFind);
    }
    return 0;
}
