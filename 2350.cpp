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
#define pll pair<LL, LL> #define vi vector<int> #define LL long long
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

const int val[] = {7, 19, 2, 6, 32, 3, 21, 10};


int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    for (int i = 0; i < 8; i++) {
        q.push(make_pair(val[i], i));
    }
    int son[50][2], cnt = 8;
    for (int i = 0; i < 50; i++) {
        son[i][0] = son[i][1] = -1;
    }

    while (q.size() != 1) {
        pii u = q.top();
        q.pop();
        pii v = q.top();
        q.pop();
        son[cnt][0] = u.se;
        son[cnt][1] = v.se;
        q.push(make_pair(u.fi + v.fi, cnt++));
    }

    int cur = cnt - 1;

    for (int i = 0; i < (int)s.length(); i++) {
        int nxt = s[i] - '0';
        assert(son[cur][nxt] != -1);
        cur = son[cur][nxt];
        if (cur < 8) {
            cout << (char)('a' + cur);
            cur = cnt - 1;
        }
    }

    cout << endl;
  return 0;
}





















