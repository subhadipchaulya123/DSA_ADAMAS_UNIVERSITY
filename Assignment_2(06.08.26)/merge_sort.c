/*
WAP in c to take input marks of ten student randomly in an array sort 
the array using merge sort and show the highest and lowest marks
sample case:[80,73,59,92,86,47,92,58,91,48]
*/

#include <stdio.h>

void merge(int arr[], int start, int mid, int end)
{
    int temp[100];
    int left = start;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] < arr[right])
        {
            temp[k] = arr[left];
            left++;
        }
        else
        {
            temp[k] = arr[right];
            right++;
        }
        k++;
    }

    while (left <= mid)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }

    while (right <= end)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        arr[start + i] = temp[i];
    }
}

void merge_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[10] = {80, 73, 59, 92, 86, 47, 99, 58, 91, 48};

    int n = 10;

    merge_sort(arr, 0, n - 1);

    printf("Sorted marks: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nLowest marks = %d", arr[0]);
    printf("\nHighest marks = %d\n", arr[n - 1]);

    return 0;
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
