class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0});

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (visited[r][c])
                continue;

            visited[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return cost;

            for (auto& d : dir) {

                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc])
                    continue;

                int newCost = max(cost, grid[nr][nc]);

                pq.push({newCost, nr, nc});
            }
        }

        return -1;
    }
};