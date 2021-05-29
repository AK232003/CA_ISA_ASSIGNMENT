#include<stdio.h>
typedef long long ll;
int main()
{
    ll a,b,c;
    scanf("%lld%lld",&a,&b);
    if(a>=b) c=a+b;
    else c=a-b;
    printf("%lld",c);
}
