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

ll query(ll t,ll l, ll r){
    cout<<t<<" "<<l<<" "<<r<<endl;
    ll sum;
    cin>>sum;
    return sum;
}

void solve() {
   ll n;
   cin>>n;
   ll l=1,r=n;
   ll s1=query(1,1,n);
   ll s2=query(2,1,n);

   ll len=s2-s1,piv=n;
   
   while(l<=r){
    ll mid=(l+r)/2;
    ll a=query(2,1,mid);
    ll p=query(1,1,mid);
    ll diff=a-p;
    if(diff==0) l=mid+1;
    else if(diff==len) r=mid-1,piv=mid;
    else {
       cout<<"! "<<mid-diff+1<<" "<<mid+len-diff<<endl;
       return;
    }
   }
   cout<<"! "<<piv-len+1<<" "<<piv<<endl;



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