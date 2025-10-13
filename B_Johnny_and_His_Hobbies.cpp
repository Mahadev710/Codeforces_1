/*
        ॐ श्रीकृष्णाय नमः ॐ
        ----------------------------------------
        |      Author: Mahadev Keshari        |
        ----------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1025;
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

ll n;
ll arr[N];
bool brr[N];

bool check(ll k){
    range(i,1,n+1){
        if(!brr[arr[i] ^k] ) return false;
    }
    return true;
}

void solve() {
  
   cin>>n;
   for (int i = 0; i < N; i++) {
    brr[i] = false;
}

   range(i,1,n+1){
    cin>>arr[i];
    brr[arr[i]]=true;
   }
   range(k,1,1024){
    if(check(k)){
        cout<<k<<endl;
        return ;
    }
   }
   cout<<-1<<endl;
  

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