const int MAX_N = 1e5 + 10, ALPH = 30;
struct Automaton {
    int link[MAX_N], cnt, to[MAX_N][ALPH];
    int leaf[MAX_N];
    Automaton() {
        cnt = 1;
        for(int i = 0; i < MAX_N; i ++) {
            fill_n(to[i], ALPH, -1);
        }
    }
    void add(string &s, int tme) {
        int curr = 0;
        for(auto it : s) {
            int c = it - 'a';
            if(to[curr][c] == -1) {
                to[curr][c] = cnt ++;
            }
            curr = to[curr][c];
        }
        leaf[curr] = tme;
    }
    void pushLink() {
        queue<int> q; q.push(0);
        link[0] = -1;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(int c = 0; c < ALPH; c ++) if(to[curr][c] != -1) {
                int next = to[curr][c];
                int l = link[curr];
                while(l != -1 && to[l][c] == -1) {l = link[l];}
                if(to[l][c] != -1) {l = to[l][c];} else {l = 0;}
                link[next] = l;
                q.push(next);
            }
        }
    }
};
