//占坑
//待学习

//莫比乌斯函数定义：
//  d=1时 MU[d] = 1
//  d的素数因子都为1次方时     MU[d] = (-1)^k     （k为素数因子个数）
//  d的素数因子不全为1次方时   MU[d] = 0

//筛莫比乌斯函数：稍微改动素数线性筛
int MU[MAXN];   //得到莫比乌斯函数值
int prime[MAXN];//得到小于等于MAXN的所有素数
void getMU() {
    memset(prime,0,sizeof(prime));
    memset(MU,0,sizeof(MU));
    MU[1] = 1;
    for(int i=2;i<=MAXN;i++) {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]*i<=MAXN;j++) {    //除法改为乘法提速， 改为除法防止爆范围
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
            else MU[i*prime[j]] = -MU[i];
        }
    }
}
