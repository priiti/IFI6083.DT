// KT harjutus

#include <stdio.h>
#include <stdlib.h>

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
    while (temp-> next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

int count(struct node **head) {
    int count = 0;
    if (*head == NULL) {
        printf("Listis ei ole elemente.");
        return count;
    }
    struct node *temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
        printf("tere");
    }
    return count;
}

void printList(struct node **head) {
    struct node *temp = *head;
    if (*head == NULL) {
        printf("Listis ei ole elemente.");
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

float average(struct node **head) {
    float count = 0;
    float sum = 0;
    float average;
    struct node *temp = *head;
    while (temp != NULL) {
        if (temp->data % 3 == 0) {
            sum += temp->data;
            count++;
            temp = temp->next;
        }
    }
    average = sum / count;

    return average;
}


int main() {
    struct node *head = NULL;
    
    int n, i, input, elements;
    printf("Mitu arvu soovid sisestada?\n");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Sisesta arv: ");
        scanf("%d", &input);
        push(&head, input);
    }
    
    printList(&head);
    printf("\n");
    
    elements = count(&head);
    
    if (elements != 0) {
        printf("Keskmine on %0.2f\n", average(&head));
    } else {
        printf("Keskmist ei saa leida!");
    }
    
    return 0;
}
