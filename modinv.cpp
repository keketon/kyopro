#include <bits/stdc++.h>
using namespace std;

//modÇ…Ç®ÇØÇÈãtå≥ÇãÅÇﬂÇÈ(a and m: relatively prime)
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while(b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  
}