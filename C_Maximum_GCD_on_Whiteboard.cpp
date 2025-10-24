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

void solve() {
   ll n,k;
   cin>>n>>k;
   ll d=n;
   map<ll,ll> mpp;
   vector<ll> pref(n+1,0);
   for(ll i=0;i<n;i++){
    ll x;
    cin>>x;
    mpp[x]++;
   }
   for(ll i=1;i<=n;i++){
    pref[i]=pref[i-1]+mpp[i];
   }
   while(d>0){
     ll cnt=0;
     if(4*d>n){
        cnt=n;
        for(ll m=1;m*d<=n;m++){
            cnt-=mpp[m*d];
        }
     }
     else{
        cnt=pref[4*d-1];
        cnt-=mpp[d];
        cnt-=mpp[2*d];
        cnt-=mpp[3*d];
     }
     if(cnt<=k) {
        cout<<d<<endl;
        return;
     }
     d--;
   }
   
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