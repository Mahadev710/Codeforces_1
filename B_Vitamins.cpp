/*
        ॐ श्रीकृष्णाय नमः ॐ
        ----------------------------------------
        |      Author: Mahadev Keshari        |
        ----------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
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
ll n;
map<string,ll> mpp;

void read() {
  cin>>n;
  for(ll i=0;i<n;i++){
    ll c;
    cin>>c;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(mpp.count(s)==0){
        mpp[s]=c;
    }
    else mpp[s]= min(mpp[s],c);
  }
}
ll getC(string a,string b){
    if(!mpp.count(a) || !mpp.count(b)) return INF;
    return mpp[a]+mpp[b];
}

void solve(){
    ll ans=INF;
    if(mpp.count("A") && mpp.count("B") && mpp.count("C")){
        ans=mpp["A"]+mpp["B"]+mpp["C"];
    }

    if(mpp.count("ABC")){
        ans=min(ans,mpp["ABC"]);
    }
    ans=min(ans,getC("AB","C"));
    ans=min(ans,getC("A","BC"));
    ans=min(ans,getC("AC","B"));
    ans=min(ans,getC("AB","BC"));
    ans=min(ans,getC("AB","AC"));
    ans=min(ans,getC("AC","BC"));
    if(ans==INF) {
        ans=-1;
    }
    cout<<ans<<endl;

}


int main()
{
    fastio();
    int t = 1;
 
    while (t--){
        read();
        solve();}
    return 0;
}