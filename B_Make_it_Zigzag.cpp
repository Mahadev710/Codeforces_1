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
   ll n;
   cin>>n;
   vector<ll> arr(n),ans(n);

   ll maxi=0;
   range(i,0,n) {cin>>arr[i];
    maxi=max(maxi,arr[i]);
   if(i&1) {
    
    ans[i]=maxi;
   }
}
ll cnt=0;
  for(ll i=0;i<n;i++){
   
    if(i& 1){
        if(arr[i-1] >=ans[i] and i>=1){ cnt+=(arr[i-1]-ans[i]+1);
        arr[i-1]-=(arr[i-1]-ans[i] +1);}
       if(arr[i+1] >=ans[i] and i<n-1){ cnt+=(arr[i+1]-ans[i]+1);
        arr[i+1]-=(arr[i+1]-ans[i] +1);}
    } 
  }
  cout<<cnt<<endl;
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