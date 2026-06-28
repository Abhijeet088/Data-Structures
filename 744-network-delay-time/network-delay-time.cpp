class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node])
                continue;
            for (auto& [nei, wt] : adj[node]) {
                int newTime = time + wt;
                if (newTime < dist[nei]) {
                    dist[nei] = newTime;
                    pq.push({newTime, nei});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n + 1 ; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};