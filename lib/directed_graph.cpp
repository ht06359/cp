#include<bits/stdc++.h>
using namespace std;

// SCC(strongly connected components)
// verified by
// https://onlinejudge.u-aizu.ac.jp/status/users/ht06359/submissions/1/GRL_3_C/judge/9571723/C++17

vector<int> ord, low, cc, _s, group;
vector<bool> _in_s;
int timer = 0;
int _num = 0;
void _dfs_lowlink(const vector<vector<int>> &g, int v, int p = -1) {
    _s.emplace_back(v);
    _in_s[v] = true;
    ord[v] = low[v] = timer++;
    for (int nv: g[v]) {
        if (ord[nv] == 1e9) {
            _dfs_lowlink(g, nv, v);
            low[v] = min(low[v], low[nv]);
        } else if (_in_s[nv] == true) {
            low[v] = min(low[v], ord[nv]);
        }
    }
    if (ord[v] == low[v]) {
        int _cnt = 0;
        while (true) {
            _cnt++;
            int _v = _s.back(); 
            _s.pop_back();
            cc[_v] = _num;
            _in_s[_v] = false;
            if (_v == v) break;
        }
        group.emplace_back(_cnt);
        _num++;
    }
};

void lowlink(vector<vector<int>> const &g) {
    int n = g.size();
    ord.assign(n, 1e9);
    low.assign(n, 1e9);
    cc.assign(n, -1);
    _in_s.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (ord[i] == 1e9) {
            _dfs_lowlink(g, i);
        }
    }
};

/*
vector<int> ord, low, cc, _s;
vector<bool> _in_s;
int timer = 0;
int _num = 0;
void _dfs_lowlink(const vector<vector<int>> &g, int v, int p = -1) {
    _s.emplace_back(v);
    _in_s[v] = true;
    ord[v] = low[v] = timer++;
    for (int nv: g[v]) {
        if (ord[nv] == 1e9) {
            _dfs_lowlink(g, nv, v);
            low[v] = min(low[v], low[nv]);
        } else if (_in_s[nv] == true) {
            low[v] = min(low[v], ord[nv]);
        }
    }
    if (ord[v] == low[v]) {
        while (true) {
            int _v = _s.back(); 
            _s.pop_back();
            cc[_v] = _num;
            _in_s[_v] = false;
            if (_v == v) break;
        }
        _num++;
    }
};

void lowlink(vector<vector<int>> const &g) {
    int n = g.size();
    ord.assign(n, 1e9);
    low.assign(n, 1e9);
    cc.assign(n, -1);
    _in_s.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (ord[i] == 1e9) {
            _dfs_lowlink(g, i);
        }
    }
};
*/