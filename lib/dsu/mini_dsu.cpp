#include<bits/stdc++.h>
using namespace std;

struct dsu {
    int n;
    vector<int> par;
    vector<int> siz;

    dsu(int _n) {
        n = _n;
        par.resize(_n);
        siz.assign(_n, 0);
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