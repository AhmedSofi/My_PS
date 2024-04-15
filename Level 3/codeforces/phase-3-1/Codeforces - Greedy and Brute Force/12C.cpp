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
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    map<string,ll>mp;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < m; ++i)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    sort(arr.begin(), arr.end());
    ll in=0,im=n-1,mn=0,mx=0;
    vector<ll>it;
    for (auto d:mp)
    {
        it.push_back(d.second);
    }
    sort(it.rbegin(), it.rend());
    for (int i = 0; i < it.size(); ++i)
    {
        mn+=(arr[in]*it[i]);
        mx+=(arr[im]*it[i]);
        in++;
        im--;
    }
    cout<<mn<<" "<<mx<<'\n';






    return 0;
}
