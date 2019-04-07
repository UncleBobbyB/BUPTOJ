#include<functional>
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
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define ll long long
#define inf 1e9
#define dinf 1e30
#define llinf 1e18
#define ull unsigned long long
#define ui unsigned int
#define eps 1e-9

//#include<cmath>
//#define pi acos(-1.0)

#define all(x) (x).begin(), (x).end()
#define ue(x) (x).erase(unique(all((x))), (x).end())

void err() {
	cout << "shit" << endl;
	exit(1);
}


int main() {
#ifdef local
	freopen("in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int nxt[100 + 10], pre[100 + 10];
	for (int i = 0; i < n; i++) {
		nxt[i] = i + 1;
		nxt[i] %= n;
		pre[nxt[i]] = i;
	}
	int cur = 0;
	for (int epoch = 0; epoch < n; epoch++) {
		int who = cur;
		for (int i = 0; i < m - 1; i++) {
			who = nxt[who];
		}
		cur = nxt[pre[who]] = nxt[who];
		pre[cur] = pre[who];
		cout << (who + 1) << ' ';
	}

	return 0;
}





















