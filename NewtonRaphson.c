/*
    Code: Newton-Raphson method 
    Date: December 10th,2023
*/
#include<stdio.h>
#include<math.h>
#define errorTol 0.001 //must be accurate up to 3 decimal places
#define e 2.71828
double f(double x){
    //return x - pow(e,-x);
    //return pow(e,(x-1)) - 5*pow(x,2);
    //return pow(x,3) - 4*x + 1;
    //return pow(x,3) - 2*x - 5;
    //return x*log10(x) - 1.2;
    //return pow(x,3) - 3*x + 2;
    return 3*x - cos(x) - 1;
    
}
double df(double x){
    //return 1 + pow(e,-x);
    //return -10*x + pow(e,(x-1));
    //return 3*x*x -4;
    //return 3*pow(x,2) -2 ;
    //return 1/log(10)+log10(x);
    //return 3*x*x - 3;
    return 3 + sin(x);
}
int main()
{
    double x,xn,error;
    int iteration = 0;    
    printf("Enter the initial value(x0):");
    scanf("%lf",&x);
    if(f(x)==0){
        printf("The root is %.3lf",x);
        return 0;
    }
    printf("n\tx_n\t\tf(x)\t\tf'(x)\t\tx_(n+1)\t\tf(x_(n+1))\n");
    do
    {
        
        if(iteration>0)
        {
            x = xn;
        }
        xn = x - f(x)/df(x);
        printf("%d\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",iteration,x,f(x),df(x),xn,(f(xn)));
        iteration++;
        
    }while(fabs(f(xn))>=errorTol);
    printf("Since |f(x_n+1)|<0.001, ");
    printf("The desired root is %.3lf",xn);
}
