struct SuffixAutomaton {
	map<char, int> to[MAX_N];
	int len[MAX_N], link[MAX_N];
	int cnt = 0, last;

	void add_letter(char c) {
        int curr = cnt ++, p;
        len[curr] = len[last] + 1;
        for(p = last; p != -1 && !to[p].count(c); p = link[p]) {
            to[p][c] = curr;
        }
        if(p == -1) {
            link[curr] = 0;
        } else {
            int q = to[p][c];
            if(len[q] == len[p] + 1) {
                link[curr] = q;
            } else {
                int clone = cnt ++;
                len[clone] = len[p] + 1;
                to[clone] = to[q];
                link[clone] = link[q];
                for(; p != -1 && to[p][c] == q; p = link[p]) {
                    to[p][c] = clone;
                }
                link[q] = link[curr] = clone;
            }
        }
        last = curr;
	}
	void clear() {
        cnt = last = 0;
        len[0] = 0;
        link[0] = -1;
        cnt ++;
    }
	void init(string s) {
		clear();
		for(int i = 0; i < s.size(); i ++) {
			add_letter(s[i]);
		}
		calculate();
	}
	SuffixAutomaton() {cnt = 0; clear();}
};

