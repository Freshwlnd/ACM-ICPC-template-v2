#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// head

const int maxn(1e3 + 7);
int book[maxn][maxn];
int books[maxn][maxn];
int T, Q;
char type;
int x1, x2, Y1, y2, n1;

inline int lowbit(int x) {
    return x&(-x);
}

void change(int x, int y, int num) {
    for (int tx = x; tx < maxn;tx+=lowbit(tx)) {
        for (int ty = y; ty < maxn; ty += lowbit(ty)) {
            books[tx][ty] += num;
        }
    }
}

int query(int x, int y) {
    int result = 0;
    for (; x > 0; x -= lowbit(x)) {
        for (int i = y; i > 0; i -= lowbit(i)) {
            result += books[x][i];
        }
    }
    return result;
}
//需判断x、y<=0情况

inline int dex(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, Y1 - 1);
}

void build_tree() {
    memset(books, 0, sizeof(books));
    for(int i=1; i < maxn; i++) {
        for(int j=1; j < maxn; j++) {
            book[i][j] = 1;
            change(i, j, 1);
        }
    }
}

void ask() {
    cin >> type;
    switch (type) {
        case 'S': {
            cin >> x1 >> Y1 >> x2 >> y2;
            ++x1;++Y1;++x2;++y2;
            if(x1>x2) { swap(x1, x2); }
            if(Y1>y2) { swap(Y1, y2); }
            cout << dex(x1, Y1, x2, y2) << endl;
        }
            break;
        case 'A': {
            cin >> x1 >> Y1 >> n1;
            ++x1;++Y1;
            book[x1][Y1] += n1;
            change(x1, Y1, n1);
        }
            break;
        case 'D': {
            cin >> x1 >> Y1 >> n1;
            ++x1;++Y1;
            n1 = min(n1, book[x1][Y1]);
            book[x1][Y1] -= n1;
            change(x1, Y1, -n1);
        }
            break;
        case 'M': {
            cin >> x1 >> Y1 >> x2 >> y2 >> n1;
            ++x1;++Y1;++x2;++y2;
            n1 = min(n1, book[x1][Y1]);
            book[x1][Y1] -= n1;
            book[x2][y2] += n1;
            change(x1, Y1, -n1);
            change(x2, y2, n1);
        }
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        build_tree();
        cin >> Q;
        cout << "Case " << _ << ":" << endl;
        while (Q--) {
            ask();
        }
    }
}
