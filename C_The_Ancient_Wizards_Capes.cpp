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

bool find(vector<ll> &x,ll n, vector<ll> & a){
    ll vis=1;
    for(ll i=2;i<=n;i++) if(x[i]==1) vis++;
    if(vis !=a[1]){
        return false;
    }
    for(ll i=1;i<n;i++){
        if(x[i]==1 && x[i+1]==1) vis--;
        else if (x[i]==0 && x[i+1]==0) vis++;
        if(a[i+1] != vis) {
            return false;
        }

    }
    return true;

}

void solve() {
   ll n;
   cin>>n;
   vector<ll> arr(n+1);
   for(ll i=1;i<=n;i++)cin>>arr[i];
   bool flag=true;
   for(ll j=1;j<n;j++) {
    if(arr[j+1] - arr[j] > 1) {
        flag=false;
        break;
    }
   }
   if(!flag) {
    cout<<0<<endl;
    return;
   }
   vector<ll> sol1(n+1);
   vector<ll> sol2(n+1);
   sol2[1] = 1;
   sol1[1] = 0;

    for(ll j=1;j<n;j++){
        if(arr[j+1]-arr[j]==0){
           sol1[j + 1] = 1 - sol1[j];
            sol2[j + 1] = 1 - sol2[j];
        }
        else{
            sol1[j + 1] = sol1[j];
            sol2[j + 1] = sol2[j];
        }
    }
    ll cnt=0;
    if(find(sol1,n,arr)){
        cnt++;
    }
    if(find(sol2,n,arr)){
        cnt++;
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