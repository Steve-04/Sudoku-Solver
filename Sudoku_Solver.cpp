#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<long long int> vi;
typedef pair<long long int,long long int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n >> i) & 1)
#define maxArr(a,n) *max_element(a,a+n)
#define minArr(a,n) *min_element(a,a+n)
#define maxVec(a) *max_element(a.begin(), a.end())
#define minVec(a) *min_element(a.begin(), a.end())
#define cinl(i) ll i; cin>>i;
#define cins(s) string s; cin>>s;
#define cind(d) ld d; cin>>d;
#define fori(n) for(ll i=0; i<n; i++)
#define cinal(a,n) ll a[n]; fori(n) { cin>>a[i]; }
#define cinvl(v,n) vi v(n); fori(n) { cin>>v[i]; }
#define all(v) (v).begin(), (v).end()
#define cn(n) cout<<n<<"\n";
#define cs(n) cout<<n<<" ";

inline ll lcm(ll a, ll b) {return (a*b)/__gcd(a,b);}
inline ll llpow(ll a, ll b) {return (ll)(pow(a,b) + 0.5);}

#define PI 3.14159265
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld EPS = 1e-6;

bool isV(char ch) { return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'); }

ll cOdd(vi v,ll n) { ll count=0; fori(n) if(v[i]&1) count++; return count; }

map<ll,ll> freq(vi v, ll n) { map<ll,ll> m; fori(n) m[v[i]]++; return m; }

//To remove all occurences of a character c in a string str
//str.erase(remove(str.begin(), str.end(), c), str.end());

//std::vector<int>::iterator low1;

bool isSafe(ll row, ll col, vector<vi> &board, ll value)
{
    //row
    rep(i,0,board.size())
    {
        if((board[row][i] == value) || (board[i][col] == value))
            return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == value)
            return false;
    }
    return true;
}

bool go(vector<vi> &board)
{
    ll n=9;

    rep(row,0,n)
    {
        rep(col,0,n)
        {
            if(board[row][col] == 0)
            {
                rep(val,1,10)
                {
                    if(isSafe(row,col,board,val))
                    {
                        board[row][col]=val;
                        bool isPossible=go(board);
                        if(isPossible)
                            return true;
                        else
                        {
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    ll n=9;
	vector<vi> board(n,vi(n,0));

    rep(i,0,n)
    {
        rep(j,0,n)
        {
            cinl(x);
            board[i][j]=x;
        }
    }

    go(board);

    cout<<"\nSOLUTION:\n";
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

    return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}

    return 0;
}
