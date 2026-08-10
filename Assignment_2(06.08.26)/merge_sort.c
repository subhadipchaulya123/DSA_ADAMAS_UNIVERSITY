/*
WAP in c to take input marks of ten student randomly in an array sort 
the array using merge sort and show the highest and lowest marks
sample case:[80,73,59,92,86,47,92,58,91,48]
*/

#include<stdio.h>
#include <stdlib.h>
void merge(int arr[],int start,int mid,int end);
void merge_sort(int arr[],int start,int end){
if(start==end){
    return ;
}
int mid=start+(end-start)/2;
merge_sort(arr,start,mid);
merge_sort(arr,mid+1,end);
merge(arr,start,mid,end);

}
void merge(int arr[],int start,int mid,int end){
   int size = end - start + 1;
 int *temp = (int *)malloc(size * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
 int left=start,right=mid+1,index=0;
 while(left<=mid && right <=end){
    if(arr[left]<=arr[right]){
        temp[index]=arr[left];
        index++;
        left++;
    }
    else{
        temp[index]=arr[right];
        index++;
        right++;
    }
 }
 while (left <= mid){
        temp[index] = arr[left];
        index++;
        left++;
 }
    while (right <= end){
        temp[index] = arr[right];
        index++;
        right++;
    }
    for (int i = 0; i < index; i++){
      arr[start + i] = temp[i];

    }
}
int main()
{
    int arr[] = {80,73,59,92,86,47,99,58,91,48};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
  printf("\nHighest number=%d\n",arr[n-1]);
  printf("Lowest number=%d\n",arr[0]);
    return 0;
}
