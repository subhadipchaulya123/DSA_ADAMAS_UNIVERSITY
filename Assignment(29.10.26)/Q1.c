/*
consider an existsing dubly linklist 6->2->8->->4 
write a finction to input node woth value 12 between 2nd and 3rd node

output:6->2->12->8->4
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertBetween(struct Node** head, int value, int after) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == after) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Node with value %d not found.\n", after);
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(6);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(8);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Original list: ");
    printList(head);

    insertBetween(&head, 12, 2);

    printf("List after insertion: ");
    printList(head);

    return 0;
}
