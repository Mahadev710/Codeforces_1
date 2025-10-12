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
string binary(long long x)
{
    string ans="";
    while (x>0)
    {
        if (x%2==1) {ans+='1';}
        else {ans+='0';};
        x/=2;
    };
    return ans;
}
 
bool check(string s)
{
    long long n=s.size(), i;
    if (n%2==1 && s[n/2]=='1') {return false;};
    for (i=0; i<n-1-i; i++)
    {
        if (s[i]!=s[n-1-i]) {return false;};
    };
    return true;
}

void solve() {
   ll n;
   cin>>n;
   if(n==0) {
    cout<<"YES"<<endl;
    return ;
   }
//    if(n%2 ==0) {
//       
//     if(check(ans)){
//         cout<<"YES";

//     }
//     else{
//         cout<<"NO";
//     }

//    }
//     else {
//       string ans=binary(n);
//     if(check(ans)){
//         cout<<"YES";

//     }
//     else{
//         cout<<"NO";
//     }

//    }
   ll i =0;
   string s=binary(n);
   while(i<n && s[i]=='0') i++;
   while(i--) s+='0';
   if(check(s)) cout<<"Yes";
   else cout<<"No";
   cout<<endl;
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