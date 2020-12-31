struct Edge {
    int to;
    ll cap, f;
    Edge() : to(0), cap(0), f(0) {}
    Edge(int to, ll cap) : to(to), cap(cap), f(0) {}
};
struct FlowNetwork {
    ll s, t;
    vector<int> g[MAX_N];
    int dist[MAX_N], id[MAX_N];
    vector<Edge> edges;
    FlowNetwork() : s(MAX_N - 2), t(MAX_N - 1) {}
    FlowNetwork(ll s, ll t) : s(s), t(t) {}
    void reset() {edges.resize(0); for(int i = 0; i < MAX_N; i ++) {g[i].resize(0);}}
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
            for(auto it : g[curr]) {
                if(dist[edges[it].to] != -1 || edges[it].cap - edges[it].f < 1) {continue;}
                dist[edges[it].to] = dist[curr] + 1;
                q.push(edges[it].to);
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
    ll maxFlow() {
        ll ret = 0;
        while(bfs()) {
            ll p;
            while(p = dfs(s, mod)) {
                ret += p;
            }
        }
        return ret;
    }
};
