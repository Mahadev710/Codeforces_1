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
   vector<ll> arr(n),cnt(n+1,0);
   range(i,0,n) cin>>arr[i],cnt[arr[i]]++;

   ll x=-1;
   for(ll i=1;i<=n;i++) if(cnt[i]==0){
    x=i;
    break;
   }

   if(x==-1){
    for(ll i=0;i<k;i++) cout<<arr[n-3 + i%3]<<" ";
    cout<<endl;
   }
   
   else{
    ll y=-1;
    for(ll i=1;i<=n;i++) 
    if(i!=x && i!=arr[n-1]){
        y=i;
        break;
    }
    vector<ll> v ={x,y,arr[n-1]};
    for(ll i=0;i<k;i++) cout<<v[i%3]<<" ";
    cout<<endl;
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