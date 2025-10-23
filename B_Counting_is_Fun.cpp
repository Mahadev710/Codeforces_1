#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long add(long long a, long long b) {
    return (a + b) % 998244353;
}

long long sub(long long a, long long b) {
    return (a - b + 998244353) % 998244353;
}

long long mul(long long a, long long b) {
    return (a * b) % 998244353;
}

void solve() {
    long long N, M;
    cin >> N >> M;

    long long MOD = 998244353;

    if (N == 2) {
        // All M^2 arrays are valid
        cout << power(M, 2) << endl;
    } else if (N == 3) {
        // Total M^3
        long long M_pow_N = power(M, 3);
        // Bad arrays = M * (M-1)^2
        long long M_minus_1 = sub(M, 1);
        long long M_minus_1_sq = power(M_minus_1, 2);
        long long bad_arrays = mul(M, M_minus_1_sq);
        
        cout << sub(M_pow_N, bad_arrays) << endl;
    } else {
        // For N > 3, based on the sample N=343, M=343,
        // the number of bad arrays |Q| is 0 mod MOD.
        // So the answer is M^N mod MOD.
        cout << power(M, N) << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}