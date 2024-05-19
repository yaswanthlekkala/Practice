#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int* twosum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
     int* result = twosum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
}
int* twosum(int* nums, int numsSize, int target, int* returnSize)

{
    int* temp = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    bool found = false;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                temp[0] = i;
                temp[1] = j;
                found = true;
                break;
            }
        }

        if (found)
            break;
    }
    return temp;
}
