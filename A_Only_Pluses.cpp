#include <bits/stdc++.h>
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
#define intmax 1e18
#define intmin -1e18
#define input(v, n)                                                            \
  vector<ll> v(n);                                                             \
  for (auto i = 0; i < v.size(); i++) {                                        \
    cin >> v[i];                                                               \
  }
#define output(v)                                                              \
  for (auto k : v) {                                                           \
    cout << k << " ";                                                          \
  }                                                                            \
  cout << "\n";

#define MAXN 100001
int spf[MAXN];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++)
    spf[i] = i;
  for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2;

  for (int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i)
        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

vector<ll> primes;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p])
      primes.push_back(p);
}

unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % p;

    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r)
    return 0;
  if (r == 0)
    return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = (fac[i - 1] * i) % p;

  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
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
long long binpowm(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void make_set(ll v, vl &parent, vl &size) {
  parent[v] = v;
  size[v] = 1;
}
ll find_set(ll v, vl &parent) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v], parent);
}
void union_sets(ll a, ll b, vl &parent, vl &size) {
  a = find_set(a, parent);
  b = find_set(b, parent);
  if (a != b) {
    if (size[a] < size[b])
      swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll v, ll b) { return (v * b) / gcd(v, b); }

template <typename L, typename R>
ostream &operator<<(ostream &out, const pair<L, R> &p) {
  out << '(' << p.first << ',' << p.second << ')';
  return out;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &i : v)
    out << i << ' ';
  el;
  return out;
}

template <typename T> ostream &operator<<(ostream &out, const set<T> &v) {
  for (auto &i : v)
    out << i << ' ';
  el;
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_set<T> &v) {
  for (auto &i : v)
    out << i << ' ';
  el;
  return out;
}

template <typename K, typename V>
ostream &operator<<(ostream &out, const map<K, V> &m) {
  out << '[';
  for (auto &[k, v] : m) {
    out << k << ':' << v << " ";
  }
  out << "]\n";
  return out;
}

template <typename K, typename V>
ostream &operator<<(ostream &out, const unordered_map<K, V> &m) {
  out << '[';
  for (auto &[k, v] : m) {
    out << k << ':' << v << " ";
  }
  out << "]\n";
  return out;
}

void solve() {

  ll a, b, c;
  cin >> a >> b >> c;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  pq.push(a);
  pq.push(b);
  pq.push(c);
  for (ll i = 0; i < 5; i++) {
    ll val = pq.top();
    pq.pop();
    pq.push(val + 1);
  }

  ll ans = 1;
  

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
