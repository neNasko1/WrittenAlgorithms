///Type dp[i] = t(i) + min{c(j) * x[i] + ans[j] : j < i}
struct Line {
    ll a, b;
    ll y(ll x) {return x * a + b;}
    Line(ll _a, ll _b) {a = _a; b = _b;}
    Line() {a = 0; b = -mod;}
};
struct Node {
    Line val;
    Node *l, *r;
    Node() {l = nullptr; r = nullptr;}
    ll y(ll x) {return val.y(x);}
    void expand() {
        if(!l) {l = new Node(); r = new Node();}
    }
};
struct LiChao {
    Node root;
    void add(Line nw, Node *curr, ll l = 0, ll r = mod) {
        ll m = (l + r) / 2;
        bool a = nw.y(l) > curr->y(l);
        bool b = nw.y(m) > curr->y(m);
        if(b) {swap(curr->val, nw);}
        if(r - l == 1) {
            return;
        }
        curr->expand();
        if(a != b) {
            add(nw, curr->l, l, m);
        } else {
            add(nw, curr->r, m, r);
        }
    }
    ll get(ll x, Node *curr, ll l = 0, ll r = mod) {
        if(curr == nullptr) {return -mod;}
        ll m = (l + r) / 2;
        if(r - l == 1) {
            return curr->y(x);
        }
        if(x < m) {
            return max(curr->y(x), get(x, curr->l, l, m));
        } else {
            return max(curr->y(x), get(x, curr->r, m, r));
        }
    }
};

