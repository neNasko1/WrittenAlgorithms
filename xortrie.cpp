struct Node {
    ll l, r, cnt;
    Node() {l = r = -1; cnt = 0;}
};

const ll MAX_N = 1e7 + 10;

struct Trie {
    Node trie[MAX_N];
    ll sz = 1;

    int cnt(int x) {
        if(x == -1) {
            return 0;
        } else {
            return trie[x].cnt;
        }
    }

    void add(ll curr, ll x, ll d) {
        if(d == -1) {trie[curr].cnt = 1; return;}
        if(x & (1 << d)) {
            if(trie[curr].r == -1) {
                trie[curr].r = sz ++;
            }
            add(trie[curr].r, x, d - 1);
        } else {
            if(trie[curr].l == -1) {
                trie[curr].l = sz ++;
            }
            add(trie[curr].l, x, d - 1);
        }
        trie[curr].cnt = cnt(trie[curr].l) + cnt(trie[curr].r);
    }

    void rem(ll curr, ll x, ll d) {
        if(curr == -1) {return;} else if(d == -1) {trie[curr].cnt = 0; return;}
        if(x & (1 << d)) {
            rem(trie[curr].r, x, d - 1);
        } else {
            rem(trie[curr].l, x, d - 1);
        }
        trie[curr].cnt = cnt(trie[curr].l) + cnt(trie[curr].r);
    }

    ll ans(ll curr, ll x, ll d) {
        if(d == -1) {return 0;}
        if(x & (1 << d)) {
            if(trie[curr].r != -1 && trie[trie[curr].r].cnt > 0) {
                return ans(trie[curr].r, x, d - 1);
            } else {
                return ans(trie[curr].l, x, d - 1) + (1ll << d);
            }
        } else {
            if(trie[curr].l != -1 && trie[trie[curr].l].cnt > 0) {
                return ans(trie[curr].l, x, d - 1);
            } else {
                return ans(trie[curr].r, x, d - 1) + (1ll << d);
            }
        }
    }
};
