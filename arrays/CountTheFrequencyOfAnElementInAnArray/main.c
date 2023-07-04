#include <stdio.h>
/**
"Count the frequency of an element in an array"
Given an array which may contain duplicates, print all elements and their frequencies.
Examples:
Example 1
Input:  arr[] = {10, 20, 20, 10, 10, 20, 5, 20}
Output: 10 3
        20 4
        5  1
Example 2
Input: arr[] = {10, 20, 20}
Output: 10 1
        20 2

*/

void countFrequency(int arr[], int size)
{
    int frequency[size];
    int value[size];
    for(int i = 0; i < size; i++)
    {
        frequency[i] = 0;
        value[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        int j = arr[i] % size;
        if(frequency[j] != 0)
        {
            frequency[j]++;
        }
        else
        {
            frequency[j]++;
            value[j] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (frequency[i] != 0) {
            printf("%d %d\n", value[i], frequency[i]);
        }
    }
}

int main()
{
    /*test1*/
    int arr[] = { 10, 20, 20, 10, 10, 20, 5, 20 };

    /*test2
    int arr[] = {10, 20, 20};
    */
    int size = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, size);
    return 0;
}
