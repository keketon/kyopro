#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N_MAX = 30000;
vector<ll> dp(1, 0);

int main(){
  
  int N; cin >> N;
  vector<int> c(N);
  
  for(int i = 0; i < N; i++){
    cin >> c[i];
  }
  
  dp.push_back(c[0]);
  
  for(int i = 1; i < N; i++){
    if (dp.back() < c[i]) dp.push_back(c[i]);
    else{
      auto it = lower_bound(dp.begin(), dp.end(), c[i]);
      dp[it - dp.begin()] = c[i];
    }
  }
  
  cout << dp.size() - 1<< endl;
}