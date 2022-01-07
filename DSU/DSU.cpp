struct UnionFind {
    int n;
    vector<int> rank;
    vector<int> parent;
    // store other info as required
    UnionFind(int n) {
        rank.resize(n);
        fill(rank.begin(), rank.end(), 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int get(int x) {
        if(parent[x] == x) return x;
        
        int temp = get(parent[x]);
        parent[x] = temp;
        return temp;
    }
    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return;
        }
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
        if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
};
