/*
        ॐ श्रीकृष्णाय नमः ॐ
        ----------------------------------------
        |      Author: Mahadev Keshari        |
        ----------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200'005;

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
   map<ll,ll> cnt;
   ll arr[MAXN];
   for(ll i=0;i<n;i++) cin>>arr[i];
   for(ll i=0;i<n;i++) cnt[arr[i]]++;

   ll base=0;
   vector<ll> odd,even;
   for(auto [x,c] :cnt){
    //by this we take out max even number for pairing from  (odd as well as even number )frequencies base+=x*(c/2);  
    base+=x*(c/2);
    if(c%2==1) odd.push_back(x);
    else if(c>=2)even.push_back(x);
   }
   if(base==0){
    cout<<0<<endl;
    return;
   }
   ll ans=0;
   //Checking the 2nd case
   for(ll x:odd){
    if(2*base >x) {
        ans=max(ans,2*base+x);
    }
   }

   assert(is_sorted(odd.begin(),odd.end()));
   // checking the third case
   for(ll i=1;i< odd.size();i++){
    if(odd[i-1]+2*base > odd[i]){
        ans=max(ans,odd[i-1] +2*base +odd[i]);
    }

   }
   for(ll x: even){
    if(base-x >0){
        ans=max(ans,2*base);
    }
   }
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