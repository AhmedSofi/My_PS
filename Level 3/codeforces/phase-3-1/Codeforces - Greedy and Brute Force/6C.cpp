#include <bits/stdc++.h>
using namespace std ;
#define read freopen("input.txt", "r", stdin);
#define write freopen("s1.txt", "w", stdout);
#define ll long long
#define ld long double
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  test  ll t; cin>>t; while(t--)
#define yen(f) if(f) {cout<<"YES"<<'\n';} else {cout<<"NO"<<'\n';}
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (abs((a*b))/ gcd(a,b)); }
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
vector<bool>vis(N, false);
vector<bool>mark(N, false);


vector<ll> solve(vector<ll>& nums)
{
    vector<ll>ans;
    for (int i = 0; i < nums.size(); ++i)
    {
        ll x=-1;
        for (int j = 0; j < nums.size(); ++j)
        {
            if(i!=j)
            {
                if(x==-1)
                {
                    x=nums[j];
                }
                else
                {
                    x= gcd(x,nums[j]);
                }
            }
        }
        ans.push_back(x);
    }
    return ans;


}
int main()
{

    fast

      ll n,a=0,cu_a=0,b=0,cu_b=0;
      cin>>n;
      deque<ll>arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        if(n==1)
        {
            cout<<"1 0"<<'\n';
            return 0;
        }
        while (!arr.empty())
        {
            if(!a&&!b)
            {
                a=arr.front();
                b=arr.back();
                cu_a++;
                cu_b++;
                arr.pop_front();
                arr.pop_back();
            }
            else
            {
                if(a<=b)
                {
                    a+=arr.front();
                    cu_a++;
                    arr.pop_front();
                }
                else
                {
                    b+=arr.back();
                    cu_b++;
                    arr.pop_back();
                }
            }

        }
        cout<<cu_a<<" "<<cu_b<<'\n';







    return 0;
}
