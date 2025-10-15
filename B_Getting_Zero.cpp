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
const ll mod=32768; 
void solve() {
   ll n;
   cin>>n;
   vector<ll> arr(n);
   range (i,0,n) cin>>arr[i];
   for(auto x:arr){
    ll ans=20;
    for(ll i=0;i<=15;i++){
        for(ll j=0;j<=15;j++){
            int pos=(x+i)%mod;
            ll check=(pos<<j)%mod;
            if(check== 0) {
                ans=min(ans,i+j);
            }
        }
    }
    cout<<ans<<" ";
   }
   cout<<endl;

}

int main()
{
    fastio();
    int t = 1;
    // if (!(cin >> t))
    //     return 0;
    while (t--)
        solve();
    return 0;
}