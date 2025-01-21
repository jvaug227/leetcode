#include <stdint.h>

int jump(int* nums, int numsSize) {
    // if (numsSize == 1) return 0;

    uint32_t farthest_jump_index = 0;
    uint32_t current_jump_index = 0;
    uint32_t total_jumps = 0;
    
    for (uint32_t i = 0; i < numsSize 
        && farthest_jump_index < (numsSize-1); i += 1) {
        uint32_t jump_to = nums[i] + i;
        uint32_t farthest_jump = nums[farthest_jump_index] + farthest_jump_index;
        // Evaluate farthest jumper in current jump range
        if (jump_to > farthest_jump) {
            farthest_jump_index = i;
        }
        // When reach end of current range, jump to index with farthest range.
        if (i > current_jump_index) {
            total_jumps += 1;
            current_jump_index = farthest_jump;
        }
    }
    return total_jumps;
}
