//bisection method
/*#include<stdio.h>
#include<conio.h>
#define e 0.0001
float f(float x)
{
    return (sin(x)-1/x);
}
int main()
{
    int i=0;
    float a,b,c,s;
    do
    {
         printf("enter two initial guesses:");
        scanf("%f%f",&a,&b);
    }while(f(a)*f(b)>0);
    printf("\t ITERATION \t a \t b\t c\t f(c)\n");
    do
    {
        s=(a+b);
        c=s/2;
        printf("\t %d \t %f \t %f\t %f\t %f\n",i,a,b,c,f(c));
        if((f(a)*f(c))>0)
        {
            a=c;
        }
        else
        {
            b=c;
        }
    }while((fabs(b-a)/b)>e);
    printf("the value is:%f",c);
    return 0;
}
*/
//secant method
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.00001
float f(float x)
{
    return (x * exp(x) -cos(x));
}
int main()
{
    int i;
    float a,b,s,c;
    printf("enter the two initial guesses:");
    scanf("%f%f",&a,&b);
    printf("\t Iteration \t a \t b \t f(a) \t f(b) \t c\n");
    do
    {
        s=((a*f(b))-(b*f(a)));;
        c=s/(f(b)-f(a));
        printf("\t %d \t %f \t %f \t %f \t %f \t %f \n",i++,a,b,f(a),f(b),c);
        a=b;
        b=c;
    }while(fabs((c-a)/c)>e);
    printf("the value is:%f",c);
    return 0;
}
*/
//newton raphson
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.0001
float f(float x)
{
    return (sin(x)+cos(x)+exp(x)-8);
}
float fd(float x)
{
    return (cos(x)-sin(x)+exp(x));
}
int main()
{
    int i;
    float a,b,c;
    printf("enter the initial value:");
    scanf("%f",&a);
    printf("\t Iteration \t a \t f(a) \t fd(a) \t b \n");
    do
    {
        b=a-(f(a)/fd(a));
        printf("\t %d \t %f \t %f \t %f \t %f \n",i++,a,f(a),fd(a),b);
        c=a;
        a=b;
    }while(fabs((c-a)/c)>e);
    printf("the value is:%f",b);
    return 0;
}
*/
//fixed point method
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.00001
float g(float x)
{
    return ((2-sin(x))/3);
}
int main()
{
    int i;
    float a,b,err;
    printf("enter the initial guess:");
    scanf("%d",&a);
    printf("\t Iteration \t a \t b \n");
    do
    {
        b=g(a);
        err=(b-a)/b;
        printf("\n %d \t %f \t %f \n",i++,a,b);
        a=b;
    }while(fabs(err)>e);
    printf("the value is:%f",b);
    return 0;
}
*/
//gauss seidal
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f1(x,y,z) (17-y+(2*z))/20
#define f2(x,y,z) (-18-(3*x)+z)/20
#define f3(x,y,z) (25-(2*x)+(3*y))/20

