#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
#define read freopen("input.txt", "r", stdin);
#define write freopen("s1.txt", "w", stdout);
#define ll long long
#define ld long double
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  test  ll t; cin>>t; while(t--)
#define yen(f) if(f) {cout<<"YES"<<'\n';} else {cout<<"NO"<<'\n';}
//ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
//ll lcm(ll a, ll b) { return (abs((a*b))/ gcd(a,b)); }
#define Num_of_Digits(n) ((int)log10(n) + 1)
const unsigned ll N = 2e6 + 5;
bool cmb( pair<ll,ll>s1,pair<ll,ll>s2)
{
    if(s1.second==s2.second)
    {
        if(s1.first>s2.first)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(s1.second<s2.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
ll QuadraticFormula(ll a,ll b,ll c)
{

    ll x1=-((b- sqrt((b*b)-(4*a*c)))/(2*a));
    ll x2=-((b+ sqrt((b*b)-(4*a*c)))/(2*a));
    return max(x1,x2);
}
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};

vector<ll>adj[N];
vector<bool>vis(N,false);
ll random(ll min, ll max)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}



bool cycle (ll u,ll p)
{
    vis[u]=true;
    for(auto v:adj[u])
    {
        if(!vis[v])
        {
            if(cycle(v,u))
            {
                return true;
            }
        }
        else if(v!=p)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    fast
   string a,b;
    cin>>a>>b;
    ll a7= count(a.begin(), a.end(), '7');
    ll b7= count(b.begin(), b.end(), '7');
    ll ans=0;
    for (int i = 0; i < a.size(); ++i)
    {
        if(a7!=b7)
        {
            if(a7<b7)
            {
                if(a[i]=='4'&&b[i]=='7')
                {
                    a[i]='7';
                    a7++;
                    ans++;
                }
            }
            else
            {
                if(a[i]=='7'&&b[i]=='4')
                {
                    a[i]='4';
                    a7--;
                    ans++;
                }
            }
        }
    }
    ll m=0;
    for (int i = 0; i < a.size(); ++i)
    {
        if(a[i]!=b[i])
        {
            m++;
        }
    }
    m/=2;
    cout<<ans+m<<'\n';



    return 0;
}
