template<typename T>
T powmod(T a, T p, T mod) {
    T res = 1;
    T mul = a;
    for (; p > 0; p >>= 1, mul = (mul * mul) % mod) {
        if ((p & 1) == 1) res = (res * mul) % mod;
    }
    return res;
}