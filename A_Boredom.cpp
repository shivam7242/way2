#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> arr(n + 2);
  arr[0] = -1e9;
  arr[n + 1] = -1e9;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int lo = 1, hi = n;
  int mid;
  int flag = 0;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      flag = 1;
      cout << "peak ->" << mid << endl;
      return 0;
    } else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  if (flag == 0) {
    cout << "no answer" << endl;
  }

  return 0;
}
