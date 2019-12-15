#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind{
  
  // -----0-indexed----- //
  
  vector<ll> par;
  vector<ll> siz;
  
  UnionFind(ll sz_): par(sz_), siz(sz_, 1){
    for(ll i = 0; i < sz_; i++) par[i] = i;
  }
  void init(ll sz_){
    par.resize(sz_);
    siz.assign(sz_, 1);
    for(ll i = 0; i < sz_; i++) par[i] = i;
  }
  
  
  ll root(ll x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  
  bool merge(ll x, ll y){
    ll rx = root(x);
    ll ry = root(y);
    if(rx == ry) return false;
    if(siz[rx] < siz[ry]) swap(rx, ry);
    siz[rx] += siz[ry];
    par[ry] = rx;
    return true;
  }
  
  bool issame(ll x, ll y){
    return root(x) == root(y);
  }
  
  ll size(ll x){
    return siz[root(x)];
  }
};

int main(){
  ll N, K, L; cin >> N >> K >> L;
  UnionFind rd(N), rw(N);
  vector< pair<ll, ll> > grp(N);
  map< pair<ll, ll>, ll > cnt;
  
  for(ll k = 0; k < K; k++){
    ll p, q; cin >> p >> q;
    rd.merge(p-1, q-1);
  }
  for(ll l = 0; l < L; l++){
    ll r, s; cin >> r >> s;
    rw.merge(r-1, s-1);
  }
  
  
  for(ll i = 0; i < N; i++){
    grp[i] = pair<ll, ll> (rd.root(i), rw.root(i));
    cnt[grp[i]]++;
  }
  
  for(ll i = 0; i < N; i++){
    cout << cnt[grp[i]] << ' ';
  }
}