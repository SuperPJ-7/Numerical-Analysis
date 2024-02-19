import java.util.*;

class FalsePosition {
   static float f(float x)
{
    //return pow(x, 2) * sin(x) + pow(e, -x) - 3;
    return (float)Math.pow(x,3)-2*x-5;
}
static float func(float x1, float x2)
{
    return x1 - (f(x1) * (x2 - x1) / (f(x2) - f(x1)));
}
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int iteration = 0;
    float product, x=0, x1, x2, error;
    int flag = 0;
    do
    {
        System.out.println("Enter the initial guess x1 and x2:");
        x1 = sc.nextFloat();
        x2 = sc.nextFloat();
        product = f(x1) * f(x2);
        if (product >= 0)
        {
            if (product == 0)
            {
                flag = 1;
                break;
            }
            else
            {
                System.out.println("\nRe enter the initial values:");
            }
        }
    } while (product > 0);
    if (flag == 0)
    {
        float root = (f(x1) == 0) ? x1 : x2;
        System.out.println("The root is "+ root);
    }
    else
    {
        do
        {
            iteration++;
            if(iteration==15){
                break;
            }
            x = func(x1, x2);
            //System.out.println("\n the value is %f",x1);
            System.out.println("\nIteration: "+iteration+"  x1="+x1+" x2 ="+x2+" fx1= "+f(x1)+" fx2= "+f(x2)+"x="+x+"fx="+f(x));
            if (f(x1) * f(x) > 0)
            {
                x1 = x;
            }
            else if (f(x2) * f(x) > 0)
            {
                x2 = x;
            }

            error = (x1>x2)?(x1-x2):(x2-x1);
        } while (error > 0.01);
        System.out.println("the root is "+x+"\nIterations: "+iteration);
    }
    }
}