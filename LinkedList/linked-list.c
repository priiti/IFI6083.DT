/*
 Linked list
 Priit Parl
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

void insert_into_position(struct node **head, int value, int position) {
    int i;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new -> data = value;
    new -> next = NULL;
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct node *temp = *head;
    for (i = 0; i < position - 2; i++) {
        temp = temp -> next;
    }
    new -> next = temp -> next;
    temp -> next = new;
}

void delete_from_position(struct node **head, int position) {
    int i;
    if (*head == NULL) {
        printf("No elements in list.\n");
    }
    struct node *temp1 = *head;
    if (position == 1) {
        *head = temp1 -> next;
        free(temp1);
        return;
    }
    struct node *temp2 = temp1 -> next;
    for (i = 0; i < position - 2; i++) {
        temp1 = temp1 -> next;
        temp2 = temp1 -> next;
    }
    temp1 -> next = temp2 -> next;
    free(temp2);
}

void pop(struct node **head) {
    if (*head == NULL) {
        printf("No elements to remove.\n");
        return;
    } else if ((*head) -> next == NULL) {
        *head = NULL;
        return;
    }
    struct node *temp1 = *head;
    struct node *temp2 = temp1 -> next;
    while (temp2 -> next != NULL) {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    free(temp2);
    temp1 -> next = NULL;
}

void push(struct node **head, int value) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new -> data = value;
    new -> next = NULL;

    if (*head == NULL) {
        *head = new;
        return;
    }
    struct node *temp = *head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = new;
}

int count(struct node **head) {
    int c = 0;
    if (*head == NULL) {
        return c;
    }
    struct node *temp = *head;
    while (temp != NULL) {
        c++;
        temp = temp -> next;
    }
    return c;
}

void print_list(struct node **head) {
    if (*head == NULL) {
        printf("No elements in list.\n");
        return;
    }
    struct node *temp = *head;
    printf("List elements are: ");
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}


int main() {
    struct node *head = NULL;
    int option, value, position;

    while (1) {
        printf("Choose option:\n");
        printf("1. Show list\n");
        printf("2. push() element into list\n");
        printf("3. pop() element from list\n");
        printf("4. List length\n");
        printf("5. Insert element into chosen position\n");
        printf("6. Delete element from chosen position\n");
        printf("0. Exit\n");

        scanf(" %d", &option);
        printf("\n");
        switch (option) {
            case 1:
                print_list(&head);
                break;
            case 2:
                printf("Enter element:\n");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 3:
                pop(&head);
                break;
            case 4:
                printf("List length is: %d\n", count(&head));
                break;
            case 5:
                printf("Enter element: ");
                scanf("%d", &value);
                printf("Enter position in list: ");
                scanf("%d", &position);
                insert_into_position(&head, value, position);
                break;
            case 6:
                printf("Enter position in list: ");
                scanf("%d", &position);
                delete_from_position(&head, position);
                break;
            case 0:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
