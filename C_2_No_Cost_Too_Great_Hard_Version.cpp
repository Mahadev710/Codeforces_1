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
#define fi first
#define se second
#define N 200005
#define range(i, a, b) for (auto i = (a); i < (b); ++i)
#define derange(i, a, b) for (auto i = (a); i >= (b); --i)

pair<ll,ll> arr[N];
const ll M=200001;
vector<ll> d[N];
ll vis[N];

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
   ll n;
   cin>>n;
   for(ll i=1;i<=n;i++) cin>>arr[i].se;
   for(ll i=1;i<=n;i++) cin>>arr[i].fi;
   sort(arr+1,arr+n+1);
   ll flag=0;
   for(ll i=1;i<=n;i++){
    for(ll x:d[arr[i].se]){
        if(vis[x]) flag=1;
        else vis[x]=1;
    }
   }
   if(flag){
    puts("0");
    for(ll i=1;i<=n;i++){
        for(ll x:d[arr[i].se]) vis[x]=0;
        return;
    }
   }
   ll ans=arr[1].fi+arr[2].fi;
   
   for(ll i=1;i<=n;i++){
    if(i!=1){
        for(ll x:d[arr[i].se]) ans=min(ans,(x-arr[1].se%x)*arr[1].fi);

    }
    for(ll x: d[arr[i].se+1]) if(vis[x]) ans=min(ans,arr[i].fi );
   }
   cout<<ans<<endl;
   for(ll i=1;i<=n;i++)
      for(ll x:d[arr[i].se]) vis[x]=0;


}

int main()
{
    fastio();
    int t = 1;
    if (!(cin >> t))
        return 0;

    for(ll i=2;i<=M;i++){
        if(d[i].size()) continue;
        for(ll j=i;j<=M;j+=i) d[j].push_back(i);
    }    
    while (t--)
        solve();
    return 0;
}