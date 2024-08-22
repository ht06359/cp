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
    void update(int i, T x) {
        i += (1 << n);
        dat[i] = x;
        while (i > 1) {
            i >>= 1;
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



vector<int> in, out, leader, siz, par;
vector<vector<int>> g;
int timer = 0;

void dfs_sz(int v = 0) {
    siz[v] = 1;
    if ((int)g[v].size() && g[v][0] == par[v]) swap(g[v][0], g[v].back());
    for (int &nv: g[v]) {
        if (nv == par[v]) continue;
        par[nv] = v;
        dfs_sz(nv);
        siz[v] += siz[nv];
        if (siz[nv] > siz[g[v][0]]) swap(nv, g[v][0]);
    }
}

void dfs_hld(int v = 0) {
    in[v] = timer++;
    for (auto nv: g[v]) {
        if (nv == par[v]) continue;
        leader[nv] = (nv == g[v][0]? leader[v]: nv);
        dfs_hld(nv);
    }
    out[v] = timer;
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    siz.assign(n, 0);
    in.assign(n, 0);
    out.resize(n);
    par.assign(n, -1);
    leader.resize(n, 0);
    dfs_sz();
    dfs_hld();
    cout << endl;
    for (auto x: in) cout << (x < 10? " ": "") << x << " ";
    cout << endl;
    for (auto x: out) cout << (x < 10? " ": "") << x << " ";
    cout << endl;
    cout << endl;
    for (auto x: leader) cout << (x < 10? " ": "") << x << " ";
    cout << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (in[leader[i]] < 10? " ": "")<< in[leader[i]] << " " ;
    }
    cout << endl;
    for (auto x: in) cout << (x < 10? " ": "")<< x << " ";
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (out[leader[i]] < 10? " ": "")<< out[leader[i]] << " " ;
    }
    cout << endl;
    vector<array<int, 4>> v(n);
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < n; i++) {
            cin >> v[i].at(j);
        }
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < 4; j++) {
        for (auto x: v) cout << x.at(j) <<" ";
        cout << '\n';
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int v: g[i]) cout << v << " ";
        cout << endl;
    }
    */
}