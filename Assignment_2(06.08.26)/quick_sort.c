/*
WAP in c to take input in an array 10 unorder number and apply
Quick sort to order the array in ascending order
Sample input:[5,2,1,3,8,9,6,4,7,12]
*/
#include <stdio.h>
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int low, int high)
{
    int start = low;
    int end = high;
    int mid = start + (end - start) / 2;
    int pivot = arr[mid];

    while (start <= end) {
        while (arr[start] < pivot){
            start++;
        }
        while (arr[end] > pivot){
            end--;
        }
        if (start <= end){
            swap(arr, start, end);
            start++;
            end--;
        }
    }

    return start;
}
void quick_sort(int arr[], int low, int high){
    if (low >= high) {
        return;
    }

    int index = partition(arr, low, high);

    quick_sort(arr, low, index - 1);
    quick_sort(arr, index, high);
}
void display(int arr[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
int maximum(int arr[], int n){
return arr[n - 1];
}
int minimum(int arr[], int n){
 return arr[0];
}
int main(){
    int arr[] = {5, 2, 1, 3, 8, 9, 6, 4, 7, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    display(arr, n);
    printf("Highest number = %d\n", maximum(arr, n));
    printf("Lowest number = %d\n", minimum(arr, n));
    return 0;
}
