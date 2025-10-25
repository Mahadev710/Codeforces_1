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
using ll = long long;
const int N=2e5+5;

ll fact[N];
void factorials(){
    fact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}



// void solve() {
//    ll n;
//    cin>>n;
//    vector<ll> arr(n);
//    range(i,0,n) cin>>arr[i];
//    ll mini=*min_element(arr.begin(),arr.end());
//    ll cnt=0;
   
//    for(auto x:arr){
//     if(mini==x) cnt++;
//     if((mini&x)!=mini) {
//         cout<<0<<endl;
//         return;
//     }
//    }
//    ll fact=1;
//    for(ll i=1;i<=n-2;i++) fact=(1LL*fact*i) %mod;
//    ll ans=(1LL *cnt*(cnt-1))%mod;
//    ans=(1LL *ans *fact)%mod;
//    cout<<ans<<endl;
// }

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll total_and=-1;

    for(ll i=0;i<n;i++){
        cin>>arr[i];
        total_and &= arr[i];
    }
    ll k=0;
    for(ll x:arr)
        if(x==total_and) k++;
    
    if(k<2) {
        cout<<0<<endl;
        return;
    }    
    ll ans=(k*(k-1))%mod;
    ans=(ans*fact[n-2])%mod;
    cout<<ans<<endl;
}

int main()
{
    fastio();
    int t = 1;
    factorials();
    if (!(cin >> t))
        return 0;
    while (t--)
        solve();
    return 0;
}