#include<bits/stdc++.h>
using namespace std;

const int H_MAX = 500;
const int W_MAX = 500;
int h, w;
char maze[H_MAX][W_MAX];
bool reached[H_MAX][W_MAX];

void dfs(int x, int y){
  if(x < 0 || w <= x || y < 0 || h <= y || maze[x][y] == '#') return;
  if(reached[x][y]) return;
  
  reached[x][y] = true;
  
  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);
}

int main(){
  cin >> h >> w;
  int sx, sy, gx, gy;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> maze[j][i];
      if(maze[j][i] == 's') {sx = j; sy = i;}
      if(maze[j][i] == 'g') {gx = j; gy = i;}
    }
  }
  
  dfs(sx, sy);
  
  cout << (reached[gx][gy]?"Yes":"No") << endl;
  
}