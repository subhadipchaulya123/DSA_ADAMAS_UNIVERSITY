/*
reversing a delivary route using a single linked list 

A delivary comapany store its delivery stop in a singly list.Each node contain a stop number 
and a pointer to the next stop.After completing the deliveries the driver needs to stop displayed 
in reverser ordernfor the return journey.

TASK:WACP to create the route ,display it and reverse the singly linked list,and display
     reversed route

Example:
  original route : 101 -> 102 -> 103 -> 104 -> NULL
  Reversed route: 104 -> 103 -> 102-> 101 -> NULL 
*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int stopNumber;
    struct Node* next;
};
struct Node* createNode(int stopNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->stopNumber = stopNumber;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** head, int stopNumber) {
    struct Node* newNode = createNode(stopNumber);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->stopNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


int main() {
    struct Node* head = NULL;
    int stopNumber;

    printf("Enter delivery stops (-1 to stop): ");
    while (1) {
        scanf("%d", &stopNumber);
        if (stopNumber == -1) {
            break;
        }
        insertNode(&head, stopNumber);
    }
    printf("Original Route: ");
    displayList(head);
    reverseList(&head);
    printf("Reversed Route: ");
    displayList(head);

    return 0;
}