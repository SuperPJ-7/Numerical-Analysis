#include<stdio.h>
#include<math.h>
double f(double x){
    //return pow(x,2) - x - 1;
    //return x*x - 2*x -3;
    return pow(x,2) - 3;
}
double g(double x){
    
    //return 1/(x-1);
    //return 3/(x-2);
    return sqrt(3);
}
int main(){
    double error,x;
    printf("Enter the initial guess:");
    scanf("%lf",&x);
    printf("x\t\tg(x)\n");
    do{
        printf("%.4lf\t\t%.4lf\n",x,g(x));
        error = fabs(x-g(x));
        x = g(x);
    }while(error>=0.001);
    printf("The root is %.3lf",x);
}