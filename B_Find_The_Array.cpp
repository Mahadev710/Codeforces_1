/*
        ॐ श्रीकृष्णाय नमः ॐ
        ----------------------------------------
        |      Author: Mahadev Keshari        |
        ----------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
using ll = long long;
#define range(i, a, b) for (auto i = (a); i < (b); ++i)
#define derange(i, a, b) for (auto i = (a); i >= (b); --i)

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return n == 2;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

ll gcdll(ll a, ll b) { return b == 0 ? a : gcdll(b, a % b); }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

void solve() {
    ll n;
    cin>>n;
    ll sum=0;
    vector<ll> arr(n);
    range(i,0,n) cin>>arr[i],sum+=arr[i];
    
      
    // cur[0] — cost if we replace a[0], a[2], a[4], … with 1
    // cur[1] — cost if we replace a[1], a[3], a[5], … with 1
    
    ll curr[2]={0,0};

    range(i,0,n) curr[i%2] +=(arr[i]-1);
    
    range(j,0,2){
        if(2*curr[j]>sum){
            continue;
        }
        range(i,0,n){
            if(i%2==j) arr[i]=1;
        }
        break;
    }
    range(i,0,n) cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    fastio();
    int t = 1;
    if (!(cin >> t))
        return 0;
    while (t--)
        solve();
    return 0;
}