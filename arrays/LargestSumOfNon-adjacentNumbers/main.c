#include <stdio.h>
#include <stdlib.h>

/*
Largest sum of non-adjacent numbers

"Given an array arr[] of positive numbers, the task is to find the maximum sum of a subsequence such that
no 2 numbers in the sequence should be adjacent in the array."

Examples:

Input: arr[] = {5, 5, 10, 100, 10, 5}
Output: 110

Input: arr[] = {3, 2, 7, 10}
Output: 13

Input: arr[] = {3, 2, 5, 10, 7}
Output: 15

*/

#define max(a,b) (a > b ? a : b)

int maximumSum(int* arr, int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];
    if (size == 2)
        return max(arr[0], arr[1]);

    int m[size];

    m[0] = arr[0];
    m[1] = max(arr[0], arr[1]);

    for (int i = 2; i < size; i++)
    {
        m[i] = max(m[i - 1], arr[i] + m[i - 2]);
    }
    return m[size - 1];
}

int main()
{
    /*test1 */
    int arr[] = {5, 5, 10, 100, 10, 5};

    /*test2
    int arr[] = {3, 2, 7, 10};
    */

    /*test3
    int arr[] = {3, 2, 5, 10, 7};
    */
    int n = sizeof(arr) / sizeof(int);

    printf("%d\n", maximumSum(arr, n));

    return 0;
}
