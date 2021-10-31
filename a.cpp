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

	string s;
	cin >> s;

	if(s == "Hello,World!") {
		cout << "AC" << "\n";
	} else {
		cout  << "WA" << "\n";
	}

	return 0;
}
