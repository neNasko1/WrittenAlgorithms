struct Edge {
    int to;
    ll cap, f;
    Edge(int to, ll cap) : to(to), cap(cap), f(0) {}
};
struct FlowNetwork {
    ll s, t, n, m;
    vector<int> g[MAX_N];
    int dist[MAX_N], id[MAX_N];
    vector<Edge> edges;
    FlowNetwork(ll s, ll t, ll n) : s(s), t(t), n(n) {}
    void addEdge(ll a, ll b, ll cap) {
        g[a].push_back(edges.size());
        edges.emplace_back(b, cap);
        g[b].push_back(edges.size());
        edges.emplace_back(a, 0);
    }
    queue<ll> q;
    bool bfs() {
        for(ll i = 0; i < MAX_N; i ++) {dist[i] = -1; id[i] = 0;}
        q.push(s);
        dist[s] = 0;
        while(!q.empty()) {
            ll curr = q.front(); q.pop();
            for(auto id : g[curr]) {
                if(dist[edges[id].to] != -1 || edges[id].cap - edges[id].f < 1) {continue;}
                dist[edges[id].to] = dist[curr] + 1;
                q.push(edges[id].to);
            }
        }
        return dist[t] != -1;
    }
    ll dfs(int curr, ll pushed) {
        if(pushed == 0 || curr == t) {return pushed;}
        for(; id[curr] < g[curr].size();) {
            int nxt = g[curr][id[curr] ++];
            if(dist[edges[nxt].to] != dist[curr] + 1 || edges[nxt].cap - edges[nxt].f < 1) {continue;}
            ll tr = dfs(edges[nxt].to, min(edges[nxt].cap - edges[nxt].f, pushed));
            if(tr != 0) {
                edges[nxt].f += tr;
                edges[nxt ^ 1].f -= tr;
                return tr;
            }
        }
        return 0;
    }
    ll callDfs() {
        return dfs(s, mod);
    }
    ll maxFlow() {
        ll ret = 0;
        while(bfs()) {
            ll p;
            while(p = callDfs()) {
                ret += p;
            }
        }
        return ret;
    }
};
