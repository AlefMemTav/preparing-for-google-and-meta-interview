#include <stdio.h>
#include <stdlib.h>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Examples:
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

/*BRUTE FORCE APPROACH*/
int* twoSum(int* nums, int size, int target, int* returnSize)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int* result = malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    /*test1*/
    int nums[] = {2, 7, 11, 15};
    int target = 9;

    /*test2
    int nums[] = {3,2,4};
    int target = 6;
    */

    /*test3
    int nums[] = {3,3};
    int target = 6;
    */

    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int* result = twoSum(nums, size, target, &returnSize);
    if (result != NULL)
    {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }

    return 0;
}
