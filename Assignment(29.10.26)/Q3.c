/*
Polinomial expression

define a structure of a node with present polinomial linked list


write a programe to perform addition of  2 polinomial using linked list and show the resultent list
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node* createNode(int c, int e)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}
void insert(struct node **head, int c, int e)
{
    struct node *newNode = createNode(c, e);
    struct node *temp;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        head = head->next;

        if (head != NULL)
            printf(" + ");
    }

    printf("\n");
}
struct node* addPolynomial(struct node *p1, struct node *p2)
{
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            insert(&result, p1->coeff + p2->coeff, p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else
        {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}
int main()
{
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *result = NULL;
    insert(&poly1, 5, 3);
    insert(&poly1, 4, 2);
    insert(&poly1, 2, 1);
    insert(&poly1, 7, 0);
    insert(&poly2, 3, 3);
    insert(&poly2, 2, 2);
    insert(&poly2, 6, 1);
    insert(&poly2, 5, 0);

    printf("First Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = addPolynomial(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
