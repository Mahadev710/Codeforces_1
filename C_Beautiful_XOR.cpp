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
   ll a,b;
   cin>>a>>b;
   ll c=a|b;
   if(a==b) {cout<<0<<endl;
   return;
}
 ll p=1;
   while(p<=a){
    p*=2;
   }

   if(b>=p){
    cout<<-1<<endl;
    return;
   } 
   int y1=a^c;
   int y2=c^b;
   if(y1==0){
    cout<<1<<endl;
    cout<<y2<<endl;
   }
   else if(y2==0){
     cout<<1<<endl;
    cout<<y1<<endl;
   }
   else{
    cout<<2<<endl;
    cout<<y1<<" "<<y2<<endl;
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