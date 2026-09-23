/*
In a shop the product price of 5 product are stored in a list .
the price is stored in float/double.Each node consist of one product and address of next 
perform the fpllowing operation an the list in meanudriven from


1)Create a list of 5 product prices.
2)Traverse/display the list.
3)Search for a price entered by the user.
4)Find the minimum price and insert it at the head. Example: 65.25
5)Insert a new price at the 3rd position. Example: 102.10
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    double price;
    struct node*next;
};

struct node * head=NULL;

void create_list(){
    int n;
    double price;
    struct node *newnode, *temp;
    printf("Enter the number of product:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
     newnode = (struct node *)malloc(sizeof(struct node));
     printf("Enter price %d:",i+1);
     scanf("%lf", &price);
     newnode->price = price;
     newnode->next = NULL;

     if(head==NULL){
     head=newnode;
     }
     else{
        temp=head;
        while(temp -> next != NULL){
           temp=temp->next; 
        }
        temp ->next=newnode;
     }
    }
}
void traverse(){
    struct node * temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return ;
    }
    printf("Product Price:\n");
      while(temp != NULL) {
        printf("%.2lf -> ", temp->price);
        temp = temp->next;
    }
   printf("NULL\n");
}
void search_price(){
    double key;
    int pos=1;
    struct node * temp =head;
    printf("Enter price to search:");
    scanf("%lf",&key);
    while(temp != NULL){
        if(temp ->price == key){
         printf("Product price %0.2lf found at %d possition\n",key,pos);
         return ;
        }
    temp = temp->next;
    pos++;
    }
   printf("Price not found\n");
}
void insert_head(){
 double price;
    struct node *newnode;
    printf("Enter new price: ");
    scanf("%lf", &price);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->price = price;
    newnode->next = head;
    head = newnode;
    printf("Price %.2lf inserted at the head.\n", price);
}
void insert_third(){ 
    double price;
    struct node *newNode, *temp;
    printf("Enter price to insert at 3rd position: ");
    scanf("%lf", &price);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->price = price;
    temp = head;
    for(int i = 1; i < 2; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Price %.2lf inserted at 3rd position\n", price);
}
int main(){
    int choice;
    do{
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Search Price\n");
        printf("4. Insert Minimum at Head\n");
        printf("5. Insert Price at 3rd Position\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_list();
                break;

            case 2:
               traverse();
               break;

            case 3:
               search_price();
               break;

            case 4:
               insert_head();
               break;

            case 5:
               insert_third();
               break;

            case 6:
              printf("Exiting\n");
              break; 

            default:
              printf("Invalid choice\n");
        }

    } while(choice != 6);

    return 0;
}
















