/*
bank account keeping the transaction amount as it is processd  by customer.
The transtion amount of last customer is stored at top possition .After completition 
of all transaction the manager pull teh amount one by one and display the amount and find 
total _transaction amount to print
Define the following function:
push():to insert amount in
pop():to remove amount
dosum():find sum of all tramsaction amount

amount to be inserted in following order:1050,2090,3000,6000,5500,8900
*/

#include <stdio.h>
#define MAX 3

void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) {
        printf("Stack is overflow\n");
        return;
    }
    (*top)++;
    stack[*top] = value;
    printf("%d amount credited in bank account\n", value);
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("0 rupees present in the bank account\n");
        return -1;
    }
    int x = stack[*top];
    (*top)--;
    return x;
}

int peek(int stack[], int top) {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}

int isEmpty(int top) {
    return top == -1;
}

int isFull(int top) {
    return top == MAX - 1;
}

int dosum(int stack[], int top) {
    int sum = 0;
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    return sum;
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;
    do {
        printf("\nSTACK MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. dosum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            case 2:
                value = pop(stack, &top);
                if (value != -1) {
                    printf("%d popped\n", value);
                }
                break;
            case 3:
                value = peek(stack, top);
                if (value == -1) {
                    printf("Stack is Empty\n");
                } else {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                printf("%d is total amount\n", dosum(stack, top));
                break;
            case 5:
                display(stack, top);
                break;
            case 6:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    
    return 0;
}
