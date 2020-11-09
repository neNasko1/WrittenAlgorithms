struct State {
	ll vert, par, sz, tme;
};

struct DSU {
	ll par[MAX_N], sz[MAX_N], tme;
	stack<State> roll;
	void init() {
		tme = 0;
		while(!roll.empty()) {roll.pop();}
		for(ll i = 0; i < MAX_N; i ++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	ll find(ll x) {
		if(x == par[x]) {
			return par[x];
		} else {
			return find(par[x]);
		}
	}
	void remember(ll x) {
		roll.push({x, par[x], sz[x], tme});
	}
	bool merge(ll x, ll y) {
		x = find(x); y = find(y);
		if(x == y) {
			return false;
		}

		tme ++;
		remember(x);
		remember(y);
		
		if(sz[x] < sz[y]) {swap(x, y);}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	void rollback(ll when) {
		while(!roll.empty() && roll.top().tme > when) {
			auto now = roll.top(); roll.pop();
			par[now.vert] = now.par;
			sz[now.vert] = now.sz;
		}
	} 
};
