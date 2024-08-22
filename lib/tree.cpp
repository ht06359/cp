#include<bits/stdc++.h>
using namespace std;


// Euler Tour
template<typename T, auto op, auto e>
struct segment_tree {
    int n;
    vector<T> dat;
    segment_tree (int _n) {
        n = __lg(_n) + 1;
        dat.assign(1 << (n+1), e());
    };

    void update(int i, T x) {
        i += (1 << n);
        dat[i] = x;
        while (i > 1) {
            i >>= 1;
            dat[i] = op(dat[i << 1], dat[(i << 1) | 1]);
        }
    }

    T get(int i) {
        return dat[i + (1<<n)];
    }

    T prod(int l, int r) {
        return _prod(l, r, 1, 0, 1<<n);
    }

    T prod_all() {
        return dat[1];
    }

    private:
    T _prod(int l, int r, int id, int _l, int _r) {
        if (_r <= l || r <= _l) return e();
        if (l <= _l && _r <= r) return dat[id];
        return op(_prod(l, r, id << 1, _l, (_l + _r) >> 1), _prod(l, r, (id << 1) | 1, (_l + _r) >> 1, _r));
    }
};

int64_t op(int64_t a, int64_t b) {
    return min(a, b);
}
int64_t e() {
    return (int64_t) 1e16;
}
int root;
vector<int> vs, depth, in, out;
vector<int64_t> _sum;
void init(int _n) {
    depth.assign(2*_n, -1);
    in.resize(2*_n);
    out.resize(2*_n);
    _sum.assign(2*_n+1, (int64_t)0);
};
void _dfs_et(const vector<vector<pair<int,int64_t>>> &_g, int v, int p, int d, int64_t w, int &timer) {
    in[v] = timer;
    vs[timer] = v;
    depth[timer++] = d;
    _sum[v] = (p != -1 ? _sum[p] + w : w);
    for (auto [nv, l] :_g[v]) if (nv != p) {
        _dfs_et(_g, nv, v, d+1, l, timer);
        out[v] = timer;
        vs[timer] = v;
        depth[timer++] = d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pair<int, int64_t>>> g(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    init(n);
    int ti = 0;
    _dfs_et(g, 0, -1, 0, 0, ti);
    int tt;
    cin >> tt;
    for (;tt--;) {
        int t;
        cin >> t;
        if (t == 1) {
            int id;
            int64_t W;

        }
    }
}

