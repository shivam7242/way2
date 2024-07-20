// shinzo_wo_sasageyo!!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define int long long
#define endl "\n"
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
typedef long long ll;
ll expo(ll a, ll b, ll m) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }

ll mod_add(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
/*----------------------------------------------------------------------------------------------------------*/

class DisjointSet {

public:
  vector<int> rank, parent, size;
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findUPar(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      parent[ulp_v] = ulp_u;
    } else {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};
int findIndex(int r, int c, int n, int m) {
  int ele = (r * m) + c;
  return ele;
}
int isValid(int r, int c, int n, int m) {
  if (r < 0 or r >= n or c < 0 or c >= m) {
    return 0;
  }
  return 1;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    DisjointSet ds((n * m) + 1);

    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; j++) {
        char c = a[i][j];
        if (c == '#') {
          row[i]++;
          col[j]++;

          int index = findIndex(i, j, n, m);
          if (isValid(i - 1, j, n, m) and a[i - 1][j] == '#') {
            int indexup = findIndex(i - 1, j, n, m);
            // if(i==1 and j==0){
            //     cout<<"hio "<<indexup<<endl;
            // }
            ds.unionBySize(indexup, index);
          }
          if (isValid(i + 1, j, n, m) and a[i + 1][j] == '#') {
            int indexdown = findIndex(i + 1, j, n, m);
            ds.unionBySize(indexdown, index);
            //  if(i==1 and j==0){
            //     cout<<"hio "<<indexdown<<endl;
            // }
          }
          if (isValid(i, j - 1, n, m) and a[i][j - 1] == '#') {
            int indexleft = findIndex(i, j - 1, n, m);
            ds.unionBySize(indexleft, index);
            //  if(i==1 and j==0){
            //     cout<<"hio "<<indexleft<<endl;
            // }
          }
          if (isValid(i, j + 1, n, m) and a[i][j + 1] == '#') {
            int indexright = findIndex(i, j + 1, n, m);
            ds.unionBySize(indexright, index);
            //  if(i==1 and j==0){
            //     cout<<"hio "<<indexright<<endl;
            // }
          }
        }
      }
    }
    // cout<<findIndex(1,0,n,m)<<endl;
    // cout<<"hey "<<ds.findUPar(2)<<endl;
    map<int, int> freq;
    for (int i = 0; i < n * m; i++) {
      int ref = ds.findUPar(i);
      freq[ref]++;
    }
    int mx = 0;

    for (int i = 0; i < n; i++) {
      set<int> s;
      for (int j = 0; j < m; j++) {
        if (isValid(i - 1, j, n, m) and a[i - 1][j] == '#') {
          int index = findIndex(i - 1, j, n, m);
          int par = ds.findUPar(index);
          s.insert(par);
        }
        if (isValid(i + 1, j, n, m) and a[i + 1][j] == '#') {
          int index = findIndex(i + 1, j, n, m);
          int par = ds.findUPar(index);
          s.insert(par);
        }
        if (a[i][j] == '#') {
          s.insert(findIndex(i, j, n, m));
        }
      }
      int pos = 0;
      for (auto it = s.begin(); it != s.end(); it++) {
        int ele = *it;
        pos = pos + freq[ele];
      }
      pos = pos - row[i] + m;
      mx = max(mx, pos);
    }
    for (int i = 0; i < m; i++) {
      set<int> s;
      for (int j = 0; j < n; j++) { // j is row, i is col
        if (isValid(j, i + 1, n, m) and a[j][i + 1] == '#') {
          // if(i==1){
          //     cout<<"aye "<<j<<" "<<i+1<<endl;
          // }
          int index = findIndex(j, i + 1, n, m);
          int par = ds.findUPar(index);
          s.insert(par);
        }
        if (isValid(j, i - 1, n, m) and a[j][i - 1] == '#') {
          // if(i==1){
          //     cout<<"aye "<<j<<" "<<i-1<<endl;
          // }
          int index = findIndex(j, i - 1, n, m);
          int par = ds.findUPar(index);
          // if(i==1){
          //     cout<<par<<endl;
          // }
          s.insert(par);
        }
        if (a[j][i] == '#') {
          s.insert(findIndex(j, i, n, m));
        }
      }
      int pos = 0;
      for (auto it = s.begin(); it != s.end(); it++) {
        // if(i==1){
        //     cout<<"hi "<<*it<<endl;
        // }
        int ele = *it;
        pos = pos + freq[ele];
        // if(i==1){
        //     cout<<"hi "<<ele<<" "<<freq[ele]<<endl;
        // }
      }
      // if(i==1){
      //     cout<<"hey "<<pos<<endl;
      // }
      pos = pos - col[i] + n;
      // if(i==1){
      //     cout<<pos<<endl;
      // }
      mx = max(mx, pos);
    }

    cout << mx << endl;
  }

  return 0;
}
