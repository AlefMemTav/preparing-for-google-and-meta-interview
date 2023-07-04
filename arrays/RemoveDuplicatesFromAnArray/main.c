#include <stdio.h>
#include <stdlib.h>
/**
Remove duplicates from an array

Given an array of integers, the task is to remove the duplicates from the array.
Example 1:
Input: arr1[]={1,2,2,4,5,4,7,8,7,3,6}
Output: arr2[]={1,2,4,5,7,8,3,6}
*/

#define TABLE_SIZE 100

typedef struct HashTable
{
    int key;
} HashTable;

HashTable hashTable[TABLE_SIZE];

int hash(int key)
{
    return abs(key) % TABLE_SIZE;

}

void initializeHashTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].key = -1;
    }
}

int removeDuplicates(int arr[], int arrsize)
{
    initializeHashTable();
    int n = 0;
    for(int i = 0; i < arrsize; i++)
    {
        int j = hash(arr[i]);
        while(hashTable[j].key != -1)
        {
            if(hashTable[j].key == arr[i])
            {
                break;
            }
            else
            {
                j = (j + 1);
            }
        }
        if(hashTable[j].key != arr[i])
        {
            hashTable[j].key = arr[i];
            n++;
        }
    }

    int k = 0;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].key != -1)
        {
            arr[k] = hashTable[i].key;
            k++;
        }
    }

    return n;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    /* test1 */
    int arr1[]= {1,2,2,4,5,4,7,8,7,3,6};
    /* test2
    int arr1[]= {1,1,2};
    */
    /* test3
    int arr1[] = {0,0,1,1,1,2,2,3,3,4};
    */
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int newsize = removeDuplicates(arr1, size1);

    printArray(arr1, newsize);
    return 0;
}
