#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int left,int mid,int right) {
    //write your code here..
    int n = right-left+1;
    int temp[n];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    for(i=0;i<n;i++)
        arr[left+i] = temp[i];
}

void mergeSort(int arr[], int left, int right) {
    //write your code here..
    if(left >= right)
        return;
    int mid = (left + right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}