#include<bits/stdc++.h>
using namespace std;


template<typename T, auto op, auto e>
struct segment_tree {
    int n;
    vector<T> dat;
    segment_tree (int _n) {
        n = __lg(_n) + 1;
        dat.assign(1 << (n+1), e());
    };
    void add(int i, T x) {
        i += (1 << n);
        dat[i] += x;
        while (i > 1) {
            i >>= 1;
            dat[i] = op(dat[i << 1], dat[(i << 1) | 1]);
        }
    }
    void update(int i, T x) {
        i += (1 << n);
        dat[i] = x;
        while (i > 1) {
            i >>= 1;
            dat[i] = op(dat[i << 1], dat[(i << 1) | 1]);
        }
    }
    void init(const vector<T> &a) {
        for (int i = 0; i < (int)a.size(); i++) {
            dat[i + (1 << n)] = a[i];
        }
        for (int i = (1 << n) - 1; i >= 0; i--) {
            dat[i] = op(dat[i << 1], dat[(i << 1) | 1]);
        }
    }
    T get(int i) {
        return dat[i + (1 << n)];
    }
    T prod(int l, int r) {
        return _prod(l, r, 1, 0, 1 << n);
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

/*
template<typename T, auto op, auto e>
struct heavy_light_decomposition {
    int n;
    vector<int> in, out, leader, siz, par, inv;
    const vector<vector<int>> *g = nullptr;
    segment_tree<T, op, e> *s = nullptr;

    heavy_light_decomposition(const vector<vector<int>> &_g, segment_tree<T, op, e> &_s) {
        n = (int) _g.size();
        g = &_g;
        s = &_s;
        siz.assign(n, 0);
        in.assign(n, 0);
        out.resize(n);
        par.assign(n, -1);
        inv.resize(n);
        leader.assign(n, 0);
        _dfs_sz();
        _dfs_hld();
    }

private:
    void _dfs_sz(int v = 0) {
        siz[v] = 1;
        if ((int)(*g)[v].size() && (*g)[v][0] == par[v]) swap((*g)[v][0], (*g)[v].back());
        for (int &nv: (*g)[v]) {
            if (nv == par[v]) continue;
            par[nv] = v;
            _dfs_sz(nv);
            siz[v] += siz[nv];
            if (siz[nv] > siz[(*g)[v][0]]) swap(nv, (*g)[v][0]);
        }
    }

    void _dfs_hld(int v = 0, int& timer = 0) {
        in[v] = timer++;
        inv[in[v]] = v;
        for (auto nv: (*g)[v]) {
            if (nv == par[v]) continue;
            leader[nv] = (nv == (*g)[v][0]? leader[v]: nv);
            _dfs_hld(nv, timer);
        }
        out[v] = timer;
    }
};

// the in[vertexes] in heavy path are in [in[v], in[leader[v]] 
// the in[vertexes] in subtree are in [in[v], out[v])

//   val \ id      |  0  1  2  3  4  5  6  7  8  9 10 11 12
//    in[id]       |  0  9 10 11 12  7  8  1  2  5  6  3  4 
//    out[id]      | 13 13 12 12 13  9  9  7  7  7  7  5  5 
//   leader[id]    |  0  1  1  1  4  5  5  0  0  9  9  0  0 

//   val \ id      |  0  1  2  3  4  5  6  7  8  9 10 11 12
// in[leader[id]]  |  0  9  9  9 12  7  7  0  0  5  5  0  0 
//    in[id]       |  0  9 10 11 12  7  8  1  2  5  6  3  4 

//     in[id]      |  0  1  2  3  4  5  6  7  8  9 10 11 12 
//     out[id]     | 13  7  7  5  5  7  7  9  9 13 12 12 13 
//    leader[id]   |  0  0  0  0  0  9  9  5  5  1  1  1  4 
//  in[leader[id]] |  0  0  0  0  0  5  5  7  7  9  9  9 12 


//                      0(0)
//                    / | \\
//                   /  |  \\
//                  /   |   \\
//                 1(9)  5(7) 7(1)
//               // \   ||    \\
//              //   \  ||     \\
//             //    |  ||      8(2)
//             2(10) 4(12)6(8) / \\
//             ||             /   \\
//             ||            /     \\
//             3(11)        9(5)    11(3)
//                          ||      ||
//                          10(6)   12(4)

int64_t op(int64_t a, int64_t b) {
    return min(a, b);
}
int64_t e() {
    return (int64_t) 1e16;
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}