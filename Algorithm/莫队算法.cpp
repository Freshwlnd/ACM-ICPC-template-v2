//美妙袜子
#include <bits/stdc++.h>
#define per(i,a,n) for (int i=a;i<n;i++)
#define rep(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pI;
typedef vector<ll> vI;
const ll mod(1e9 + 7);
const ll INF(0x3f3f3f3f);
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// head

const int N = 50003;
struct Mo {
    int l, r, ID;
    ll A, B;
}q[N];
ll S(ll x) { return x * x; }

int n, m, col[N], unit, Be[N];
ll sum[N], ans;
bool cmp(Mo a, Mo b) { return Be[a.l] == Be[b.l] ? a.r<b.r : a.l<b.l; }
bool CMP(Mo a, Mo b) { return a.ID<b.ID; };
void revise(int x, int add) {
    ans -= S(sum[col[x]]);
    sum[col[x]] += add;
    ans += S(sum[col[x]]); }

int main() {
    scanf("%d%d", &n, &m);
    unit = sqrt(n);
    per(i, 1, n) {
        scanf("%d", &col[i]);
        Be[i] = i / unit + 1;
    }
    per(i, 1, m) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].ID = i;
    }
    
    sort(q + 1, q + m + 1, cmp);
    
    int l = 1, r = 0;
    per(i, 1, m) {
        while (l<q[i].l) {revise(l, -1); l++;}
        while (l>q[i].l) {revise(l - 1, 1); l--;}
        while (r<q[i].r) {revise(r + 1, 1); r++;}
        while (r>q[i].r) {revise(r, -1); r--;}
        
        if (q[i].l == q[i].r) { q[i].A = 0; q[i].B = 1; continue; }
        q[i].A = ans - (q[i].r - q[i].l + 1);
        q[i].B = 1LL * (q[i].r - q[i].l + 1)*(q[i].r - q[i].l);
        ll GCD = gcd(q[i].A, q[i].B);
        q[i].A /= GCD;
        q[i].B /= GCD;
    }
    
    sort(q + 1, q + m + 1, CMP);
    per(i, 1, m) { printf("%lld/%lld\n", q[i].A, q[i].B); }
    return 0;
}
