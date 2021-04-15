#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define lli long long int
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define scl(x) scanf("%lld",&x)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define scs(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;

vi arr[100001];
int in[100001];
vector<int> res;

bool Kahns(int n) {
  priority_queue<int, vi, greater<int> > pq;
  for (int i = 1; i <= n; i++)
  { if (in[i] == 0)
      pq.push(i);
  }
  while (!pq.empty()) {
    int curr = pq.top();
    res.pb(curr);
    pq.pop();
    for (int child : arr[curr])
    {
      in[child]--;
      if (in[child] == 0 )
        pq.push(child);
    }

    return (res.size() == n);
  }

  int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
      arr[x].pb(y);
      in[y]++;

    }

    if (!Kahns(n))
      cout << "Sandro fails.";
    else
    {
      for (int node : res)
        cout << node << " ";
    }
    return 0;
  }
