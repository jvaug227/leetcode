#include <stdint.h>
#include <stdlib.h>
#include <string.h>

const uint32_t MAX_CITATIONS = 1001;
int hIndex(int* citations, int citationsSize) {
    uint32_t* hset = malloc(sizeof(uint32_t) * MAX_CITATIONS);
    memset(hset, 0, sizeof(uint32_t) * MAX_CITATIONS);

    uint32_t max_h = 0;

    for (uint32_t i = 0; i < citationsSize; i++) {
        uint32_t h = citations[i];
        hset[h] += 1;
        if (h > max_h) max_h = h;
    }

    uint32_t sum = 0;
    for (uint32_t i = max_h+1; i > 0; i -= 1) {
        uint32_t h = i-1;
        uint32_t h_value = hset[h];
        
        sum += h_value;
        // printf("h %i with value %i, total: %i\n", h, h_value, sum);

        if (sum >= h) {
            return h;
        }
    }

    free(hset);
    return 0;
}
