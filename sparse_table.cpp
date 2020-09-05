int arr[MAX_N], mn[MAX_N][LOG];
int n;
void construct() {
    for(int i = 0; i < n; i ++) {mn[i][0] = arr[i];}
    for(int j = 1; j < LOG; j ++) {
        for(int i = 0; i + (1 << j) <= n; i ++) {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r) {
    int q = 0;
    while((1 << q) <= r - l + 1) {q ++;} q --;
    return min(mn[l][q], mn[r - (1 << q) + 1][q]);
}
