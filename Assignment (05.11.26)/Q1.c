/* Menu-Driven C Program for Doubly Linked List
The question asks us to write a menu-driven C program to perform the following operations on a Doubly Linked List:
Create a list.
Traverse the list in forward and reverse order.
Insert a node at the nth position.
Delete a node from the nth position.
Search for a specific item.*/
#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// Function to create a list
void create()
{
    struct node *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

// Function to traverse forward
void forward()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Forward: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Function to traverse backward
void backward()
{
    struct node *temp = tail;

    if(tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Backward: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

// Function to insert at nth position
void insert()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(pos == 1)
    {
        newnode->next = head;

        if(head != NULL)
            head->prev = newnode;
        else
            tail = newnode;

        head = newnode;
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;
    else
        tail = newnode;

    temp->next = newnode;
}

// Function to delete from nth position
void delete()
{
    struct node *temp;
    int pos, i;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        free(temp);
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
}

// Function to search an element
void search()
{
    struct node *temp = head;
    int item, pos = 1;

    printf("Enter item to search: ");
    scanf("%d", &item);

    while(temp != NULL)
    {
        if(temp->data == item)
        {
            printf("Item found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Item not found\n");
}

// Main function
int main()
{
    int choice;

    while(1)
    {
        printf("\n----- DOUBLY LINKED LIST MENU -----\n");
        printf("1. Create List\n");
        printf("2. Forward Traversal\n");
        printf("3. Backward Traversal\n");
        printf("4. Insert at Nth Position\n");
        printf("5. Delete from Nth Position\n");
        printf("6. Search an Element\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                insert();
                break;

            case 5:
                delete();
                break;

            case 6:
                search();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
