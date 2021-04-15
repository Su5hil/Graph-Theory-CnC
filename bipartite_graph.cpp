#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define lli long long int
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define scl(x) scanf("%lld",&x)
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

vi arr[2001];
int vis[2001];
int col[2001];
bool dfs(int node, int c) {
  vis[node] = 1;
  col[node] = c;
  for (int child : arr[node]) {
    if (vis[child] == 0) {
      if (dfs(child, c ^ 1) == false)
        return false;
    }
    else {
      if (col[node] == col[child]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  cin >> t;
  for (int j = 1; j <= t; j++) {
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= n; k++) {
      arr[k].clear();
      vis[k] = 0;
    }
    for (int k = 1; k <= m; k++) {
      int a, b;
      cin >> a >> b;
      arr[a].pb(b);
      arr[b].pb(a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        bool res = dfs(i, 0);
        if (res == false) {
          flag = false;
        }
      }
    }
    cout << "Scenario #" << j << ":" << '\n';
    if (flag == false)
      cout << "Suspicious bugs found!" << '\n';
    else
      cout << "No suspicious bugs found!" << '\n';
  }
  return 0;
}
