string s; int link[MAX_N];
void constructKMP() {
    link[0] = link[1] = 0;
    for(int i = 2; i <= s.size(); i ++) {
        int j = link[i - 1];
        while(true) {
            if(s[i - 1] == s[j]) {link[i] = j + 1; break;}
            if(j == 0) {link[i] = 0; break;}
            j = link[j];
        }
    }
}
