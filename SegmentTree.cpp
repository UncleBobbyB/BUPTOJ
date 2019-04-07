#include<bitset>
#include<cassert>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<cctype>
#include<algorithm>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
#include<algorithm>
#include<set>
// #include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pli pair<LL, int>
#define pil pair<int, LL>
#define pll pair<LL, LL>
#define vi vector<int>
#define LL long long
#define INF 1e9
#define DINF 1e30
#define LLINF 1e18
#define ULL unsigned long long
#define UI unsigned int
#define eps 1e-9
#define PI acos(-1.0)

#define all(x) (x).begin(), (x).end()

void err() {
  cout << "shit" << endl;
  exit(1);
}

const int N = 1e5 + 10;
struct Node {
  int l, r;
  LL v, add, set;
} f[N << 2];

inline void pushup(int o) {
  f[o].v = f[o << 1].v + f[o << 1 | 1].v;
}

inline void pushdown(int o) {
  if(f[o].add) {
    f[o << 1].add += f[o].add;
    f[o << 1 | 1].add += f[o].add;
    f[o << 1].v += (f[o << 1].r - f[o << 1].l + 1) * f[o].add;
    f[o << 1 | 1].v += (f[o << 1 | 1].r - f[o << 1 | 1].l + 1) * f[o].add;
    f[o].add = 0;
  }else if(f[o].set >= 0) {
    f[o << 1].add = f[o << 1 | 1].add = 0;
    f[o << 1].set = f[o << 1 | 1].set = f[o].set;
    f[o << 1].v = (f[o << 1].r - f[o << 1].l + 1) * f[o].set;
    f[o << 1 | 1].v = (f[o << 1 | 1].r - f[o << 1 | 1].l + 1) * f[o].set;
    f[o].set = -1;
  }
}

void build(int o, int l, int r) {
  f[o].l = l;
  f[o].r = r;
  f[o].v = 0;
  f[o].add = 0;
  f[o].set = -1;
  if(l == r) {
    f[o].v = 1;
    return ;
  }
  int mi = (l + r) / 2;
  build(o << 1, l, mi);
  build(o << 1 | 1, mi + 1, r);
  pushup(o);
}

void add(int o, int l, int r, int d) {
  if(f[o].l >= l && f[o].r <= r) {
    if(f[o].set >= 0) pushdown(o);
    f[o].add += d;
    f[o].v += (f[o].r - f[o].l + 1) * d;
    return ;
  }
  pushdown(o);
  int mi = (f[o].l + f[o].r) / 2;
  if(l <= mi) add(o << 1, l, r, d);
  if(r > mi) add(o << 1 | 1, l, r, d);
  pushup(o);
}

void setv(int o, int l, int r, int d) {
  if(f[o].l >= l && f[o].r <= r) {
    f[o].add = 0;
    f[o].set = d;
    f[o].v = (f[o].r - f[o].l + 1) * d;
    return ;
  }
  pushdown(o);
  int mi = (f[o].l + f[o].r) / 2;
  if(l <= mi) setv(o << 1, l, r, d);
  if(r > mi) setv(o << 1 | 1, l, r, d);
  pushup(o);
}

LL query(int o, int l, int r) {
  if(f[o].r < l || f[o].l > r) return 0;
  if(f[o].l >= l && f[o].r <= r) return f[o].v;
  pushdown(o);
  return query(o << 1, l, r) + query(o << 1 | 1, l, r);
}

int getv(int o, int x) {
  if(f[o].set >= 0) return f[o].set;
  if(f[o].l == f[o].r) return f[o].v;
  pushdown(o);
  int mid = (f[o].l + f[o].r) / 2;
  if(x <= mid) return getv(o << 1, x);
  else return getv(o << 1 | 1, x);
}

int get_id(int v, int l, int r) {
  int lo = l, hi = r + 1;
  while(lo < hi) {
    int mi = lo + (hi - lo) / 2;
    if(getv(1, mi) <= v) lo = mi + 1;
    else hi = mi;
  }
  return lo;
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif

  // ios::sync_with_stdio(false);
  // cin.tie(0);

  return 0;
}
