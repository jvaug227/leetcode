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

//  Time Complexity: O(n+k)
//  Extra Space Complexity: O(k), worst-case: O(n)
void rotateDecent(int* nums, int numsSize, int k) {
    if (k == 0 || numsSize == 0) return;
    // [ (1 2 3) 4 5 6 a b (c 7 8) ]
    // [ c 7 8 (4 5 6) a b (1 2 3) ]
    // [ c 7 8 1 2 3 [a b (4 5 6)] ]


    // [ c 7 8 4 5 (6 a b) (1 2 3) ]
    // [ c 7 8 [(4 5 1) (2 3)] 6 a b ]
    // [ c 7 8 1 2 3 4 5 6 a b ]
    for (uint32_t j = 0; j < (numsSize/k)-1; j++) {
        uint32_t start = j * k;
        for (uint32_t i = 0; i < k; i++) {
            swap(nums, start+i, start+i+k);
        }
    }

    uint32_t offset = (numsSize/k)*(k-1);
    uint32_t new_size = numsSize - offset;
    int k2 = new_size - k;
    rotateDecent(nums + offset, new_size, k2);
    
}

// This is supposedly a "two-pointers problem", and can be solved in O(1) space.
// So two indicies and no allocating a new array.
void rotateGood(int* nums, int numsSize, int k) {
    for (uint32_t i = 0; i < numsSize; i++) {
        
    }
}

void rotate(int* nums, int numsSize, int k) {
    rotateDecent(nums, numsSize, k);
}
