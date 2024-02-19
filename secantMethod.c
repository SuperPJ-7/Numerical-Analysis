#include <stdio.h>
#include <math.h>
#define errorTolerance 0.001
#define e 2.71828

double f(double x)
{
    //return tan(x) + tanh(x);
    //return pow(x,3) - 2*x -5;
    //return pow(x,6) - pow(x,4) - pow(x,3) - 1;
    //return pow(x,3)+pow(x,2) - 3*x -3;
    //return 3*x + sin(x) - pow(e,x);
    //return pow(x,3) + pow(x,2) - x - 1;
    //return pow(x,3) - 2*x - 5;
    return x*pow(e,x) - cos(x);
}
double func(double a, double b)
{
    return a - (f(a) * (b - a) / (f(b) - f(a)));
}
int main()
{
    int iteration = 0;
    double product, x, a, b, error, prev;
    // do
    // {
    //     printf("Enter the initial guess a and b:");
    //     scanf("%f%f", &a, &b);
    //     product = f(a) * f(b);
    //     if(product<0)
    //     {
    //         break;
    //     }
    //     else if (product > 0)
    //     {
    //         printf("\nRe enter the initial values:");
    //     }
    //     else if (product == 0)
    //     {
    //         printf("the root is %lf", (f(a) == 0) ? a : b);
    //         return 0;
    //     }
    // } while (1);
    printf("Enter the initial guess x1 and x2:");
    scanf("%lf%lf",&a,&b);

    printf("Given equation is ...\n");
    printf("f(%d)=%lf\nf(%d)=%lf\n",(int)a,f(a),(int)b,f(b));
    // printf("Since, f(%d) x f(%d) <0.So, root lies between %d and %d\n\n",(int)a,(int)b,(int)a,(int)b);
    printf("S.N\tx1\t\tx2\t\tf(x1)\t\tf(x2)\t\tx_n\t\tf(x_n)\n");
    
    do
    {
        iteration++;
        // if (iteration > 1)
        // {
        //     prev = x;
        // }
        x = func(a, b);
        printf("%d\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",iteration,a,b,f(a),f(b),x,f(x));
        a = b;
        b = x;

        
        
        
    } while (fabs(f(x))>=errorTolerance);
    printf("Since,aproximate error<error tolerance i.e %.4lf<%.3lf, the root is %.3lf",error,errorTolerance,x);
   
}
