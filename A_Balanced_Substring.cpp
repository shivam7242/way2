#include <bits/stdc++.h>
using namespace std;  
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 2, vector<int>(m + 2, -1e9));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      v[i][j] = x;
    }
  }
  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, 1, 0, -1};
  int indx = -1, indy = -1;
  for (int i = 1; i <= n; i++) {

    int lo = 1, hi = m;
    int mid;
    int f = 0;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;

      if (v[i][mid] > v[i][mid - 1] && v[i][mid] > v[i][mid + 1] &&
          v[i][mid] > v[i - 1][mid] && v[i][mid] > v[i + 1][mid]) {
        indx = i;
        indy = mid;
        f = 1;
        break;
      } else if (v[i][mid] < v[i][mid - 1] && v[i][mid] > v[i][mid + 1]) {
        hi = mid - 1;
      } else if (v[i][mid] > v[i][mid - 1] && v[i][mid] < v[i][mid + 1]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if (f == 1) {
      break;
    }
  }
  cout << indx << " " << indy << endl;
  return 0;
}
