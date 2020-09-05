long long inv[MAX_N];
void calculate() {
    inv[1] = 1;
    for(long long i = 2; i < MAX_N; i ++) {
        inv[i] = ((-(mod / i) * inv[mod % i]) % mod + mod) % mod;
    }
}
long long lp[MAX_N], phi[MAX_N]; vector<int> pr;
void euler() {
    phi[1] = 1;
    for(int i = 2; i < MAX_N; i ++) {
        if(!lp[i]) {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        } else {
            if(lp[i] == lp[i / lp[i]]) {
                phi[i] = phi[i / lp[i]] * lp[i];
            } else {
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
            }
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < MAX_N; j ++) {
            lp[pr[j] * i] = pr[j];
        }
    }
}
const int MAX_N = 4;
struct Matrix {
    ull tab[MAX_N][MAX_N];
    Matrix() {for(int i = 0; i < MAX_N; i ++) {fill_n(tab[i], MAX_N, 0);}}
    Matrix operator *(const Matrix &other) const {
        Matrix ans;
        for(int i = 0; i < MAX_N; i ++) {
            for(int j = 0; j < MAX_N; j ++) {
                for(int k = 0; k < MAX_N; k ++) {
                    ans.tab[i][j] += (tab[i][k] * other.tab[k][j]) % mod;
                    ans.tab[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    void operator =(const Matrix &other) {
        for(int i = 0; i < MAX_N; i ++) {
            for(int j = 0; j < MAX_N; j ++) {
                tab[i][j] = other.tab[i][j];
            }
        }
    }
};
Matrix identity() {
    Matrix ret;
    for(int i = 0; i < MAX_N; i ++) {
        ret.tab[i][i] = 1ll;
    }
    return ret;
}

ll fpow(ll &x, ull p) {
    ll pw = x, ret = 1;
    while(p) {
        if(p & 1ll) {
            ret = (ret * pw) % mod;
        }
        p /= 2ll;
        pw = (pw * pw) % mod;
    }
    return ret;
}
