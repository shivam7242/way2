#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
#include <queue>
using namespace std;
const unsigned int M = 1000000007;
#define endl "\n"
typedef long long ll;
// /-------------gcc functions--------------------/
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define setbits __builtin_popcount
#define setbitsll __builtin_popcountll
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define des greater<int>()
#define lb lower_bound
#define ub upper_bound

#define all(a) a.begin(), a.end()
#define el cout << "\n"
#define vl vector<ll>
#define vc vector<char>
#define vpr vector<pair<ll, ll>>
#define sl set<ll>
#define sc set<char>
#define mp map<ll, ll>
#define ump unordered_map<ll, ll>
#define pr pair<ll, ll>

ll ghata = 0;
ll rr[4] = {-1, 0, 1, 0};
ll cc[4] = {0, 1, 0, -1};

void dfs(ll row, ll col, vector<vl> &vis, vector<vl> &v) {
  ll n = v.size();
  ll m = v[0].size();
  vis[row][col] = 1;
  ghata++;

  for (ll i = 0; i < 4; i++) {
    ll tempr = rr[i] + row;
    ll tempc = cc[i] + col;

    if (tempr >= 0 && tempc >= 0 && tempr < n && tempc < m &&
        vis[tempr][tempc] == 0) {
      dfs(tempr, tempc, vis, v);
    }
  }
}
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ;
  vector<vector<ll>> v(n, vl(m));
  vector<vector<ll>> vis(n, vl(m, 0));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  vpr store;
  ll val = n * m;
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>,
                 greater<pair<ll, pair<ll, ll>>>>
      pq;

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (v[i][j] <= k) {
        pq.push({v[i][j], {i, j}});
      }
    }
  }

  ll ct = k;
  while (ct > 0) {
    if (!pq.empty()) {
      if (ct >= pq.top().first) {
        ct -= pq.top().first;
        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>,
                       greater<pair<ll, pair<ll, ll>>>>
            pq1;
        ll sub = pq.top().first;
        vpr call1, call2;
        ll add = 0;

          
        while (!pq.empty()) {
          ll value = pq.top().first;
          ll row = pq.top().second.first;
          ll col = pq.top().second.second;
          v[row][col] -= sub;
          pq.pop();

          if (v[row][col] == 0) {
            if (row == 0 && row == n - 1 && col == 0 && col == m) {
              call1.push_back({row, col});
            } else {
              call2.push_back({row, col});
            }
          } else {
            pq1.push({v[row][col], {row, col}});
          }
        }


        for (ll i = 0; i < call1.size(); i++) {
          ghata = 0;
          dfs(call1[i].first, call1[i].second, vis, v);
          add += ghata;
        }

        for (ll i = 0; i < call2.size(); i++) {
          ghata = 0;
          dfs(call2[i].first, call2[i].second, vis, v);
          add += ghata;
        }

        val -= add;
        if (add == 0) {
          store.push_back({sub, val});
        } else {
          store.push_back({sub, val});
        }
        pq = pq1;

      } else {
        store.push_back({ct, val});
        break;
      }
    } else {
      break;
    }
  }
  vl ans;
  for (auto it : store) {
    for (ll i = 0; i < it.first; i++) {
      ans.push_back(it.second);
    }
  }

  for (auto it : ans) {
    cout << it << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

// 3.61e6