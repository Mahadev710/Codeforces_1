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
   if(n==2) {
    cout<<-1<<endl;
    return;
   }
   if(n==3){
    cout<< "1 3"<<endl;
    cout<<"2 3" <<endl;
    return;
   }

   if(n==4){
    cout<<"1 2"<<endl;;
    cout<<"1 3"<<endl;
    cout<<"1 4"<<endl;
    return;

   }
    cout<<"1 2"<<endl;;
    cout<<"2 3"<<endl;
    cout<<"3 4"<<endl;
    
    cout<<"1 "<<n<<endl;
   
    for(ll i=5; i<n;i++) cout<<2<<" "<<i<<endl;



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