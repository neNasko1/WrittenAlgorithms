const ll mod[2] = {(ll)1e9 + 7, (ll)1e9 + 9};
const ll MAX_N = 1e5 + 10;

struct Hash {
    ll pref[MAX_N][2], base[2] = {69, 31};
    ll pw[MAX_N][2];

    pair<ll, ll> query(ll l, ll r) {
        if(l == 0) {
            return {pref[r][0], pref[r][1]};
        }
        return {(pref[r][0] - pref[l - 1][0] + mod[0]) % mod[0], (pref[r][1] - pref[l - 1][1] + mod[1]) % mod[1]};
    }

    bool ok(ll l, ll r, ll x, ll y) {
        if(r - l != y - x) {return false;}
        auto a = query(l, r);
        auto b = query(x, y);
        if(l < x) {
            a.first = (a.first * pw[x - l][0]) % mod[0];
            a.second = (a.second * pw[x - l][1]) % mod[1];
        } else {
            b.first = (b.first * pw[l - x][0]) % mod[0];
            b.second = (b.second * pw[l - x][1]) % mod[1];
        }
        return a == b;
    }

    void precompute(string &in) {
        ll n = in.size();
        pw[0][0] = pw[0][1] = 1;
        for(ll i = 1; i < MAX_N; i ++) {
            for(ll j = 0; j < 2; j ++) {
                pw[i][j] = (pw[i - 1][j] * base[j]) % mod[j];
            }
        }
        for(ll i = 0; i < n; i ++) {
            for(ll j = 0; j < 2; j ++) {
                pref[i][j] = ((in[i] - 'a') * pw[i][j]) % mod[j];
                if(i > 0) {
                    pref[i][j] = (pref[i][j] + pref[i - 1][j]) % mod[j];
                }
            }
        }
    }
}
