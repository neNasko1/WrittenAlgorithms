int arr[MAX_N], n, cnt; vector<int> c;
void compress() {
    for(int i = 0; i < n; i ++) {
        c.push_back(arr[i]);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    cnt = c.size();
    for(int i = 0; i < n; i ++) {
        arr[i] = lower_bound(c.begin(), c.end(), arr[i]) - c.begin();
    }
}


