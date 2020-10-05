struct SparseTable {
    int ans[LOG][MAX_N];
    void construct(int n, int (&arr)[MAX_N]) {
        for(int i = 0; i < n; i ++) {ans[0][i] = arr[i];}
        for(int j = 1; j < LOG; j ++) {
            for(int i = 0; i + (1 << j) <= n; i ++) {
                ans[j][i] = min(ans[j - 1][i], ans[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int q = 0;
        while((1 << q) <= r - l + 1) {q ++;} q --;
        return min(ans[q][l], ans[q][r - (1 << q) + 1]);
    }
};
