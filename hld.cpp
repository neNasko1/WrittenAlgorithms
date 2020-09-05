struct HLD {
    vector<int> g[MAX_N];
    int sz[MAX_N], heavy[MAX_N], par[MAX_N], d[MAX_N], sz[MAX_N];
    SegTree sg;
    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    void dfs(int x, int p) {
        sz[x] = 1; heavy[x] = -1; par[x] = p; d[x] = d[p] + 1;
        int mx = 0;
        for(auto it : g[x]) {
            if(it == p) {continue;}
            dfs(it, x);
            if(sz[it] > mx) {heavy[x] = it; mx = sz[it];}
            sz[x] += sz[it];
        }
    }
    void hld(int x, int p, int h) {
        head[x] = h; pos[x] = curr ++;
        if(heavy[x] != -1) {hld(heavy[x], x, h);}
        for(int i = 0; i < g[x].size(); i ++) {
            int it = g[x][i];
            if(it == p) {continue;}
            if(it != heavy[x]) {hld(it, x, it);}
        }
    }
    int query(int a, int b) {
        int ret = 0;
        for(; head[a] != head[b];) {
            if(d[head[a]] > d[head[b]]) {swap(a, b);}
            ret = max(ret, sg.ans(pos[head[b]], pos[b]));
            b = par[head[b]];
        }
        if(d[a] > d[b]) {swap(a, b);}
        ret = max(ret, sg.ans(pos[a], pos[b]));
        return ret;
    }
    void upd(int a, int b) {
        sg.upd(pos[a], b);
    }
};
