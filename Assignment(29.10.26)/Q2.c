/*
Consider an excisting doubly link list ans dekete an item from given possition
2->6->9->13 
delete form possition 3 and print resultentlist

output:2->6->13
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void deleteNodeAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    Node* current = *head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position %d is out of range.\n", position);
        return;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    current->prev->next = current->next;
    free(current);
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = createNode(2);
    head->next = createNode(6);
    head->next->prev = head;
    head->next->next = createNode(9);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(13);
    head->next->next->next->prev = head->next->next;

    printf("Original list: ");
    printList(head);

    deleteNodeAtPosition(&head, 3);

    printf("List after deletion: ");
    printList(head);

    return 0;
}
