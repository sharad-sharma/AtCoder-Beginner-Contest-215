#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(a) begin(a), end(a)
#define deb(x) cout << #x << " = " << x << endl
#define debu(x, y) cout << "( " << #x << ", " << #y << " ) = ( " << x << ", " << y << " )" << endl
#define logarr(arr) for(int z=(0); z<((int)arr.size()); z++) cout << (arr[z]) << " "; cout << endl

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	set<int> primes;
	for(auto &u: a) {	// O(1e5 sqrt 1e5)
		int tem = u;
		for(int i=2; i*i<=tem; i++) {
			if(tem%i == 0) primes.insert(i);
			while(tem%i == 0) tem /= i;
			if(tem != 1) primes.insert(tem);
		}
	}

	vector<int> mark(m+1, 0);

	for(auto &u: primes) {
		if(u == 1) continue;
		for(int j=u; j<=m; j+=u) {
			mark[j] = 1;
		}
	}

	int ans = 0;
	for(int i=1; i<=m; i++) {
		if(mark[i] == 0) ans++;
	}

	cout << ans << "\n";
	for(int i=1; i<=m; i++) {
		if(mark[i] == 0) cout << i << "\n";
	}	


	return 0;
}
