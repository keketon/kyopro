typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 2e5;

vector<ll> fac(MAX);
vector<ll> finv(MAX);

ll power_MOD(ll a, ll b){
  ll ans = 1;
  while(b > 0){
    if(b&1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b = (b >> 1);
  }
  return ans;
}

void comb_ini(){
  fac[0] = 1; fac[1] = 1;
  finv[0] = 1; finv[1] = 1;
  for(ll i = 2; i <= MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    finv[i] = finv[i - 1] * power_MOD(i, MOD - 2) % MOD;
  }
}

ll comb_MOD(ll n, ll r){
  if(n < r) return 0;
  if(n < 0 || r < 0) return 0;
  if(r == 0) return 1;
  return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

int main(){
	comb_ini();
}