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
     int find(int x) {
        if(parent[x] == x) return x;
        
        int temp = find(parent[x]);
        parent[x] = temp;
        return temp;
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
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
