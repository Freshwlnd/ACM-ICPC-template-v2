//米勒拉宾算法
//大数素性测试
//原文：https://blog.csdn.net/qq_37957829/article/details/77335072 

typedef long long LL;
 
LL mulmod( LL a, LL b , LL p )
{
    LL  d =1;
    a = a%p;
    while( b>0 )
    {
        if(b&1)
            d = (d*a)%p;
        a = (a*a)%p;
        b>>=1;
    }
    return d;
}
 
bool witness( LL a,LL n)
{
    LL d = n-1 ;
    if( n ==2 ) return true ;
    if( !(n&1) ) return false ;
    while(!(d&1)) d = d/2;
    LL t = mulmod(a,d,n);
    while((d!=n-1) && (t!=1)&&(t!=n-1))
    {
        t = mulmod( t ,2,n);
        d=d<<1;
    }
    return (t==n-1)||(d&1);
}
 
bool isprime( LL n)
{
    int a[3] = {2,7,61};
    for(int i=0;i<3;i++)
        if(!witness(a[i],n))
            return false;
    return true;
}
int main()
{
    LL s;
    cin>>s;
    if(isprime(s))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}