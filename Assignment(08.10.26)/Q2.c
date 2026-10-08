/*
Q.8.2.
Train coaches using Doubly Linked List:   
A railway system stores the coaches of a train in a doubly linked list. 
Each coach has a coach number and link to both previous and next coaches. 
This allows the railway staff to inspect the coaches from the engine towards 
the last coach and from the last coach back towards the engine.   

Task: — Write a C Program (WACP) to:   
i) Create a doubly linked list of coach numbers.   
ii) Traverse and display the coaches in forward order.   
iii) Traverse and display the coaches in backward order.  
*/

#include <stdio.h>
#include <stdlib.h>
struct Coach {
    int coachNumber;
    struct Coach *prev;
    struct Coach *next;
};
struct Coach* createCoach(int coachNumber) {
    struct Coach* newCoach = (struct Coach*)malloc(sizeof(struct Coach));
    if (newCoach == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newCoach->coachNumber = coachNumber;
    newCoach->prev = NULL;
    newCoach->next = NULL;
    return newCoach;
}
void insertCoach(struct Coach** head, int coachNumber) {
    struct Coach* newCoach = createCoach(coachNumber);
    if (*head == NULL) {
        *head = newCoach;
    } else {
        struct Coach* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCoach;
        newCoach->prev = temp;
    }
}
void displayForward(struct Coach* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Coach* temp = head;
    printf("Forward traversal:\n");
    while (temp != NULL) {
        printf("%d ", temp->coachNumber);
        temp = temp->next;
    }
    printf("\n");
}
void displayBackward(struct Coach* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Coach* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Backward traversal:\n");
    while (temp != NULL) {
        printf("%d ", temp->coachNumber);
        temp = temp->prev;
    }
    printf("\n");
}
void freeList(struct Coach* head) {
    struct Coach* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Coach* head = NULL;
    insertCoach(&head, 1);
    insertCoach(&head, 2);
    insertCoach(&head, 3);
    insertCoach(&head, 4);
    insertCoach(&head, 5);
    displayForward(head);
    displayBackward(head);
    freeList(head);
    
    return 0;
}