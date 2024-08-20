#include<bits/stdc++.h>
using namespace std;


// LowLink

vector<int> ord;
vector<int> low;
vector<int> cnt;
vector<pair<int,int>> bridge;
vector<bool> art_point;
vector<bool> par;
int k = 0;
// articulation points/bridges
void dfs(int v, int p, vector<vector<int>> const &g) {
    low[v] = ord[v] = k++;
    int count = 0;
    for (int nv: g[v]) {
        if (ord[nv] == -1) {
            count++;
            dfs(nv, v, g);
            low[v] = min(low[v], low[nv]);
        } else {
            low[v] = min(low[v], ord[nv]);
        }
    }
    cnt[v] = count;
};
void lowlink(vector<vector<int>> const &g) {
    int n = g.size();
    ord.assign(n, -1);
    low.assign(n, -1);
    cnt.assign(n, 0);
    par.assign(n, false);
    art_point.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (ord[i] == -1) {
            dfs(i, -1, g);
            par[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int nv: g[i]) {
            if (ord[i] <= low[nv]) flag = true;
        }
        art_point[i] = ((par[i] == true) && (cnt[i] > 1)) || ((par[i] != true) && flag); 
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    lowlink(g);
    for (int i = 0; i < n; i++) {
        if (art_point[i]) cout << i << " ";
    }
    cout << endl;
}