const int MAX_N = 1e5 + 10;
struct SegTree {
    int tree[4 * MAX_N], lazy[4 * MAX_N];

    void build(int curr, int l, int r, int (&arr)[MAX_N]) {
        if(l == r) {
            tree[curr] = arr[l]; lazy[curr] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(curr * 2, l, m, arr);
        build(curr * 2 + 1, m + 1, r, arr);
        tree[curr] = tree[curr * 2] + tree[curr * 2 + 1];
        lazy[curr] = 0;
    }

    void push(int curr, int l, int r) {
        tree[curr] += lazy[curr] * (r - l + 1);
        if(l != r) {
            lazy[curr * 2] += lazy[curr]; lazy[curr * 2 + 1] += lazy[curr];
        }
        lazy[curr] = 0;
    }

    void upd(int curr, int l, int r, int ql, int qr, int val) {
        push(curr, l, r);
        if(ql <= l && r <= qr) {
            lazy[curr] += val;
            push(curr, l, r);
            return;
        } else if(l > qr || r < ql) {return;}
        int m = (l + r) / 2;
        upd(curr * 2, l, m, ql, qr, val);
        upd(curr * 2 + 1, m + 1, r, ql, qr, val);
        tree[curr] = tree[curr * 2] + tree[curr * 2 + 1];
    }

    int query(int curr, int l, int r, int ql, int qr) {
        push(curr, l, r);
        if(ql <= l && r <= qr) {
            return tree[curr];
        } else if(l > qr || r < ql) {return 0;}
        int m = (l + r) / 2;
        return query(curr * 2, l, m, ql, qr) + query(curr * 2 + 1, m + 1, r, ql, qr);
    }
};

