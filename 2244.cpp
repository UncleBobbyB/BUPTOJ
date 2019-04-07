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

int cnt;

void SORT(int a[], int a_end[]) {
	int n = a_end - a;
	if (n == 1) {
		return ;
	}
	int i = 0, j = n - 1, mi = a[n / 2];
	while (i < j) {
		while (i < n && a[i] <= mi) {
			i++;
		}
		while (j > 0 && a[j] > mi) {
			j--;
		}
		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	cnt++;

	if (cnt == 2) {
		for (int i = 0; i < n; i++) if (a[i] == mi) {
			for (int j = i + 1; j < n; j++) {
				cout << a[j] << ' ';
			}
			cout << '\n';
			return ;
		}
	}
	for (int i = 0; i < n; i++) if (a[i] == mi) {
		SORT(a, a + i + 1);
		break;
	}
}


int main() {
#ifdef local
	freopen("in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cnt = 0;
	SORT(a, a + n);

	return 0;
}





















