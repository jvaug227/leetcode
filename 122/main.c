#include <stdint.h>
int maxProfit(int* prices, int pricesSize) {
    int32_t total_profit = 0;
    uint32_t min_profit_index = 0;
    for (int32_t i = 0; i < pricesSize; i++) {
        int32_t profit = prices[i] - prices[min_profit_index];
        if (profit < 0) {
            min_profit_index = i;
        }
        if (profit > 0) {
            total_profit += profit;
            min_profit_index = i;
        }
    }
    return total_profit;
}
