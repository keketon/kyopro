#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
  int r, c, sy, sx, gy, gx; cin >> r >> c >> sy >> sx >> gy >> gx;
  vector<string> field(r);
  for(int i = 0; i < r; i++) cin >> field[i];
  
  sy--; sx--; gy--; gx--;
  
  vector<vector<int>> step(r, vector<int> (c, -1));
  queue<pair<int, int>> que;
  
  step[sy][sx] = 0;
  que.push(make_pair(sy, sx));
  
  while(!que.empty()){
    pair<int, int> v = que.front();
    int y = v.first;
    int x = v.second;
    que.pop();
    
    for(int dist = 0; dist < 4; dist++){
      int yn = y + dy[dist];
      int xn = x + dx[dist];
      if(yn < 0 || yn >= r || xn < 0 || xn >= c) continue;
      if(field[yn][xn] == '#') continue;
      if(step[yn][xn] != -1) continue;
      
      step[yn][xn] = step[y][x] + 1;
      que.push(make_pair(yn, xn));
    }
  }
  
  cout << step[gy][gx] << endl;
  
}