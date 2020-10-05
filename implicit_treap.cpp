const ll inf = 1e18;

struct Node {
    ll pri, val;
    int cnt;
    Node *l, *r;
    Node(ll _val) {
        val = _val;
        cnt = 1;
        pri = rand() * rand() + rand();
        l = r = nullptr;
   }
};

struct Treap {
    typedef Node *node;
    node root;
    void clear() {root = nullptr;}
    int cnt(node t) {return t ? t->cnt : 0;}
    void traverse(node t) {
        if(!t) {return;}
        push(t);
        traverse(t->l);
        cout << t->val << " ";
        traverse(t->r);
    }
    int cnt() {return cnt(root);}
    void traverse() {traverse(root); cout << endl;}

    void push(node &t) {
        if(!t) {return;}
    }
    void comb(node &t) {
        if(!t) {return;}
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
    }

    node merge(node l, node r) {
        push(l); push(r);
        if(!l) {return r;}
        if(!r) {return l;}
        if(l->pri > r->pri) {
            node newR = merge(l->r, r);
            l->r = newR;
            comb(l);
            return l;
        } else {
            node newL = merge(l, r->l);
            r->l = newL;
            comb(r);
            return r;
        }
    }
    pair<node, node> split(node t, int x) {
        push(t);
        if(!t) {return {nullptr, nullptr};}
        int curr = cnt(t->l) + 1;
        if(x < curr) {
            auto a = split(t->l, x);
            t->l = a.second;
            comb(t);
            return {a.first, t};
        } else {
            auto a = split(t->r, x - curr);
            t->r = a.first;
            comb(t);
            return {t, a.second};
        }
    }
};
