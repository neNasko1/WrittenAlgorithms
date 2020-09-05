struct SuffixArray {
    int sufarr[MAX_N];
    pair<pair<int, int>, int> l[MAX_N];
    int rnk[LOG][MAX_N];
    ll n, len, lg;

    ll lcp(int i, int j) {
        int ans = 0;
        for(int k = lg - 1; k >= 0; k --) {
            if(rnk[k][i] == rnk[k][j]) {
                i += (1 << k);
                j += (1 << k);
                ans += (1 << k);
            }
        }
        return ans;
    }

    void construct(string &str) {
        str += '$';
        n = str.size();
        int cnt = -1;
        for(int i = 0; i < n; i ++) {
            l[i] = {{str[i], -1}, i};
        }
        sort(l, l + n);
        for(int i = 0; i < n; i ++) {
            if(i == 0 || l[i].first != l[i - 1].first) {
                rnk[0][l[i].second] = ++ cnt;
            } else {
                rnk[0][l[i].second] = cnt;
            }
        }
        for(lg = 1, len = 1; len < n; lg ++, len *= 2) {
            cnt = -1;
            for(int i = 0; i < n; i ++) {
                if(i + len < n) {
                    l[i] = {{rnk[lg - 1][i], rnk[lg - 1][i + len]}, i};
                } else {
                    l[i] = {{rnk[lg - 1][i], -1}, i};
                }
            }
            sort(l, l + n);
            for(int i = 0; i < n; i ++) {
                if(i == 0 || l[i].first != l[i - 1].first) {
                    rnk[lg][l[i].second] = ++ cnt;
                } else {
                    rnk[lg][l[i].second] = cnt;
                }
            }
        }
        ll ans = (n * n - n) / 2ll;
        for(int i = 0; i < n - 1; i ++) {
            ans -= lcp(l[i].second, l[i + 1].second);
        }
        cout << ans << endl;
    }

};