int main()
{
    float x0=0,y0=0,z0=0,x1,y1,z1,e1,e2,e3,e;
    int i=1;
    printf("enter the allowed error:");
    scanf("%f",&e);
    printf("\t Iteration \t x1 \t y1 \t z1 \n");
    do
    {
        x1=f1(x0,y0,z0);
        y1=f2(x1,y0,z0);
        z1=f3(x1,y1,z0);
        printf("\t %d \t %f \t %f \t %f \n",i,x1,y1,z1);
        i++;
        e1=fabs(x0-x1);
        e2=fabs(y0-y1);
        e3=fabs(z0-z1);
        x0=x1;
        y0=y1;
        z0=z1;
    }while(e1>e && e2>e && e3>e);
    printf("the value of x,y,z are:%f,%f,%f",x1,y1,z1);
    return 0;
}
*/
//gauss jacobi
/*
#include<stdio.h>
#include<conio.h>
#define f1(x,y,z) (17-y+(2*z))/20
#define f2(x,y,z) (-18-(3*x)+z)/20
#define f3(x,y,z) (25-(2*x)+(3*y))/20
int main()
{
    int i=1;
    float x0=0,y0=0,z0=0,x1,y1,z1,e1,e2,e3,e;
    printf("enter the allowed error:");
    scanf("%f",&e);
    do
    {
        x1=f1(x0,y0,z0);
        y1=f2(x0,y0,z0);
        z1=f3(x0,y0,z0);
        printf("\t %d \t %f \t %f \t %f \n",i,x1,y1,z1);
        i++;
        e1=fabs(x0-x1);
        e2=fabs(y0-y1);
        e3=fabs(z0-z1);
        x0=x1;
        y0=y1;
        z0=z1;
    }while(e1>e && e2>e && e3>e);
    printf("the value of x,y,z are:%f,%f,%f",x1,y1,z1);
    return 0;
}
*/
//power method
/*
#include<stdio.h>
#include<conio.h>
#define e 0.0001
int main()
{
    int i,j,n;
    float x[10],a[10][10],z[10],oldvalue,zmax=1,error;
    printf("enter the order of matrix:");
    scanf("%d",&n);
    printf("enter the elements of matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("a(%d,%d):",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    printf("enter the eigen vector:");
    for(i=1;i<=n;i++)
    {
        scanf("%f",&x[i]);
    }
    do{
        for(j=1;j<=n;j++)
    {
        z[i]=0;
        for(i=1;i<=n;i++)
        {
            z[i]=z[i]+a[i][j]*x[j];
        }
    }
    oldvalue=zmax;
    zmax=fabs(z[i]);
    for(i=2;i<=n;i++)
    {
        if(fabs(z[i])>zmax)
        {
            zmax=z[i];
        }
    }
    error=fabs(zmax-oldvalue);
    for(i=1;i<=n;i++)
    {
        z[i]=z[i]/zmax;
    }
    for(i=1;i<=n;i++)
    {
        x[i]=z[i];
    }
    }while(error>e);
    printf("the value is:%f\n",zmax);
    for(i=1;i<=n;i++)
    {
        printf("%f\t",z[i]);
    }
    return 0;
}
*/
//lagranges interpolation
/*
#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j;
    float x[10],y[10],xvalue,yvalue=0,z[10];
    printf("enter the number of data points:");
    scanf("%d",&n);
        printf("enter the xvalue:");
    scanf("%f",&xvalue);
    printf("enter the data points:");

    for(i=0;i<=n-1;i++)
    {
        {

            scanf("%f",&x[i]);

            scanf("%f",&y[i]);
        }
    }
for(i=0;i<=n-1;i++)
    {
        z[i]=1;
        for(j=0;j<=n-1;j++)
        {
            if(j!=i)
            {
                z[i]=z[i]*(xvalue-x[j])/(x[i]-x[j]);
            }
        }
    }
    for(i=0;i<=n-1;i++)
    {
        yvalue=yvalue +(z[i]*y[i]);
    }
    printf("the value of %f :",xvalue);
    printf("%f",yvalue);
    return 0;
}
*/
//least square method
/*
#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,n;
    float sumx,sumy,sumxy,sumxx,a,b,x[10],y[10];
    printf("enter the number of data points:");
    scanf("%d",&n);

    printf("enter the data points:");
    for(i=1;i<=n;i++)
    {
        scanf("%f",&x[i]);
        scanf("%f",&y[i]);
    }
    for(i=1;i<=n;i++)
    {
            sumx=sumx+x[i];
    sumy=sumy+y[i];
    sumxy=sumxy+x[i]*y[i];
    sumxx=sumxx+x[i]*x[i];
    }
    a=((sumxy*sumx)-(sumxx*sumy))/((sumx*sumx)-n*sumxx);
    b=(sumy-n*a)/sumx;
    printf("the value is given by:\n ");
    printf("y= %f x+ %f ",a,b);
    return 0;
}*/
//trapezoidal rule
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (cos(x)/(1+pow(x,2)))
int main()
{
    int i;
    float a,b,n,h,xn,sum=0,I;
    printf("enter the first ,last and no of strips:");
    scanf("%f%f%f",&a,&b,&n);
    h=(b-a)/n;
        for(i=1;i<=n-1;i++)
        {
            sum=sum+2*f(a+i*h);
        }
        I=(h/2)*(f(a)+f(b)+sum);

    printf("the value is:%f",I);
    return 0;
}
*/
//simpson's 1/3 rule
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (cos(x)/(1+pow(x,2)))
int main()
{
    int i;
    float a,b,n,sum=0,I,h;
    printf("enter the lower,upper limit and the no of strips:");
    scanf("%f%f%f",&a,&b,&n);
    h=(b-a)/n;
    for(i=1;i<=n-1;i++)
    {
        if(i%2==0)
        {
            sum=sum+2*f(a+i*h);
        }
        else
        {
            sum=sum+4*f(a+i*h);
        }
    }
    I=(h/3)*(sum+f(a)+f(b));
    printf("the value is:%f",I);
    return 0;
}
*/
//simpson's 3/8
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (cos(x)/(1+pow(x,2)))
int main()
{
    int i;
    float a,b,n,sum=0,I,h;
    printf("enter the lower,upper limit and the no of strips:");
    scanf("%f%f%f",&a,&b,&n);
    h=(b-a)/n;
    for(i=1;i<=n-1;i++)
    {
        if(i%3==0)
        {
            sum=sum+2*f(a+i*h);
        }
        else
        {
            sum=sum+3*f(a+i*h);
        }
    }
    I=(3*h/8)*(sum+f(a)+f(b));
    printf("the value is:%f",I);
    return 0;
}
*/
//rk-2 method
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x,y) ((y-x)/(y+x))
int main()
{
    float a,b,m,m1,m2,x1,h,y1,xn;
    printf("enter the initial and final values:");
    scanf("%f%f",&a,&b);
    printf("enter the value of x:");
    scanf("%f",&xn);
    printf("enter the value of h:");
    scanf("%f",&h);
    while(a<xn)
    {
        m1=h*f(a,b);
        m2=h*f(a+h,b+m1*h);
        m=(m1+m2)/2;
        y1=b+m;
        x1=a+h;
        printf("\nthe value at %f is:%f\n",x1,y1);
        a=x1;
        b=y1;
    }

    return 0;
}
*/
//rk-4
#include<stdio.h>

#include<math.h>
#define f(x,y) ((y-x)/(y+x))
int main()
{
    float x0,y0,h,m1,m2,m3,m4,xn,m,x1,y1;
    printf("enter the initial value:");
    scanf("%f%f",&x0,&y0);
    printf("enter the step size:");
    scanf("%f",&h);
    printf("enter the value of x for which y is needed:");
    scanf("%f",&xn);
    while(x0<xn)
    {
        m1=f(x0,y0);
        m2=f(x0+h/2,y0+h/2*m1);
        m3=f(x0+h/2,y0+h/2*m2);
        m4=f(x0+h,y0+h*m3);
        m=(m1+(2*m2)+(2*m3)+m4)/6;
        x1=x0+h;
        y1=y0+m*h;
        printf("%f:\t%f\n",x1,y1);
        x0=x1;
        y0=y1;
    }
    return 0;
}
