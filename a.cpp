#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 2 << "\n";
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    cout << "jaifjaoeijfo\n";
    s += s;
    vector<vector<int>> cnt(2*n+1, vector<int> (26, 0));
    for (int i = 0; i < 2*n; i++) {
        cout << "%ER\n";
        for (int j = 0; j < 26; j++) {
            cnt[i+1][j] = cnt[i][j];
            cout << j << "\n";
        }
        cnt[i+1][s[i%n]-'a']++;
    }
    cout << "akjfaijpe\n";
    int ans = 1;
    int have = 0;
    for (int i = 0; i < (int) t.size(); i++) {
        int l = have, r = 2*n;
        int c = t[i] - 'a';
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (cnt[m][c] - cnt[have][c] > 0) m = r;
            else m = l;
        }
        if (r >= n) ans++;
        have = r%n;
    }
    cout << ans << "\n";
}