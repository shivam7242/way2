#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int f(int ind, vector<int> &v, int sum, vector<vector<int>> &dp) {

  if (ind < 0) {

    if (sum == 0) {

      return 1;
    }
    return 0;
  }

  if (dp[ind][sum] != -1) {
    return dp[ind][sum];
  }
  int skip = f(ind - 1, v, sum, dp);
  int take = 0;
  if (sum >= v[ind]) {

    take = f(ind - 2, v, sum - v[ind], dp);
  }
  return dp[ind][sum] = ((take) % mod + (skip) % mod) % mod;
}
class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {

    int ans = INT_MAX;
    vector<vector<char>> v(n, vector<char>(n, 1));
    for (auto it : mines) {
      v[it[0]][it[1]] = 0;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int left = i, right = i, top = j, bottom = j;
        int left_ct = 0, right_ct = 0, top_ct = 0, bottom_ct = 0;

        while (left - 1 >= 0 && v[i][left - 1] == '1') {
          left_ct++;
        }

        while (right + 1 < n && v[i][right + 1] == '1') {
          right_ct++;
        }

        while (top - 1 >= 0 && v[i][top - 1] == '1') {
          top_ct++;
        }

        while (bottom + 1 < n && v[i][bottom + 1] == '1') {
          bottom_ct++;
        }

        ans = min(min({left_ct, right_ct, top_ct, bottom_ct}) + 1, ans);
      }
    }
    return ans;
  }
};


int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 1; i < n; i += 1) {
    v.push_back(i);
  }
  int sum = 0;
  sum += (n * (n + 1) / 2);
  if (sum & 1) {
    cout << 0 << endl;
  } else {

    sum /= 2;
    sum -= n;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    int ans = f(v.size() - 1, v, sum, dp) % mod;
    cout << ans % mod << endl;
  }
}
