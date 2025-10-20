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

vector<vector<ll>> adj;
set<ll> path;
vector<ll> parent;
vector<string>commands;

bool find_path(ll u,ll p,ll n){
    parent[u]=p;
    if(u==n) return true;
    for(ll v : adj[u]){
        if(v!=p) {
            if(find_path(v,u,n)) return true;
        }
    }
    return false;
}

void dfs(ll u,ll v,ll n){
    if(u==n) return;
    vector<ll> nodes;
    ll path_child=0;
    for(ll v: adj[u]){
        if(v==p) continue;
        
    }
}
 
void solve() {
   ll n;
   cin>>n;
   adj.assign(n+1,vector<int>());
   on_path.clear();
   parent.assign(n+1,0);

   commands.clear();
   for(ll i=0;i<n-1;i++){
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   find_path(1,0,n);
   ll curr=n;
   while(curr !=0){
    on_path.insert(curr);
    curr =parent[curr];
   }
   dfs(1,0,n);
   cout<<commands.size()<<endl;
   for(auto cmd: commands){
    cout<<cmd<<endl;
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