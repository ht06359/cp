template<typename T> 
struct fenwick_tree {
    int siz;
    vector<T> b;
    fenwick_tree(int n) : siz(n), b(n + 1, T()) {
    };
    // add X on b[id] (0-indexed)
    void add(int id, T x) {
        int i = id + 1;
        while (i <= siz) {
            b[i] += x;
            i += i & -i;
        }
    }
    // return sum of [0, id) (0-indexed)
    T sum(int id) {
        int i = id;
        T res = 0;
        while (i > 0) {
            res += b[i];
            i -= i & -i;
        }
        return res;
    }
    // return sum of [l, r) (0-indexed)
    T sum(int l, int r) {
        assert(0 <= l && l <= siz);
        assert(0 <= r && r <= siz);
        if (l <= r) return this->sum(r) - this->sum(l);
        else return this->sum(r) + this->sum(l, siz);
    }
    // return the smallest index which "sum of [0, ??) >= input" is correct  
    // return siz when there's no index needed
    int lower_bound(T x) {
        int res = 0;
        T t = x;
        int k = 1;
        while (k << 1 <= siz) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (res + k <= siz && b[res + k] < t) {
                t -= b[res + k];
                res += k;
            }
        }
        return res;
    }
};

    /*
    // return the smallest index which "sum of [0, ??) > input" is correct  
    // return siz+1 when there's no index needed
    int upper_bound(T x) {
        int res = 0;
        T t = x;
        for (int k = __lg(siz); k > 0; k >>= 1) {
            if (res + k <= siz && b[res + k] <= t) {
                t -= b[res + k];
                res += k;
            }
        }
        cout << siz << endl;
        return res;
    }
    // add X to the elements of [l, r)
    void imos(int l, int r, T x) {
        this->add(l, x);
        this->add(r, -x);
    }
    */

