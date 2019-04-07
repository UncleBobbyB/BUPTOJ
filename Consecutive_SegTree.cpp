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
#define ue(x) (x).erase(unique(all((x))), (x).end())

void err() {
  cout << "shit" << endl;
  exit(1);
}

const int N = 50000 + 10;
struct Node {
  int l, r, pre, suf, maxlen, add;
} f[N << 2];

inline void pushup(int o) {
  f[o].pre = f[o << 1].pre;
  if(f[o << 1].pre == f[o << 1].r - f[o << 1].l + 1) f[o].pre += f[o << 1 | 1].pre;
  f[o].suf = f[o << 1 | 1].suf;
  if(f[o << 1 | 1].suf == f[o << 1 | 1].r - f[o << 1 | 1].l + 1) f[o].suf += f[o << 1].suf;
  f[o].maxlen = max(f[o << 1].suf + f[o << 1 | 1].pre, max(f[o << 1].maxlen, f[o << 1 | 1].maxlen));
}

inline void pushdown(int o) {
  f[o << 1].add = f[o << 1 | 1].add = f[o].add;
  f[o << 1].pre = f[o << 1].suf = f[o << 1].maxlen = f[o].add > 0 ? f[o << 1].r - f[o << 1].l + 1 : 0;
  f[o << 1 | 1].pre = f[o << 1 | 1].suf = f[o << 1 | 1].maxlen = f[o].add > 0 ? f[o << 1 | 1].r - f[o << 1 | 1].l + 1 : 0;
  f[o].add = 0;
}

void build(int o, int l, int r) {
  f[o].l = l;
  f[o].r = r;
  f[o].maxlen = f[o].pre = f[o].suf = r - l + 1;
  f[o].add = 0;
  if(l == r) return ;
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
}

void modify(int o, int l, int r, int d) {
  if(f[o].l >= l && f[o].r <= r) {
    f[o].add = d;
    f[o].pre = f[o].suf = f[o].maxlen = d > 0 ? f[o].r - f[o].l + 1 : 0;
    return ;
  }
  if(f[o].add) pushdown(o);
  int mid = (f[o].l + f[o].r) >> 1;
  if(l <= mid) modify(o << 1, l, r, d);
  if(r > mid) modify(o << 1 | 1, l, r, d);
  pushup(o);
}

int query(int o, int len) {
  if(f[o].maxlen < len) return 0;
  if(f[o].pre >= len) return f[o].l;
  if(f[o].add) pushdown(o);
  if(f[o << 1].maxlen >= len) return query(o << 1, len);
  if(f[o << 1].suf + f[o << 1 | 1].pre >= len) {
    int mid = (f[o].l + f[o].r) >> 1;
    return mid - f[o << 1].suf + 1;
  }
  return query(o << 1 | 1, len);
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif

  // ios::sync_with_stdio(false);
  // cin.tie(0);

  return 0;
}
