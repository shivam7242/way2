#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

ll fun(ll ind, ll prev, ll siz, string &s, ll sum, ll x, vector<vector<vector<ll>>> &dp)
{
  // Base case: when the index reaches the size of the string
  if (ind == siz)
  {
    return sum % x == 0 ? 1 : 0;
  }

  // Memoization check
  if (dp[ind][prev][sum % x] != -1)
  {
    return dp[ind][prev][sum % x];
  }

  ll ct = 0;
  if (ind == 0 || prev == s[ind - 1] - '0')
  {
    for (ll i = 0; i <= s[ind] - '0'; i++)
    {
      ct += fun(ind + 1, i, siz, s, sum + i, x, dp);
    }
  }
  else
  {
    for (ll i = 0; i <= 9; i++)
    {
      ct += fun(ind + 1, i, siz, s, sum + i, x, dp);
    }
  }

  // Store result in memoization table
  return dp[ind][prev][sum % x] = ct;
}

void solve()
{
  ll n, x;
  cin >> n >> x;
  string s = to_string(n);

  ll len = s.length();
  ll ans = 0;

  // Initialize memoization table with -1
  vector<vector<vector<ll>>> dp(len, vector<vector<ll>>(10, vector<ll>(x, -1)));

  for (ll i = 0; i <= s[0] - '0'; i++)
  {
    ans += fun(1, i, len, s, i, x, dp);
  }

  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
