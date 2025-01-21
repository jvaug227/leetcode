#include <stdint.h>

// Essentially a modified version of my "Remove Duplicated from Sorted Array I",
// Heres a basic Idea of how the algorithm works using one of the test-cases:
//
// Given K and I, where K is the current valid end of the array and I is the look-ahead,
// In the sample [ 0,0,1,1,1,1,2,3,3 ], K would start at index 1 and I at index 2.
// "J" (or K-1) serves as the basis of comparison at index 0.
// In this example, J is 0, K is 0, and I is 1. As you would easily notice, J is sitting on 0
// and its next value would be 0. Should K ever move, J would sit on the second acceptable duplicate.
// When the move of K occurs, we don't care about what value K will be, only that it will be sitting on 
// something not a valid duplicate, so we can go ahead and replace it with whatever is on I.
//
// Once this move and replace occurs, the data now looks like:
//     J K I
// [ 0,0,1,1,1,1,2,3,3 ]
// Now J will be sitting on the second acceptable duplicate, K will be sitting on some arbitrary value,
// and I will be on one of two values: An unacceptable duplicate or a new series of values to parse.
//     J K I
// [ 0,0,X,?,1,1,2,3,3 ]
// Should I be on another duplicate (I == J), we know K is sitting on a 3rd duplicate. We don't want this, so we
// want to stop the move of K from occuring should this condition be true; or on inverse, we want to only move when this
// condition is false.
//
// In this example, (I != J), so we move K (and therefor J):
//       J K I
// [ 0,0,1,1,1,1,2,3,3 ]
//
// Well, now we've hit the condition (I == J), so lets just skip doing anything and let I increment:
//       J K   I
// [ 0,0,1,1,1,1,2,3,3 ]
//
// Oops, its another duplicate, let's go again:
//       J K     I
// [ 0,0,1,1,1,1,2,3,3 ]
//
// We finally hit a new value! Lets jump K so we don't override the 1 pair and replace it with the 2:
//         J K   I
// [ 0,0,1,1,2,1,2,3,3 ] (Note: this is the same loop iteration as the last sample, I is in the same place.)
//
// Looks like (I != J) still, so we do it again:
//           J K   I
// [ 0,0,1,1,2,3,2,3,3 ]
//
// aaand again:
//             J K   I
// [ 0,0,1,1,2,3,3,3,3 ]
//
// On the next cycle of the loop, there's no more data to check and K+1 is the size of the valid array.
int removeDuplicates(int* nums, int numsSize) {
    // Anything size two or less will either be 2 of the same entry 
    // or 2 different entries; automatically being a qualified output.
    if (numsSize < 3) return numsSize;

    uint32_t k = 1;
    uint32_t i = 2;

    for (; i < numsSize; i++) {
        int current_j = nums[k-1];
        int current_i = nums[i];
        if (
            current_j != current_i) {
            k += 1;
            nums[k] = nums[i];
        }
    }

    return k+1;
}
