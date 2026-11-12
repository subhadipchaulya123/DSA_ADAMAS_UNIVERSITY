#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct node *create(int c, int p)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->coeff = c;
    newnode->pow = p;
    newnode->next = NULL;

    return newnode;
}

// Insert node at the end
void insert(struct node **head, int c, int p)
{
    struct node *newnode = create(c, p);
    struct node *temp;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

// Add two polynomials
struct node *add(struct node *p1, struct node *p2)
{
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            insert(&result, p1->coeff + p2->coeff, p1->pow);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            insert(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else
        {
            insert(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insert(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insert(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

// Display polynomial
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->pow);

        head = head->next;

        if (head != NULL)
            printf(" + ");
    }

    printf("\n");
}

int main()
{
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    struct node *result = NULL;

    // First polynomial: 3x^3 + 2x^2 + 5
    insert(&p1, 3, 3);
    insert(&p1, 2, 2);
    insert(&p1, 5, 0);

    // Second polynomial: 4x^2 - 2
    insert(&p2, 4, 2);
    insert(&p2, -2, 0);

    printf("First Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    result = add(p1, p2);

    printf("Sum of Polynomials: ");
    display(result);

    return 0;
}
