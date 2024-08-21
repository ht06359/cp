#include<bits/stdc++.h>
using namespace std;

const std::uint64_t hashmod = 0x1fffffffffffffff;

template<typename T>
struct rolling_hash {
    vector<uint64_t> hash, p;
    int64_t n;
    
    static constexpr uint64_t mask(int64_t a){ return (1ull << a) - 1; }
    
    inline uint64_t mul(uint64_t a, uint64_t b) const {
        __uint128_t ans = __uint128_t(a) * b;
        ans = (ans >> 61) + (ans & hashmod);
        if(ans >= hashmod) ans -= hashmod;
        return ans;
    }

    rolling_hash(const T &a) {
        n = a.size();
        hash.assign(n + 1, 0);
        p.assign(n + 1, 0);
        p[0] = 1;
        for(int64_t i = 0; i < n; i++) {
            p[i + 1] = mul(p[i], base);
            hash[i + 1] = mul(hash[i], base) + (mdf + (uint64_t)a[i]);
            if(hash[i + 1] >= hashmod) hash[i + 1] -= hashmod;
        }
    }
    // get [l, r)
    uint64_t get(int64_t l, int64_t r) const {
        assert(0 <= l && l <= n);
        assert(0 <= r && r <= n);
        uint64_t ret = hash[r] + hashmod - mul(hash[l], p[r - l]);
        if(ret >= hashmod) ret -= hashmod;
        return ret;
    }

    int64_t LCP(const rolling_hash &b, int64_t l1, int64_t r1, int64_t l2, int64_t r2) {
        int64_t len = min(r1 - l1, r2 - l2);
        int64_t ok = -1;
        int64_t ng = len + 1;
        while(ng - ok > 1) {
            int64_t mid = (ok + ng) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }

    uint64_t connect(uint64_t hash1, uint64_t hash2, int64_t hash2len) const {
        uint64_t ret = mul(hash1, p[hash2len]) + hash2;
        if(ret >= hashmod) ret -= hashmod;
        return ret;
    }
};



template<typename T, typename S>
struct ms_hash {
    int _n;
    map<S, uint64_t> _map;
    vector<uint64_t> _hash;
    multiset_hash(int n, map<S, uint64_t> mp) : _n(n), _map(mp) {
        _hash.assign(_n+1, 0);
    }
    uint64_t get(int l, int r) {
        return _ha[r] - _hash[l];
    }
};

template<typename T, typename S>
struct zobrist_hash {
    map<S, uin
};
