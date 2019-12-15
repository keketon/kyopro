#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MAXV = 110;
const ll INF = 1e9;

struct edge{
  ll to;
  ll cost;
};

ll V;
vector<edge> G[MAXV];
ll d[MAXV];

void djikstra(ll s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+V, INF);
  d[s] = 0;
  que.push(P(0, s));
  
  while(!que.empty()){
    P p = que.top(); que.pop();
    ll v = p.second;
    if(d[v] < p.first) continue;
    
    for(ll i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  cin >> V;
  ll E;
  cin >> E;
  for(ll i = 0; i < E; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;		//“ü—Í‚Í1-indexed -> 0-indexed‚É•ÏŠ·
    edge e1 = {b, c};
    edge e2 = {a, c};
    G[a].push_back(e1);
    G[b].push_back(e2);
  }
  djikstra(0);
  for(ll i = 0; i < V; i++){
    if(d[i] != INF)
      cout << i << "‚Ü‚Å‚ÌƒRƒXƒg " << d[i] << endl;
  }
}