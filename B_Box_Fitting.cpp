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
   ll n,box_width,w;
   cin>>n>>box_width;
   vector<ll> cnt(20);

   for(ll i=0;i<n;i++){
    cin>>w;
    cnt[log2(w)]++;
   }
   ll height=1,space_left=box_width;

   range(iter,0,n){
    ll largest=-1;
    for(ll size=19;size>=0 ; size--){
        if(cnt[size] and (1<<size)<=space_left){
            largest= size;
            break;
        }
    }
    if(largest==-1){
        space_left=box_width;
        height++;
        for(ll size=19; size>=0;size--){
            if(cnt[size] and (1<<size) <=space_left){
                largest=size;
                break;
            }
        }
    }
    cnt[largest]-=1;
    space_left-=1<<largest;

   }
   cout<< height<<endl;
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