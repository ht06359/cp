#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, w;
    cin >> n >> h >> w;
    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = p[i].second;
    }
    vector<int> dp(n+1, inf);
    dp[0] = -inf;