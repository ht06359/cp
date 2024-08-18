#include<bits/stdc++.h>
using namespace std;
const int64_t inf = 1e18;
// const int64_t mod = 1e9 + 7;
const int64_t mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    int flag = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        flag |= (1 << a);
    }
    vector dp(n+1, vector (1<<10, vector<long long> (2, -1)));
    dp[0][0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1<<10; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i][j][k] == -1) continue;
                int c = s[i] - '0';
                int ni = i+1, nj = j, nk = k;
                if (nj != 0) {
                    if (nk == 1) {
                        if (c == 0) nk = 1;
                        else nk = 0;
                    }
                    nj |= (1 << 0);
                    if (dp[ni][nj][nk] == -1) dp[ni][nj][nk] = 0;
                    dp[ni][nj][nk] += dp[i][j][k]*10;
                } else {
                    nk = 0;
                    if (dp[ni][nj][nk] == -1) dp[ni][nj][nk] = 0;
                    dp[ni][nj][nk] += dp[i][j][k]*10;
                }
                for (long long x = 1; x < 10; x++) {
                    ni = i+1, nj = j, nk = k;
                    if (nk == 1) {
                        if (x > c) continue;
                        else if (x == c) nk = 1;
                        else nk = 0;
                    }
                    nj |= (1 << x);
                    if (dp[ni][nj][nk] == -1) dp[ni][nj][nk] = 0;
                    dp[ni][nj][nk] += dp[i][j][k]*10 + x;
                    dp[ni][nj][nk] %= mod;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 1<<10; i++) {
        for (int j = 0; j < 2; j++) {
            if (((flag & i) == flag) && dp[n][i][j] >= 0) {
                ans += dp[n][i][j];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
}