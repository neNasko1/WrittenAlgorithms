const int MAX_N = 1e4 + 10;
struct CentroidDecomposition {
    vector<int> g[MAX_N], ct[MAX_N];
    int sz[MAX_N], root;
    bool used[MAX_N];
    void add(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dfs(int x, int p) {
        sz[x] = 1;
        for(auto it : g[x]) {
            if(it == p || used[it]) {continue;}
            sz[x] += dfs(it, x);
        }
        return sz[x];
    }
    int centroid(int x, int p, int n) {
        for(auto it : g[x]) {
            if(it == p || used[it]) {continue;}
            if(sz[it] >= n / 2) {return centroid(it, x, n);}
        }
        return x;
    }
    int build(int x, int p) {
        int n = dfs(x, p);
        int cen = centroid(x, p, n);
        used[cen] = true;
        for(auto it : g[cen]) {
            if(it == p || used[it]) {continue;}
            int now = build(it, cen);
            ct[cen].push_back(now);
        }
        root = cen;
        return cen;
    }
};
