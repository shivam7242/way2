#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    n1--;
    n2--;
    while (n1 >= 0 && n2 >= 0) {
      while (n1 >= 0) {
        if (s1[n1] != '#') {
          break;
        }
        int c1 = 0;
        while (s1[n1] == '#') {
          c1++;
          n1--;
        }
        n1 -= c1;
      }
      while (n2 >= 0) {
        if (s2[n2] != '#') {
          break;
        }
        int c2 = 0;
        while (s2[n2] == '#') {
          c2++;
          n2--;
        }
        n2 -= c2;
      }
      if (n1 >= 0 && n2 >= 0) {
        if (s1[n1] == s2[n2]) {
          n1--;
          n2--;
        }
      }
    }

    if (n1 == n2)
      return true;
    return false;
  }
};

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.length();
  map<char, int> store;
  int i = 0, j = 0;
  int ans = 0;
  while (j < n) {
    store[s[j]]++;
    if (store.size() >= k) {
      ans++;
      while (i < j) {
        store[s[i]]--;
        if (store[s[i]] == 0) {
          store.erase(s[i]);
        }
        i++;
        if (store.size() < k) {
          break;
        }
        ans++;
      }
    }
    j++;
  }

  while (i < j) {
    store[s[i]]--;
    if (store[s[i]] == 0) {
      store.erase(s[i]);
    }
    i++;
    if (store.size() < k) {
      break;
    }
    ans++;
  }

  cout << ans << endl;
  return 0;
}
