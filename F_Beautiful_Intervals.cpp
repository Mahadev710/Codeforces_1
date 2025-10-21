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
   ll n,m;
   cin>>n>>m;
   vector<pair<ll,ll>> arr(m+1);
   vector<ll> cnt(n+1),ans(n+1,-1);

   ll idx=-1;

   for(ll i=1;i<=m;i++){
    cin>>arr[i].first>>arr[i].second;
    for(ll j=arr[i].first;j<=arr[i].second;j++){
        cnt[j]++;
        if(cnt[j]==m) idx=j;
    }
   }
   if(idx!=-1){
    ans[idx]=0;
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        if(ans[i]!=-1) continue;
        cnt++;
        ans[i]=cnt;
    }
   }
   else{
    ll l=1,r=n;
    idx=-1;
    for(ll i=1;i<=n;i++){
        l =1,r=n;
        for(ll j=1;j<=m;j++){
            if(arr[j].first > i or arr[j].second <i) continue;
            l =max(l,arr[j].first);
            r=min(r,arr[j].second);
        }
        if(l<r){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        for(ll i=1;i<n;i++){
            ans[i]=i;
            
        }
        ans[n]=0;
    }
    else{
        ll idx2=-1;
        for(ll i=l;i<=r;i++){
            if(i!=idx){
                idx2=i;
                break;
            }
          }
        ans[idx] =0; ans[idx2]=1;
        ll cnt=1;
        for(ll i=1;i<=n;i++){
        if(ans[i]==-1){
            cnt++;
            ans[i]=cnt;
        }
  }
    }

   }
   for(ll i=1;i<=n;i++) {
    cout<<ans[i]<<" ";
   }
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