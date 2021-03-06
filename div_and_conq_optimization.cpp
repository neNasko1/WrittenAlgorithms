///Type: dp[i][j] = min{dp(i - 1, k) + C(k, j) : k <= j}
///Condition:For every j'<j opt(i, j')<=opt(i, j)
int n;
long long C(int i, int j);
vector<long long> dp_before(n), dp_cur(n);
void compute(int l, int r, int optl, int optr) {
    if (l > r) {return;}
    int mid = (l + r) / 2;
    pair<long long, int> best = {INF, -1};
    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {dp_before[k] + C(k, mid), k});
    }
    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}
