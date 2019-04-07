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

const int N = 100 + 10;
const int M = 10000 + 10;

vector<pii> adj[N];
int dist[N];

inline void add(int u, int v, int d) {
	adj[u].pb(make_pair(d, v));
	adj[v].pb(make_pair(d, u));
}

void dijkstra(vector<pair<int, int> > adj[], int dist[], int n, int sr, int ed) {
	for (int i = 0; i < n; i++) {
		dist[i] = inf;
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(dist[sr] = 0, sr));
	bool done[n + 1];
	for (int i = 0; i < n + 1; i++) {
		done[i] = false;
	}
	while (!q.empty()) {
		int u = q.top().se;
		q.pop();
		done[u] = true;
		if (u == ed) {
			break;
		}
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i].se;
			int d = adj[u][i].fi;
			if (done[v]) {
				continue;
			}
			q.push(make_pair(dist[v] = min(dist[v], dist[u] + d), v));
			// dist[v] = min(dist[v], dist[u] + d);
		}
	}
}

int main() {
#ifdef local
	freopen("in", "r", stdin);
#endif

	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n ){
		for (int i = 0; i < m; i++) {
			int u, v, d;
			scanf("%d %d %d", &u, &v, &d);
			u--;
			v--;
			add(u, v, d);
		}

		dijkstra(adj, dist, n, 0, n - 1);
		printf("%d\n", dist[n - 1]);
	}
	return 0;
}





















