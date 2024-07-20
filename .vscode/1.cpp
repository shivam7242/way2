#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n), pref(n), suff(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (i == 0)
    {
      pref[i] = arr[i];
    }
    else
    {
      pref[i] = __gcd(arr[i], pref[i - 1]);
    }
  }
  for (int i = 0; i < n; i++)
  {

    if (i == n - 1)
    {
      suff[i] = arr[i];
    }
    else
    {
      suff[i] = __gcd(arr[i], suff[i + 1]);
    }
  }
  int ans = pref[n - 1];

  for (int i = 1; i < n - 1; i++)
  {

    ans = max(ans, __gcd(pref[i - 1], suff[i + 1]));
  }
  if (n > 0)
  {
    ans = max(ans, suff[1]);
    ans = max(ans, pref[n - 2]);
  }

  cout << ans << endl;
  return 0;
}
