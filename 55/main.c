#include <stdbool.h>
#include <stdint.h>
bool canJump(int* nums, int numsSize) {
    int32_t max_stamina = nums[0];
    uint32_t i = 1;
    for (; i < numsSize && max_stamina > 0; i++) {
        max_stamina -= 1;
        int32_t stamina = nums[i];
        if (stamina >= max_stamina) {
            max_stamina = stamina;
        }
    }
    return i == numsSize;
}
