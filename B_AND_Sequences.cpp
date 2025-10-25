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

bool isPowerofTwo(ll n){
    return (n>0) && ((n&(n-1))==0);
}
ll mod=1e9+7;


void solve() {
   ll n;
   cin>>n;
   vector<ll> arr(n);
   range(i,0,n) cin>>arr[i];
   ll mini=*min_element(arr.begin(),arr.end());
   ll cnt=0;
   
   for(auto x:arr){
    if(mini==x) cnt++;
    if((mini&x)!=mini) {
        cout<<0<<endl;
        return;
    }
   }
   ll fact=1;
   for(ll i=1;i<=n-2;i++) fact=(1LL*fact*i) %mod;
   ll ans=(1LL *cnt*(cnt-1))%mod;
   ans=(1LL *ans *fact)%mod;
   cout<<ans<<endl;
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