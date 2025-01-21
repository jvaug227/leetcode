#include <stdint.h>

int removeElement(int* nums, int numsSize, int val) {

    uint32_t i = 0;
    uint32_t j = numsSize;

    while (i < j)  {
        if (nums[j-1] == val) {
            j -= 1;
            continue;
        }
        if (nums[i] == val) {
            nums[i] = nums[j-1];
            j -= 1;
        }

        i += 1;
    }

    return j;
}
