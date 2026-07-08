class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = prices;
            for (auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];
                if (prices[from] == INT_MAX)
                    continue;
                temp[to] = min(temp[to], prices[from] + cost);
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};