struct Automaton {
    int leaf[MAX_N];
    int link[MAX_N], cnt;
    map<char, int> to[MAX_N];
    Automaton() {cnt = 1;}
    void add(string &s, int tme) {
        int curr = 0;
        for(auto it : s) {
            if(!to[curr].count(it)) {
                to[curr][it] = cnt ++;
            }
            curr = to[curr][it];
        }
        leaf[curr] = tme;
    }
    void pushLink() {
        queue<int> q; q.push(0);
        link[0] = -1;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(auto it : to[curr]) {
                int next = it.second;
                char c = it.first;
                int l = link[curr];
                while(l != -1 && !to[l].count(c)) {l = link[l];}
                if(l != -1) {l = to[l][c];} else {l = 0;}
                link[next] = l;
                q.push(next);
            }
        }
    }
};

