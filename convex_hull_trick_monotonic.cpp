struct Line {
    ll a, b, ind;
    long double p;
    Line() {}
    Line(ll _a, ll _b, ll _ind) {a = _a; b = _b; ind = _ind;}
    ll y(ll x) {return a * x + b;}
    long double getWhere(const Line &other) {
        if(a == other.a) {
            return -mod;
        } else {
            return (long double)(b - other.b) / (long double)(other.a - a);
        }
    }
};

struct LineContainer {
    deque<Line> lines;
    void addLine(Line curr) {
        while(!lines.empty() && lines.back().getWhere(curr) <= lines.back().p) {
            lines.pop_back();
        }
        if(lines.empty()) {
            curr.p = -mod;
        } else {
            curr.p = lines.back().getWhere(curr);
        }
        lines.push_back(curr);
    }
    pair<ll, int> get(ll x) {
        while(lines.size() > 1 && lines[1].p <= x) {
            lines.pop_front();
        }
        return {lines.front().y(x), lines.front().ind};
    }
};
