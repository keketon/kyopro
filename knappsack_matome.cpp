#include<bits/stdc++.h>
using namespace std;

long long dp[200001];

int main(){
  
  long long ans = 0;
  int N, W; cin >> N >> W;
  vector<int> v(N), w(N);
  
  bool a = true, b = true, c = true;
  if(N > 30) a = false;
  for(int i = 0; i < N; i++){
    cin >> v[i] >> w[i];
    if(v[i] > 1000) b = false;
    if(w[i] > 1000) c = false;
  }
  
  if(c){
    ans = 0;
    for(int i = 0; i < N; i++){
      for(int j = W; j >= w[i]; j--){
        dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
      }
    }
    ans = dp[W];
    
  }else if(b){
    
    for(int i = 1; i <= 200001 ; i++){
      dp[i] = 1e17;
    }
    ans = 0;
    
    for(int i = 0; i < N; i++){
      for(int j = 200000; j >= v[i]; j--){
        dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
      }
    }
    for(int j = 200000; j >= 0; j--){
      if(dp[j] <= W) {ans = j; break;}
    }
    
  }else{
    ans = 0;
    vector<pair <long long, long long> > alpha, beta;
    int n = N/2;
    
    if(N==1 && w[0] <= W) ans = v[0];
    else if(N==1 && w[0] > W) ans = 0;
    else{
      for(int bit = 0; bit<(1<<n); bit++){
        long long Value=0, Weight=0;
        for(int j = 0; j < n; j++){
          if(bit & (1<<j)) {Value+=v[j]; Weight+=w[j];}
        }
        if(Weight <= W) alpha.push_back(make_pair(Weight, -Value));
      }
      
      for(int bit = 0; bit<(1<<N-n); bit++){
        long long Value=0, Weight=0;
        for(int j = 0; j < N-n; j++){
          if(bit & (1<<j)) {Value+=v[n+j]; Weight+=w[n+j];}
        }
        if(Weight <= W) beta.push_back(make_pair(Weight, -Value));
      }
      
      sort(alpha.begin(), alpha.end());
      sort(beta.begin(), beta.end());
      vector<pair<long long, long long> > gamma, delta;
      gamma.push_back(make_pair(alpha.at(0).first, -alpha.at(0).second));
      delta.push_back(make_pair(beta.at(0).first, -beta.at(0).second));
      for(int i = 1; i < alpha.size(); i++){
        if(-alpha.at(i).second > gamma.back().second)
          gamma.push_back(make_pair(alpha.at(i).first, -alpha.at(i).second));
      }
      
      for(int i = 1; i < beta.size(); i++){
        if(-beta.at(i).second > delta.back().second)
          delta.push_back(make_pair(beta.at(i).first, -beta.at(i).second));
      }
      int m = delta.size()-1;
      
      for(int i = 0; i< gamma.size(); i++){
        if(gamma.at(i).first + delta.at(0).first > W) break;
        while(gamma.at(i).first + delta.at(m).first > W) m--;
        ans = max(ans, gamma.at(i).second + delta.at(m).second);
      }
    }
  }
  
  cout << ans << endl;
}