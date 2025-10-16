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
  string s;
  cin>>s;
  for(ll k=1;k<=10;k++){
    ll team1_score_max=0;
    ll team2_score_max=0;
    ll team1_score_min=0;
    ll team2_score_min=0;

    for(ll i=0;i<k;i++){
        if(i%2 ==0){
            if(s[i]=='1'){
                team1_score_max++;
                team1_score_min++;
            }
            else if(s[i]=='?') team1_score_max++;
        }
        else{
            if(s[i]=='1'){
                team2_score_max++;
                team2_score_min++;
            }
            else if(s[i]=='?') team2_score_max++;
        }
    }
     ll team1_rem_kicks=5-(k+1)/2;
     ll team2_rem_kicks= 5-(k)/2;
     if(team1_score_max>team2_rem_kicks+team2_score_min){
        cout<<k<<endl;
        return ;
     }
     if(team2_score_max>team1_rem_kicks+team1_score_min){
        cout<<k<<endl;
        return ;
     }
     
  }
  cout<<10<<endl;
 
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