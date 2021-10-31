#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(a) begin(a), end(a)
#define deb(x) cout << #x << " = " << x << endl
#define debu(x, y) cout << "( " << #x << ", " << #y << " ) = ( " << x << ", " << y << " )" << endl
#define logarr(arr) for(int z=(0); z<((int)arr.size()); z++) cout << (arr[z]) << " "; cout << endl
#define int long long

int mod = 998244353;
const int N = 1024;

// dp[i][mask] --> upto i th element and mask with last digit selected is k
// dp[for the first i contests][set of contests participated so far][the kind of last participated contest]={the number of possible combinations}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; string s;
	cin >> n >> s;
	long long dp[1024][1024][10] = {0};

	for(int i=1; i<=n; i++) {
		// for i th contest
		int v = (s[i-1] - 'A');
		for(int j=1; j<N; j++) {
			for(int k=0; k<10; k++) {
				(dp[i][j][k] += dp[i-1][j][k]) %= mod;		// as it is copy
				if(k == v) {
					(dp[i][j][k] += dp[i-1][j][k]) %= mod;
				}
			}
		}
		for(int j=1; j<N; j++) {
			if(j & (1 << v)) continue;
			for(int k=0; k<10; k++) {
				(dp[i][j | (1 << v)][v] += dp[i-1][j][k]) %= mod;
			}
		}
		(dp[i][1<<v][v] += 1) %= mod;
	}

	int ans = 0;
	for(int j=1; j<N; j++) {
		for(int k=0; k<10; k++) {
			(ans += dp[n][j][k]) %= mod;
		}
	}

	cout << ans << "\n";

	return 0;
}
