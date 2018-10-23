//美妙袜子
#include<bits/stdc++.h>
#define per(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,n) for (int i=n-1;i>=a;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long 
using namespace std; const int N = 50003;
struct Mo { int l, r, ID; ll A, B; }q[N]; ll S(ll x) { return x * x; }
ll GCD(ll a, ll b) { while (b ^= a ^= b ^= a %= b); return a; }

int n, m, col[N], unit, Be[N]; ll sum[N], ans;
bool cmp(Mo a, Mo b) { return Be[a.l] == Be[b.l] ? a.r<b.r : a.l<b.l; }
bool CMP(Mo a, Mo b) { return a.ID<b.ID; };
void revise(int x, int add) { ans -= S(sum[col[x]]), sum[col[x]] += add, ans += S(sum[col[x]]); }

int main() {
	scanf("%d%d", &n, &m); unit = sqrt(n);
	per(i, 1, n) { scanf("%d", &col[i]), Be[i] = i / unit + 1; }
	per(i, 1, m) { scanf("%d%d", &q[i].l, &q[i].r), q[i].ID = i; }

	sort(q + 1, q + m + 1, cmp);

	int l = 1, r = 0;
	per(i, 1, m) {
		while (l<q[i].l)revise(l, -1), l++;
		while (l>q[i].l)revise(l - 1, 1), l--;
		while (r<q[i].r)revise(r + 1, 1), r++;
		while (r>q[i].r)revise(r, -1), r--;

		if (q[i].l == q[i].r) { q[i].A = 0; q[i].B = 1; continue; }
		q[i].A = ans - (q[i].r - q[i].l + 1);
		q[i].B = 1LL * (q[i].r - q[i].l + 1)*(q[i].r - q[i].l);
		ll gcd = GCD(q[i].A, q[i].B); q[i].A /= gcd; q[i].B /= gcd;
	}

	sort(q + 1, q + m + 1, CMP);
	per(i, 1, m) { printf("%lld/%lld\n", q[i].A, q[i].B); }
	return 0;
}
