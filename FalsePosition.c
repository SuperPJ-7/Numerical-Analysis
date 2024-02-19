#include <stdio.h>
#include <math.h>
#define errorTolerance 0.001

float f(float x)
{
    //return log(x) - cos(x);
    //return sin(x) - x + 2;
    //return pow(x,3)-4*pow(x,2)+x+6;
    //return x*sin(x) + cos(x);
    // return pow(x,3) + 4*x - 1;
    return pow(x,6) - pow(x,4) - pow(x,3) - 1;
}
float func(float a, float b)
{
    return a - (f(a) * (b - a) / (f(b) - f(a)));
}
int main()
{
    int iteration = 0;
    float product, x, a, b, error, prev;
    do
    {
        printf("Enter the initial guess a and b:");
        scanf("%f%f", &a, &b);
        product = f(a) * f(b);
        if(product<0)
        {
            break;
        }
        else if (product > 0)
        {
            printf("\nRe enter the initial values:");
        }
        else if (product == 0)
        {
            printf("the root is %lf", (f(a) == 0) ? a : b);
            return 0;
        }
    } while (1);

    printf("Given equation is ...\n");
    printf("f(%d)=%lf\nf(%d)=%lf\n",(int)a,f(a),(int)b,f(b));
    printf("Since, f(%d) x f(%d) <0.So, root lies between %d and %d\n\n",(int)a,(int)b,(int)a,(int)b);
    printf("S.N\ta\t\tb\t\tf(a)\t\tf(b)\t\tx\t\tf(x)\n");
    
    do
    {
        iteration++;
        if (iteration > 1)
        {
            prev = x;
        }
        x = func(a, b);
        printf("%d\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",iteration,a,b,f(a),f(b),x,f(x));
        if ((f(a) * f(x)) > 0)
        {
            a = x;
        }
        else if (f(b) * f(x) > 0)
        {
            b = x;
        }

        
        error = fabs(x - prev);
        if(iteration>1 && error<errorTolerance)
        {
            break;
        }
        
    } while (1);
    printf("Since,aproximate error<error tolerance i.e %.4lf<%.3lf, the root is %.3lf",error,errorTolerance,x);
   
}
