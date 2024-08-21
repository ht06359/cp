#include<bits/stdc++.h>
using namespace std;

const uint64_t x = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();

template<typename T>
struct zobrist_hash {
    map<int64_t, uint64_t> h;
};


