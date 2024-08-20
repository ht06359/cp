#include<bits/stdc++.h>
using namespace std;

vector<int> on_diameter;
int64_t _diameter(const vector<vector<pair<int,int>>> &g) {
    int n = g.size();
    int res = -1, id = -1;
    priority_queue<pair<int64_t,int>, vector<pair<int64_t,int>>, greater<pair<int64_t,int>>> q;
    vector<int64_t> dist(n, 3e18);
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [d, v] = q.top();q.pop();
        if (dist[v] <= d) continue;
        dist[v] = d;
        if (res < dist[v]) {
            res = dist[v];
            id = v;
        }
        for (auto [nv, D]: g[v]) {
            if (dist[nv] <= dist[v] + D) continue;
            q.emplace(dist[v] + D, nv);
        }
    }
    //free(&q);
    priority_queue<tuple<int64_t,int,int>, vector<tuple<int64_t,int,int>>, greater<tuple<int64_t,int,int>>> pq;
    dist.assign(n, 3e18);
    pq.emplace(0, id, -1);
    vector<int> prv(n, -1);
    res = -1;
    while (!pq.empty()) {
        auto [d, v, p] = pq.top();pq.pop();
        if (dist[v] <= d) continue;
        dist[v] = d;
        prv[v] = p;
        if (res < dist[v]) {
            res = dist[v];
            id = v;
        }
        for (auto [nv, D]: g[v]) {
            if (dist[nv] <= dist[v] + D) continue;
            pq.emplace(dist[v] + D, nv, v);
        }
    }
    while (id != -1) {
        on_diameter.emplace_back(id);
        id = prv[id];
    }
    return res;
};

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < n-1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    cout << _diameter(g) << " " << on_diameter.size() << endl;
    for (auto x: on_diameter) cout << x << " ";
    cout << endl;
}