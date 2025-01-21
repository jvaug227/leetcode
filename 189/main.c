#include <stdint.h>
#include <stdlib.h>


/*
"MULTIPLE OF K"

k=3, n=6, steps=2
0. (1 2 3) (4 5 6)
1. 4 5 6 1 2 3

k=2, n=6, steps=3
0. (1 2) 3 4 (5 6)
1. 5 6 (3 4) (1 2)
2. 5 6 1 2 3 4

k=2, n=8, steps=4
0. (1 2) 3 4 5 6 (7 8)
1. 7 8 (3 4) 5 6 (1 2)
2. 7 8 1 2 (5 6) (3 4)
3. 7 8 1 2 3 4 5 6

k=1, n=6, steps=6
0. (1) 2 3 4 5 (6)
1. 6 (2) 3 4 5 (1)
2. 6 1 (3) 4 5 (2)
3. 6 1 2 (4) 5 (3)
4. 6 1 2 3 (5) (4)
5. 6 1 2 3 4 5

"NOT MULTIPLE OF K"

k=2, n=5
0. (1 2) 3 (4 5)
1. 4 5 [3 1 2]


k=3, n=11
0. (1 2 3) 4 5 6 7 8 (9 10 11)
1. 9 10 11 (4 5 6) 7 8 (1 2 3)
2. 9 10 11 1 2 3 (7 8 (4) 5 6)

0. 1 2 3 4 5 6 7 8 9 10 11
1. 11 10 9 8 7 6 5 4 3 2 1
2. 9 10 11 6 7 8 5 4 3 1 2
3. 9 10 11 2 1 3 4 5 8 7 6
4. 9 10 11 3 1 2 4 5 6 7 8



k=5, n=11
0. (1 2 3 4 5) 6 (7 8 9 10 11)
1. 7 8 9 10 11 (6 (1 2 3 4) 5)


when leftover n: (k, 2k)

k=2, n=3
0. (1 (2) 3)
x. 2 3 1


k=3, n=5
0. (1 2 (3) 4 5)
x. 3 4 5 1 2


k=5, n=6
0. (1 (2 3 4 5) 6)
1. (6 (5 4 3 2) 1)
x. 2 3 4 5 6 1


*/


//  Time Complexity: O(n+k)
//  Extra Space Complexity: O(k), worst-case: O(n)
void rotateBad(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int* buffer = malloc(sizeof(int) * k);
    for (uint32_t i = 0; i < k; i++) {
        buffer[i] = nums[i + (numsSize-k)];
    }
    for (uint32_t i = (numsSize); i > k; i--) {
        uint32_t i2 = i-1;
        nums[i2] = nums[i2-k];
    }
    for (uint32_t i = 0; i < k; i++) {
        nums[i] = buffer[i];
    }
    free(buffer);
}

void swap(int* nums, uint32_t i1, uint32_t i2) {
    int temp = nums[i1];
    nums[i1] = nums[i2];
    nums[i2] = temp;
}

void rotate_on_center(int*nums, int numsSize) {
    uint32_t last = numsSize-1;
    for (uint32_t i = 0; i < numsSize/2; i++) {
        // printf("Swapping %i and %i\n", nums[i], nums[last-i]);
        swap(nums,i, last-i);
    }
}

// Space Complexity: O(1)
// Time Complexity: O(N)
void rotateGood(int* nums, int numsSize, int k) {
    if (numsSize <= 1) return;
    k = k % numsSize;
    rotate_on_center(nums, numsSize);
    rotate_on_center(nums, k);
    rotate_on_center(nums+k, numsSize-k);
}

void rotate(int* nums, int numsSize, int k) {
    rotateGood(nums, numsSize, k);
}
