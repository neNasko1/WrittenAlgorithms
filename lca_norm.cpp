const ll MAX_N = 2e5 + 10, MAX_LOG = 20;
struct Lca {
    vector<ll> g[MAX_N];
    int par[MAX_N][MAX_LOG], d[MAX_N];
    void add(ll a, ll b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void pre(int x, int p) {
        par[x][0] = p;
        d[x] = d[p] + 1;
        for(ll i = 1; i < MAX_LOG; i ++) {
            par[x][i] = par[par[x][i - 1]][i - 1];
        }
        for(auto it : g[x]) {
            if(it == p) {continue;}
            pre(it, x);
        }
    }

    int lift(int a, int k) {
        for(ll i = MAX_LOG - 1; i >= 0; i --) {
            if(par[a][i] != -1 && d[par[a][i]] >= k) {
                a = par[a][i];
            }
        }
        return a;
    }

    int ans(int a, int b) {
        if(d[a] < d[b]) {swap(a, b);}
        a = lift(a, d[b]);
        if(a == b) {return a;}
        for(ll i = MAX_LOG - 1; i >= 0; i --) {
            if(par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
        }
        return par[a][0];
    }
};


