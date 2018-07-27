#include<stdio.h>
#include<math.h>
double func(double x)
{
    double y;
    y=x*x*x*x*x-x-1;
    return y;
}
int main(void)
{
    double y,xl,xg,a,b,c,d,e,f_a,f_b,f_a_f_b;
    int ittr=1,ittrn;
    printf("You are getting the root of the equation y=x*x*x*x*x-x-1\n\n");
    printf("Enter the bisection interval points: ");
    scanf("%lf%lf",&a,&c);
    printf("Enter error tolerance and number of iterations: ");
    scanf("%lf %d",&e,&ittrn);

    do
    {
        b=(a+c)/2;
        printf("Iteration no: %d; x = %lf\n",ittr,b);
        f_a=func(a);
        f_b=func(b);
        f_a_f_b=f_a*f_b;
        if(f_a_f_b<0)
        {
            c=b;
        }
        else
        {
            a=b;
        }
        d=a-c;
        if(d>0)//"fabs" function call korleo hoito
        {
            d=d;
        }
        else
        {
            d=-d;
        }
        ittr++;
    }
    while(d>e||ittr<ittrn);
    printf("\nRoot: %lf\n",b);
    return 0;
}
