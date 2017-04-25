#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **head, int value) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    
    if (*head == NULL) {
        *head = new;
        return;
    }
    
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

bool checkModulus(int value) {
    if (value % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

void print_list(struct node **head) {
    if (*head == NULL) {
        printf("Listis ei ole elemente.\n");
        return;
    }
    struct node *temp = *head;
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    struct node *numbers1 = NULL;
    struct node *numbers2 = NULL;
    char answer[5];
    int n = 0;
    int x1 = 0;
    int value, x2;
    float percent1, percent2;
    
    strcpy(answer, "jah");
    
    while (strcmp(answer, "jah") == 0) {
        n++;
        printf("Sisesta arv: \n");
        scanf("%d", &value);
        push(&numbers1, value);
        printf("Kas soovid veel? [jah / ei]\n");
        scanf("%s", answer);
    }
    
    print_list(&numbers1);
    
    struct node *temp = numbers1;
    while (temp != NULL) {
        if (checkModulus(temp->data)) {
            push(&numbers2, temp->data);
            x1++;
        }
        temp = temp->next;
    }
    x2 = n - x1;
    percent1 = (float)x1 / n * 100;
    percent2 = (float)x2 / n * 100;
    
    printf("Paaris arvude protsent on %0.3f\n", percent1);
    printf("Paaritute arvude protsent on %0.3f\n", percent2);
    
    printf("Paaris arvud on: ");
    print_list(&numbers2);
    
    
    
    return 0;
}



