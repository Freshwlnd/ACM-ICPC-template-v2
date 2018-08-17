#include<bits/stdc++.h>
#define per(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,n) for (int i=n-1;i>=a;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long 
using namespace std; 

const int maxn = 1e5 + 7;

int sett[maxn];//集合index的类别，或者用parent表示
int rankk[maxn];//集合index的层次，通常初始化为0
int data[maxn];//集合index的数据类型

//初始化集合
void Make_Set(int i) {
	sett[i] = i;//初始化的时候，一个集合的parent都是这个集合自己的标号。没有跟它同类的集合，那么这个集合的源头只能是自己了。
	rankk[i] = 0;
}

//查找集合i（一个元素是一个集合）的源头（递归实现）
int Find_Set(int i) {
	//如果集合i的父亲是自己，说明自己就是源头，返回自己的标号
	if (sett[i] == i)
		return sett[i];
	//否则查找集合i的父亲的源头
	return  Find_Set(sett[i]);
}

//合并
void Union(int i, int j) {
	i = Find_Set(i);
	j = Find_Set(j);
	if (i == j) { return; }
	if (rankk[i] > rankk[j]) {
		sett[j] = i;
	} 
	else {
		if (rankk[i] == rankk[j]) rankk[j]++;
		sett[i] = j;
	}
}

int main() {
	return 0;
}
