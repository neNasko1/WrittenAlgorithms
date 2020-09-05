ll big = MAX_N, sr = MAX_N / 2;
while(big > 1) {
    bool flag = false;
    init();
    for(ll i = 0; i < MAX_N; i ++) {
        add(i);
        ll lb = i - (big / 2), rb = i + (big / 2);
        for(auto it : toAns[i]) {
            if(eval(it)) {
                nxt[(i + rb) / 2].push_back(it);
            } else {
                nxt[(i + lb) / 2].push_back(it);
            }
        }
    }
    for(ll i = 0; i < MAX_N; i ++) {
        toAns[i] = nxt[i];
        nxt[i].resize(0);
    }
    big /= 2;
}

