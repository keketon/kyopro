#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2){
  
  int l1 = s1.size();
  int l2 = s2.size();
  
  if(l1 == 0 || l2 == 0) return 0;
  
  vector< vector<int> > lcs(l1, vector<int> (l2, 0));
  
  bool isFound = false;
  
  for(int i = 0; i < l1; i++){
    if (isFound || s1[i] == s2[0]){
      lcs[i][0] = 1;
      isFound = true;
    }
  }
  
  isFound = false;
  for(int i = 0; i < l2; i++){
    if (isFound || s2[i] == s1[0]){
      lcs[0][i] = 1;
      isFound = true;
    }
  }
  
  int max_len = 0;

  for(int i = 0; i < l1 - 1; i++){
    for(int j = 0; j < l2 - 1; j++){
      
      if(s1[i+1] == s2[j+1]){
        lcs[i+1][j+1] = lcs[i][j] + 1;
        max_len = max(lcs[i+1][j+1], max_len);
      }else{
        lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
      }
      
    }
  }
  return max_len;
}

int main(){
  
  int n; cin >> n;
  
  for(int i = 0; i < n; i++){
    string s1, s2; cin >> s1 >> s2;
    cout << LCS(s1, s2) << endl;
  }
  
}