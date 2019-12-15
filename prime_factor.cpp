#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 30000;
vector<long long> dp(1, 0);

vector<int> prime_l(int N) {
  deque<bool> is_prime(N + 1, true);
  vector<int> res;
  for(int i = 2; i <= N; i++){
    if(is_prime[i]){
      for(int j = i * i; j <= N; j += i){
        is_prime[j] = false;
      }
      res.emplace_back(i);
    }
  }
  return res;
}

vector<int> prime_f(int N) {
  int sn = sqrt(N) + 1;
  vector<int> prime_list = prime_l(N);
  vector<int> res;
  for(int i = 0, en = prime_list.size(); i <en; i++){
    int r = prime_list[i];
    if(r * r > N) break;
    int tmp = 0;
    while(!(N % r)) {
      N /= r;
      tmp++;
    }
    res.emplace_back(tmp);
  }
  if(N > 1) res.emplace_back(1);
  //cau
  
  return res;
}

int main(){
  
  int N; cin >> N;
  
  vector<int> a = prime_f(N);
  for(auto e: a){
    cout << e << endl;
  }
}