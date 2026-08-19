/* 
consider a book rack,where books are placed in stack.Each book has acc_no
(1,2,3,4........)if you one asked to place book in stack using acc_no
have you performe these operation on stack of books.the sequence of operation
push(1),push(2),push(3),push(4),pop(4),push(5),pop(5) display the final position of books
*/
#include <stdio.h>

#define MAX 5

void push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    (*top)++;
    stack[*top] = value;

    printf("%d pushed into stack\n", value);
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int x = stack[*top];
    (*top)--;

    return x;
}

void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are: ");

    for (int i = *top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    printf("\n");
}

int main()
{
    int choice, acc_no;
    int stack[MAX];
    int top = -1;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Accession Number: ");
                scanf("%d", &acc_no);
                push(stack, &top, acc_no);
                break;

            case 2:
                acc_no = pop(stack, &top);

                if (acc_no != -1)
                    printf("%d popped from stack\n", acc_no);

                break;

            case 3:
                display(stack, &top);
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
