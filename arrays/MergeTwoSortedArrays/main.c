#include <stdio.h>
#include <stdlib.h>
/**
Merge two sorted arrays

"Given two sorted arrays, the task is to merge them in a sorted manner."
Examples:
Example 1
    Input:
    arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8}
    Output:
    arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}
Example 2
    Input:
    arr1[] = { 5, 8, 9}, arr2[] = {4, 7, 8}
    Output:
    arr3[] = {4, 5, 7, 8, 8, 9}
*/

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeArrays(int arr1[], int arr2[], int size1, int size2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i<size1 && j <size2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < size1)
        arr3[k++] = arr1[i++];

    while (j < size2)
        arr3[k++] = arr2[j++];
}

int main()
{
    /* test1 */
    int arr1[] = {1,3,4,5};
    int arr2[] = {2,4,6,8};

    /* test2
    int arr1[] = { 5, 8, 9};
    int arr2[] = {4, 7, 8};
    */

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr1[0]);

    int arr3[size1+size2];

    mergeArrays(arr1, arr2, size1, size2, arr3);
    printArray(arr3, size1+size2);

    return 0;
}
