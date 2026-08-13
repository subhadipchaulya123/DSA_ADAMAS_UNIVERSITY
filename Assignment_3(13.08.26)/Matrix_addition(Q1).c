#include<stdio.h>
void input(int arr[10][10],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}
void addition(int a[10][10],int b[10][10],int sum[10][10],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
}
void display(int arr[10][10],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int row,coloumn;
    int arr1[10][10];
    int arr2[10][10];
    int sum[10][10];
    printf("Input row and column number:");
    scanf("%d %d" ,&row,&coloumn);
    printf("Enter first matrix:\n");
    input(arr1,row,coloumn);
    printf("Enter second matrix:\n");
    input(arr2,row,coloumn);

   
addition(arr1,arr2,sum,row,coloumn);
    
  printf("Answer=\n");
  display(sum,row,coloumn);
    return 0;
}