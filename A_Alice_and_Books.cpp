#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class BT {
public:
  int val;
  class BT *left;
  class BT *right;
  BT(int val) {

    this->val = val;
    left = NULL;
    right = NULL;
  }
};

void inorder(BT *root, vector<int> &v) {
  if (root == NULL)
    return;

  if (root->left != NULL) {
    inorder(root->left, v);
  }

  v.push_back(root->val);

  if (root->right != NULL) {
    inorder(root->right, v);
  }
}
int main() {
  int n, x;
  cin >> n >> x;

  class BT *root = new BT(5);
  root->left = new BT(3);
  root->right = new BT(6);
  root->left->left = new BT(2);
  root->left->right = new BT(4);
  vector<int> v;

  inorder(root, v);

  sort(v.begin(), v.end());

  if (upper_bound(v.begin(), v.end(), x) == v.end()) {
    cout << "NO" << endl;
  } else {
    int ind = upper_bound(v.begin(), v.end(), x) - v.begin();
    if (ind == 0) {
      if (v[ind] == x) {
        cout << v[ind] << endl;
      } else {
        cout << "NO" << endl;
      }
    } else
      cout << v[ind - 1] << endl;
  }

  return 0;
}
