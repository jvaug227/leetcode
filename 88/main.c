#include <stdint.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  uint32_t nums2_index = 0;

  if (n == 0) {
    return;
  }

  int32_t a = m-1;
  int32_t b = n-1;

  for (uint32_t t = (m+n); t > 0; t--) {
    int value = -1000000000;
    int32_t* value_to_decrement = &a;
    if (a >= 0) {
        value = nums1[a];
    }
    
    if (b >= 0 && nums2[b] > value) {
        value = nums2[b];
        value_to_decrement = &b;
    }

    nums1[t-1] = value;
    *value_to_decrement -= 1;
  }

}
