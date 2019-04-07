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

vector<int> h;
inline int get(int x) {
	return lower_bound(all(h), x) - h.begin();
}

int main() {
#ifdef local
	freopen("in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int a[30];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		h.pb(a[i]);
	}
	sort(all(h));
	ue(h);
	int son[30][2];
	for (int i = 0; i < n; i++) {
		son[i][0] = son[i][1] = -1;
	}
	int root = a[0];
	for (int i = 1; i < n; i++) {
		int cur = root;
		while (true) {
			int id = get(cur);
			if (a[i] < cur) {
				if (son[id][0] == -1) {
					son[id][0] = a[i];
					break;
				} else {
					cur = son[id][0];
				}
			} else {
				if (son[id][1] == -1) {
					son[id][1] = a[i];
					break;
				} else {
					cur = son[id][1];
				}
			}
		}
	}
	int m;
	cin >> m;
	bool ok = false;
	function<void(int, int, int)> print = [&](int u, int dep, int togo) -> void {
		int id = get(u);
		if (dep == togo) {
			if (u != -1) {
				cout << u << ' ';
				ok = true;
			}
			return ;
		}
		for (int i = 0; i < 2; i++) {
			print(son[id][i], dep + 1, togo);
		}
	};
	print(root, 1, m);
	if (!ok) {
		cout << -1 << '\n';
	}

	return 0;
}





















