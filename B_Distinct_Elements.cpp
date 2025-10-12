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
   vector<ll> b(n),a(n);
   range(i,0,n) cin>>b[i];
   //bi - b(i-1) =i-p 
   ll bprev=0;
   ll cnt=n;
   range(i,0,n){
    ll diff=b[i]-bprev;
    ll idx = i+1 - diff;
    if(idx ==0) {
        a[i]=cnt;
        cnt--;
    }
    else{
      ll j=idx -1;
      a[i]=a[j];
    }
    bprev=b[i];
   }
   for(ll i=0;i<n;i++){
    cout<<a[i]<<" ";
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