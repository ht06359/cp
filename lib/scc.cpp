#include<bits/stdc++.h>
using namespace std;

// verified
// https://atcoder.jp/contests/abc296/submissions/56589427

struct scc{
    int N;
    vector<bool> seen;
    vector<int> vs, topo_order;
    vector<vector<int>> g, rg, group;

    scc(int n) {
        N = n;
        g.resize(N + 1);
        rg.resize(N + 1);
        seen.assign(N + 1, false);
        topo_order.resize(N + 1);
    };
    
    void add_edge(int from, int to) {
        g[from].push_back(to);
        rg[to].push_back(from);
    };

    void dfs(int v) {
        seen[v] = true;
        for (auto nv: g[v]) {
            if (seen[nv] == false) dfs(nv);
        }
        vs.push_back(v);
    };

    void rdfs(int v, int k) {
        seen[v] = true;
        topo_order[v] = k;
        for (auto nv: rg[v]) {
            if (seen[nv] == false) rdfs(nv, k);
        }
        group[k].push_back(v);
    };

    int set() {
        vs.clear();
        for (int v = 0; v < N; v++) {
            if (seen[v] == false) dfs(v);
        }
        seen.assign(N + 1, false);
        int k = 0;
        for (int i = (int) vs.size() - 1; i >= 0; i--) {
            if (seen[vs[i]] == false) {
                group.push_back({});
                rdfs(vs[i], k++);
            }
        }
        return k;
    };
};