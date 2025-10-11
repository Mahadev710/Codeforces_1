#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

const ll LINF = 1000000000000000005;
const int MAXN = 500005;

// Your cost function for a block of size 2
ll cost2(ll x, ll y) {
    return abs(x - y);
}

// Your cost function for a block of size 3
ll cost3(ll x, ll y, ll z) {
    // This is a simple way to sort three numbers
    if (x > y) swap(x, y);
    if (y > z) swap(y, z);
    if (x > y) swap(x, y);
    return z - x; // Cost is the difference between max and min
}

// Function to run the linear DP on a given array configuration
ll solve_linear(ll n, const vector<ll>& arr) {
    if (n == 0) return 0;
    if (n == 1) return LINF; // Impossible to partition a single element

    vector<ll> dp(n + 1, LINF);

    // CRITICAL FIX: Initialize base case
    dp[0] = 0;

    for (ll i = 1; i <= n; ++i) {
        // Case 1: Last block is of size 2
        if (i >= 2 && dp[i - 2] != LINF) {
            dp[i] = min(dp[i], dp[i - 2] + cost2(arr[i - 2], arr[i - 1])); // Using 0-based indexing for vector
        }

        // Case 2: Last block is of size 3
        if (i >= 3 && dp[i - 3] != LINF) {
            dp[i] = min(dp[i], dp[i - 3] + cost3(arr[i - 3], arr[i - 2], arr[i - 1]));
        }
    }
    return dp[n];
}


void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll min_total_cost = LINF;

    // CRITICAL FIX: Loop 4 times to test different rotation points
    for (int rotation = 0; rotation < min((ll)4, n); ++rotation) {
        
        // Run the DP for the current linear arrangement
        min_total_cost = min(min_total_cost, solve_linear(n, arr));
        
        // Rotate the array to create the next linear arrangement to test
        // [1, 2, 3, 4] -> [2, 3, 4, 1]
        if (n > 0) {
            rotate(arr.begin(), arr.begin() + 1, arr.end());
        }
    }

    if (min_total_cost == LINF) {
        // This case might occur if n is 1, or cannot be partitioned (e.g., n=1)
        cout << -1 << endl; 
    } else {
        cout << min_total_cost << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
     cin >> t; // Uncomment if there are multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}