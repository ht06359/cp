#include<bits/stdc++.h>
using namespace std;

template<typename T, auto op, auto e>
struct segment_tree {
    int n, siz;
    vector<T> dat;
    segment_tree (int _n) {
        n = _n;
        siz = __lg(n) + 2;
        dat.assign(1 << siz, e());
    };

    void update(int i, T x) {
        i += (1 << (siz-1));
        dat[i] = x;
        while (i > 1) {
            i >>= 1;
            dat[i] = op(dat[i << 1], dat[(i << 1) | 1]);
        }
    }

    T get(int i) {
        return dat[i + (1<<(siz-1))];
    }

    T prod(int l, int r) {
        return _prod(l, r, 1, 0, 1<<(siz-1));
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

int64_t op(int64_t a, int64_t b) {
    return min(a, b);
}
int64_t e() {
    return (1ll<<31)-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tt;
    cin >> n >> tt;
    segment_tree<int64_t, op, e> s(n);
    for (;tt--;) {
        int t;
        int64_t a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            cout << s.prod(a, b+1) << endl;
        } else {
            s.update(a, b);
        }
    }
}