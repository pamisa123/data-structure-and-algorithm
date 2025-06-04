//FACTORIAL
/*
#include<stdio.h>
#include<conio.h>
int fact(int a)
{
    if(a>=1)
    {
        return a*fact(a-1);
    }
    else
    {
        return 1;
    }
}
int main()
{
    int a;
    printf("enter the number whose factorial is wanted:");
    scanf("%d",&a);
    printf("the factorial is:%d",fact(a));
    return 0;
}
*/
//FIND Nth FIBONNACI NUMBER
/*
#include<stdio.h>
#include<conio.h>
int fib(int n,int a,int b)
{
    if(n<3)
    {
        return ;
    }
    int c=a+b;
    printf("%d\t",c);
    return fib(n-1,b,c);
}
int fibo(int n)
{
    if(n<1)
    {
        printf("invalid number of terms");
    }
    else if(n==1)
    {
        printf("%d",0);
    }
    else if(n==2)
    {
        printf("%d\t%d",0,1);
    }
    else
    {
        printf("%d\t%d\t",0,1);
        fib(n,0,1);
    }
    return ;
}
int main()
{
    int n;
    printf("enter how many elements you want to print in series:");
    scanf("%d",&n);
    fibo(n);
    return 0;
}
*/
//HCF
/*
#include<stdio.h>
#include<conio.h>
int hcf(int a,int b)
{
    int result=(a<b)?a:b;
    while(result>0)
    {
        if(a%result==0 && b%result==0)
        {
            break;
        }
        result--;
    }
    return result;
}
int main()
{
    int a,b;
    printf("Enter the two numbers:\n");
    scanf("%d%d",&a,&b);
    printf("the hcf of the numbers is:%d",hcf(a,b));
    return 0;
}
*/
//LCM
/*
#include<stdio.h>
#include<conio.h>
int lcm(int a,int b)
{
    int result=(a>b)?a:b;
    while(result%a!=0 || result%b!=0)
    {
        result++;
    }
    return result;
}
int main()
{
    int a,b;
    printf("enter two numbers:");
    scanf("%d%d",&a,&b);
    printf("the lcm is:%d",lcm(a,b));
    return 0;
}
*/
//TOWER OF HANOI
/*
#include<stdio.h>
#include<conio.h>
int tower(int n,char a,char b,char c)       //a intial,b auxialry,c destination
{
    if(n==0)
    {
        return ;
    }
    tower(n-1,a,c,b);
    printf("move disk %d from rod %c to rod %c\n",n,a,c);
    tower(n-1,c,b,a);

}
int main()
{
    int n;
    printf("enter the number of rod to store:");
    scanf("%d",&n);
    tower(n,'a','c','b');
    return 0;
}
*/
#include<stdio.h>
int gcd(int a,int b)
{
    int g;
    if(b==0)
    {
        return a;
    }
    else
    {
        g=gcd(b,a%b);
        return g;
    }
}
int main()
{
    int a,b,g;
    printf("emter two numbers:");
    scanf("%d%d",&a,&b);
    g=gcd(a,b);
    printf("gcd=%d",g);
    return 0;
}


















