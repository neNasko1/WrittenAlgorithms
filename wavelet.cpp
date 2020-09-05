const ll MAX_N = 2e7 + 10; ll MAX_ALPH = 1e9 + 10;

struct Node {
    vector<int> b, ind;
    int l, r;
    Node() {l = r = -1;}
};

struct Wavelet {
    vector<ll> arr;

    Node node[MAX_N];
    int cnt = 1;

    void make(vector<ll> &in) {
        arr = in;
        node[0].ind.resize(in.size());
        for(int i = 0; i < in.size(); i ++) {node[0].ind[i] = i;}
        build(0, -MAX_ALPH, MAX_ALPH);
    }

    void build(int curr, int l, int r) {
        if(node[curr].ind.empty() || l == r) {return;}
        int m = (l + r) / 2;
        node[curr].b.resize(node[curr].ind.size());
        node[curr].l = cnt ++;
        node[curr].r = cnt ++;
        for(int i = 0; i < node[curr].ind.size(); i ++) {
            if(arr[node[curr].ind[i]] <= m) {
                node[curr].b[i] = 1;
                node[node[curr].l].ind.push_back(node[curr].ind[i]);
            } else {
                node[node[curr].r].ind.push_back(node[curr].ind[i]);
            }
            if(i > 0) {node[curr].b[i] += node[curr].b[i - 1];}
        }
        build(node[curr].l, l, m);
        build(node[curr].r, m + 1, r);
    }
};
