#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N_MAX = 1e9;

ll fast_pow(ll base, ll expo){
    ll ret = 1;
    while(expo > 0){
        if(expo & 1){
            ret *= base;
        }
        expo >>= 1;
        base *= base;
    }
    return ret;
}