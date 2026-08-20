/*WAP in c where A single cinema hall has one ticket counter .one customer arrives at a time.
Simulate the ticket counter using queue.
The requriment are :
1.Add customer 2.Serve customer 3.Show "housefull" if the seats are full 
4.Display the all customer
*/
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void Enqueue(){
    int customer;
    if (rear == MAX - 1){
        printf("No more seats available.\n");
        return;
    }
    printf("Enter customer number: ");
    scanf("%d", &customer);
    // if (front == -1)
    // front = 0;
    rear++;
    queue[rear] = customer;
    printf("Customer %d added successfully.\n", customer);
}
void Dequque(){
    if (front == -1 || front > rear){
        printf("No customer to serve.\n");
        return;
    }
    printf("Customer %d served.\n", queue[front]);
    front++;
    if (front > rear){
        front = -1;
        rear = -1;
    }
}
void Display(){
    int i;
    if (front == -1){
        printf("No customers in queue.\n");
        return;
    }
    printf("Customers in queue:\n");
    for (i = front; i <= rear; i++){
        printf("%d\n", queue[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    while (1){
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display All Customers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                Enqueue();
                break;
            case 2:
                Dequque();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}