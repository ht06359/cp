#include<bits/stdc++.h>
using namespace std;
const int64_t inf = 1e18;
const int64_t mod = 1e9 + 7;

struct dsu {
    int n;
    vector<int> par;
    vector<int> siz;

    dsu(int _n) {
        n = _n;
        par.resize(_n);
        siz.assign(_n, 1);
        iota(par.begin(), par.end(), 0);
    }

    inline int root(int v) {
        if (par[v] == v) {
            return v;
        } else {
            return par[v] = root(par[v]);
        }
    }

    inline int size (int v) {
        return siz[root(v)];
    }

    inline bool same(int u, int v) {
        return root(u) == root(v);
    }

    inline bool unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u != v) {
            par[u] = v;
            siz[v] += siz[u];
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}