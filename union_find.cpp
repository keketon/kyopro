#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> par, sz;

ll root(ll x){
  if(par[x] == x) return x;
  return root(par[x]);
}

void unite(ll x, ll y){
  ll rx = root(x);
  ll ry = root(y);
  if(rx == ry) return;
  if(sz[rx] < sz[ry]){
    par[rx] = ry;
    sz[ry] += sz[rx];
  }else{
    par[ry] = rx;
    sz[rx] += sz[ry];
  }
}

bool same(ll x, ll y){
  return root(x) == root(y);
}


int main(){
  ll N, M; cin >> N >> M;
  vector<ll> A(M), B(M);
  
  for(ll i = 0; i < M; i++){
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  
  par.resize(N);
  sz.resize(N);
  for(ll i = 0; i < N; i++){
    par[i] = i;
    sz[i] = 1;
  }
  
  vector<ll> ans(M, 0);
  ans[M-1] = N * (N - 1) / 2;
  for(ll i = M - 2; i >= 0; i--){
    ll a = A[i + 1], b = B[i + 1];
    ll ra = root(a), rb = root(b);
    if(ra == rb) {
      ans[i] = ans[i+1]; continue;
    }
    ll sa = sz[ra], sb = sz[rb];
    ans[i] = ans[i + 1] - sa * sb;
    unite(ra, rb);
  }
  for(ll i = 0; i < M; i++){
    cout << ans[i] << endl;
  }
}