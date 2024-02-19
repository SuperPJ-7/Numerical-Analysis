#include <stdio.h>
#include <math.h>
//#define e 2.71828 
#define E 0.0001  //define error tolerance
double func(double x){
    //return log(x) - cos(x);
    //return tan(x) + tanh(x);
    //return sin(x) - 2*x +1;
    //return cos(x) - 1.3*x;
    //return sin(x) - 1/x;
    //return pow(x,2) - 25;
    return pow(x,3) - 2*x -5;
    
}
int main()
{
    double a, b, m;
    double product,error,previous; 
    int iteration = 0;      
    
    do
    {
        
        printf("Enter the initial value of a and b:");
        scanf("%lf%lf",&a,&b);
        product = func(a)*func(b);
        if(product==0){
            printf("the root is %lf",(func(a)==0)?a:b);
            return 0;
            
        }
        else if(product>0){
            printf("Re enter the initial values!!\n");
        }
        // else if(product<0){
        //     break;
        // }
    } while (product>0);
    // printf("Given equation is ...\n");
    // printf("f(%d)=%lf\nf(%d)=%lf\n",(int)a,func(a),(int)b,func(b));
    // printf("Since, f(%d) x f(%d) <0.So, root lies between %d and %d\n\n",(int)a,(int)b,(int)a,(int)b);
    printf("S.N\ta\t\tb\t\tc\t\tf(c)\n");
    
    do{
        iteration++;
        if(iteration>1)
        {
            previous = m;
        }
        m = (a + b) / 2;        
        printf("%d\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",iteration,a,b,m,func(m));
        if(func(m)==0){
            break;
        }
        else if(func(m)*func(a)<0)
        {
            b = m;
        }
        else if(func(m)*func(b)<0){
            a = m;
        }
        
        error = fabs(m - previous)/m;
        if(iteration>1 && error<E){
            break;
        }      

    }
    while(1);
    //printf("Since,aproximate error<error tolerance i.e %lf<%.3lf",error,E);
    printf("The root is %.3lf ",m);
    //printf("\nNo. of iterations: %d",iteration);
}