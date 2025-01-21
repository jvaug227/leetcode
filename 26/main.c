#include <stdint.h>

int removeDuplicates(int* nums, int numsSize) {
    uint32_t i = 1;
    uint32_t k = 0;
    for (; i < numsSize && k < numsSize-1; i++) {
        if (nums[i] != nums[k]) {
            k++;
        }
        nums[k] = nums[i];
    }
    return k+1;
}
