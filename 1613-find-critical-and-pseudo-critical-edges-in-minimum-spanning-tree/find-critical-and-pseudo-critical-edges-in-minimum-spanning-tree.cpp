class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y) {

        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (rank[x] < rank[y])
            swap(x, y);

        parent[y] = x;

        if (rank[x] == rank[y])
            rank[x]++;

        return true;
    }
};

class Solution {
public:
    int kruskal(int n, vector<vector<int>>& edges, int skipEdge,
                int forceEdge) {
        DSU dsu(n);

        int weight = 0;
        int count = 0;

        if (forceEdge != -1) {
            dsu.unite(edges[forceEdge][0], edges[forceEdge][1]);
            weight += edges[forceEdge][2];
            count++;
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == skipEdge)
                continue;

            if (dsu.unite(edges[i][0], edges[i][1])) {
                weight += edges[i][2];
                count++;
            }
        }

        if (count == n - 1)
            return weight;

        return INT_MAX;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        int originalWeight = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < edges.size(); i++) {

            if (kruskal(n, edges, i, -1) > originalWeight) {
                critical.push_back(edges[i][3]);
            }

            else if (kruskal(n, edges, -1, i) == originalWeight) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};