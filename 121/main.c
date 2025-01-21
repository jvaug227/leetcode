#include <stdint.h>
int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;
    int min_price_index = 0;
    for (uint32_t i = 1; i < pricesSize; i++) {
        int profit = prices[i] - prices[min_price_index];
        if (profit < 0) {
            min_price_index = i;
        }
        if (profit > max_profit) {
            max_profit = profit;
        }
    }
    return max_profit;
}
