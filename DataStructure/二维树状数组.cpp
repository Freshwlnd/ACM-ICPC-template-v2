//例题：hdu 1892

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// head

const int maxn(1e3 + 7);
int book[maxn][maxn];
int books[maxn][maxn];
int T, Q;
char type;
int X1, X2, Y1, Y2, n1;

inline int lowbit(int x) { return x&(-x); }

void build_tree();  //建树
void change(int x, int y, int num); //在[x][y]上加num，更新树
inline int dex(int x1, int y1, int x2, int y2); //计算[x1][y1],[x2][y2]矩阵的和
int query(int x, int y);    //计算[0][0],[x][y]矩阵的和
void ask(); //处理题目要求
/*
 * S x1 y1 x2 y2:   sum （[x1][y1],[x2][y2]矩阵和）
 * A x1 y1 n1:      add （[x1][y1]加n1）
 * D x1 y1 n1:      delete （[x1][y1]减n1，减为负数则置为0）
 * M x1 y1 x2 y2 n1:move （从[x1][y1]移动n1到[x2][y2]，减为负数则置为0）
 */


//建树
void build_tree() {
    memset(books, 0, sizeof(books));
    for(int i=1; i < maxn; i++) {
        for(int j=1; j < maxn; j++) {
            book[i][j] = 1;
            change(i, j, 1);
        }
    }
}

//节点[x][y]增加num后，更新树
void change(int x, int y, int num) {
    for (int tx = x; tx < maxn;tx+=lowbit(tx)) {
        for (int ty = y; ty < maxn; ty += lowbit(ty)) {
            books[tx][ty] += num;
        }
    }
}

//处理题目要求
/*
 * S x1 y1 x2 y2:       sum （[x1][y1],[x2][y2]矩阵和）
 * A x1 y1 n1:          add （[x1][y1]加n1）
 * D x1 y1 n1:          delete （[x1][y1]减n1，减为负数则置为0）
 * M x1 y1 x2 y2 n1:    move （从[x1][y1]移动n1到[x2][y2]，减为负数则置为0）
 */
void ask() {
    cin >> type;
    switch (type) {
        case 'S': {
            cin >> X1 >> Y1 >> X2 >> Y2;
            ++X1;++Y1;++X2;++Y2;
            if(X1>X2) { swap(X1, X2); }
            if(Y1>Y2) { swap(Y1, Y2); }
            cout << dex(X1, Y1, X2, Y2) << endl;
        }
            break;
        case 'A': {
            cin >> X1 >> Y1 >> n1;
            ++X1;++Y1;
            book[X1][Y1] += n1;
            change(X1, Y1, n1);
        }
            break;
        case 'D': {
            cin >> X1 >> Y1 >> n1;
            ++X1;++Y1;
            n1 = min(n1, book[X1][Y1]);
            book[X1][Y1] -= n1;
            change(X1, Y1, -n1);
        }
            break;
        case 'M': {
            cin >> X1 >> Y1 >> X2 >> Y2 >> n1;
            ++X1;++Y1;++X2;++Y2;
            n1 = min(n1, book[X1][Y1]);
            book[X1][Y1] -= n1;
            book[X2][Y2] += n1;
            change(X1, Y1, -n1);
            change(X2, Y2, n1);
        }
            break;
    }
}

//计算[0][0],[x][y]矩阵的和
int query(int x, int y) {
    int result = 0;
    for (; x > 0; x -= lowbit(x)) {
        for (int i = y; i > 0; i -= lowbit(i)) {
            result += books[x][i];
        }
    }
    return result;
}

//计算[x1][y1],[x2][y2]矩阵的和
inline int dex(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, Y1 - 1);
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
