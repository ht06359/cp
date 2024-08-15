#include<bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
int dr[] = {1, 0, -1, 0, 1};

vector<int64_t> fac;
vector<int64_t> invfac;
int64_t powmod(int64_t a, int64_t p) {
    int64_t res = 1;
    int64_t mul = a;
    for (; p > 0; p >>= 1, mul = (mul * mul) % mod) {
        if ((p & 1) == 1) res = (res * mul) % mod;
    }
    return res;
}
int64_t inv(int64_t a) {
    return powmod(a, mod - 2);
}
void set_factorial(int n) {
    fac.resize(n + 1);
    invfac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    invfac[n] = powmod(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1);
        invfac[i] %= mod;
    }
}
int64_t C(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long x, y;
    cin >> x >> y;
    set_factorial(max(x, y)+1);
    if ((x + y) % 3 == 0 && 2 * y >= x && 2 * x >= y) {
        cout << C((x+y)/3, (2 * y - x)/3) << endl;
    } else {
        cout << 0 << endl;
    }
}