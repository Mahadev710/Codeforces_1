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
   ll n,k;
   cin>>n>>k;
   priority_queue<ll> pq;
   ll cnt=0;
   ll temp=n;
   for(ll i=0;i<31;i++){
    if((temp>>i )&1){
        pq.push(1<<i);
        cnt++;
    }
   }
   if(k<cnt || k>n) {
    cout<<"NO"<<endl;
    return;
   }

   while(pq.size() < k){
    ll largest=pq.top();
    pq.pop();

    pq.push(largest/2);
        pq.push(largest/2);

   }
   cout<<"YES"<<endl;
   while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
   }
   cout<<endl;
}

int main()
{
    fastio();
    int t = 1;
    // if (!(cin >> t))
    //     return 0;
    while (t--)
        solve();
    return 0;
}