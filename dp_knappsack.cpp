#include<bits/stdc++.h>
using namespace std;

const int N_MAX = ??;
const int W_MAX = ??;

int dp[N_MAX+1][W_MAX+1];

int main(){
  
  int N, W; cin >> N >> W;
  vector<int> val(N), wei(N);
  for(int i = 0; i < N; i++){
    /*
    順番チェック
    */
    cin >> wei[i] >> val[i];
  }
  
  memset(dp, 0, sizeof(dp));
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < W; j++){
      if(j + 1 >= wei[i])
        dp[i+1][j+1] = max(dp[i][j+1], dp[i][j+1 - wei[i]] + val[i]);
      else dp[i+1][j+1] = dp[i][j+1];
    }
  }
  
  cout << dp[N][W] << endl;
}