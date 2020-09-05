struct Lca {
    vector<pair<int, ll> > g[MAX_N];
    ll par[MAX_N][MAX_LOG], mx[MAX_N][MAX_LOG], d[MAX_N];

    void add(int a, int b, ll c) {
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    void pre(int x, int p, ll w) {//Initialize lca with pre(root, 0, 0);
        par[x][0] = p;
        mx[x][0] = w;
        d[x] = d[p] + 1;
        for(int i = 1; i < MAX_LOG; i ++) {
            par[x][i] = par[par[x][i - 1]][i - 1];
            mx[x][i] = max(mx[par[x][i - 1]][i - 1], mx[x][i - 1]);
        }
        for(auto it : g[x]) {
            if(it.first == p) {continue;}
            pre(it.first, x, it.second);
        }
    }

    ll ans(int a, int b) {
        if(d[a] < d[b]) {swap(a, b);}
        ll ret = 0;
        for(int i = MAX_LOG - 1; i >= 0; i --) {
            if(d[a] >= d[b] + (1 << i)) {
                chkmax(ret, mx[a][i]);
                a = par[a][i];
            }
        }
        if(a == b) {return ret;}
        for(int i = MAX_LOG - 1; i >= 0; i --) {
            if(par[a][i] != par[b][i]) {
                chkmax(ret, max(mx[a][i], mx[b][i]));
                a = par[a][i];
                b = par[b][i];
            }
        }
        return max({ret, mx[a][0], mx[b][0]});
    }
};
