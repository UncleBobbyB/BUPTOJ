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

//#include<cmath>
//#define PI acos(-1.0)

#define all(x) (x).begin(), (x).end()
#define ue(x) (x).erase(unique(all((x))), (x).end())

void err() {
  cout << "shit" << endl;
  exit(1);
}

inline bool cmp(char o1, char o2) {
    if (o1 == '(') {
        return false;
    }
    if (o2 == '+' || o2 == '-') {
        return true;
    }
    return o1 == '*' || o1 == '/';
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string exp;
  cin >> exp;

  string ans;
  stack<char> st;
  for (int i = 0; i < (int)exp.length(); i++) {
      if (isdigit(exp[i])) {
          ans.pb(exp[i]);
      } else {
          if (exp[i] == '(') {
              st.push(exp[i]);
          } else if (exp[i] == ')') {
              while (st.top() != '(') {
                  ans.pb(st.top());
                  st.pop();
              }
              st.pop();
          } else {
              while (!st.empty() && cmp(st.top(), exp[i])) {
                  ans.pb(st.top());
                  st.pop();
              }
              st.push(exp[i]);
          }
      }
  }

  while (!st.empty()) {
      ans.pb(st.top());
      st.pop();
  }

  stack<double> togo;
  for (int i = 0; i < (int)ans.length(); i++) {
      if (isdigit(ans[i])) {
          togo.push(ans[i] - '0');
      } else {
          char op = ans[i];
          double a[2];
          for (int j = 0; j < 2; j++) {
              assert(!togo.empty());
              a[j] = togo.top();
              togo.pop();
          }
          if (op == '+') {
              togo.push(a[0] + a[1]);
          } else if (op == '-') {
              togo.push(a[0] - a[1]);
          } else if (op == '*') {
              togo.push(a[0] * a[1]);
          } else if (op == '/') {
              assert(a[0] > 0);
              togo.push(a[1] / a[0]);
          } else {
              err();
          }
      }
  }
  assert(togo.size() == 1);

  cout << fixed << setprecision(2) << togo.top() << endl;
  for (int i = 0; i < (int)ans.length(); i++) {
      cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}





















