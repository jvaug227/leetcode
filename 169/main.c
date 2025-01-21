#include <stdint.h>

// We are told that there will always be a "majority" element that will appear in the list
// at least n/2 times. To solve this problem in O(1) space, only a variable or two must be necessary
// to find the answer (i.e. won't need an array of equal elements O(N) to nums).
// I remember a pattern about this kind of problem, and it's to score positive points every time your number
// shows up, and score negative points when it does not. When it reaches 0, we replace the current number with 
// the next one in line. 
int majorityElement(int* nums, int numsSize) {
    int32_t current_num = nums[0]; // 1 <= n
    int32_t current_score = 1; // we're already assigned to it

    for (uint32_t i = 1; i < numsSize; i++) {
        if (nums[i] == current_num) {
            current_score += 1;
        } else {
            current_score -= 1;
        }
        if (current_score == 0) {
            current_num = nums[i];
            current_score = 1;
        }
    }

    return current_num;
}
