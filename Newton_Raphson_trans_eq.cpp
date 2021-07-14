#include<iostream>
#include<cmath>
using namespace std;
double f(double x, double T, double Tc, double eps)
{
    return ( (eps/3.0)*(T/Tc)*x - 1.0/(tanh(x)) + 1.0/x );
}
double g(double x, double T, double Tc, double eps)
{
    return ( (eps/3.0)*(T/Tc)  + pow( (1.0/sinh(x)),2.0 ) - 1.0/(x*x)  );
}

int main()
{
double a,b,d,n;
int T = 600.0;
int Tc=631.0;
double eps = 1.0;
int size = Tc+1; //including T=0
int T_arr[size];
double me_arr[size];
double TOL = 1e-7;

int N_iter = 50;


a = 5.0; //initial Guess

T_arr[0] = 0; //Deal with the 0K case
me_arr[T] = 1.0;

T_arr[Tc+1]=Tc; //Deal with the T=Tc case
me_arr[Tc+1]=0.0;


for(T = 1;T<Tc; T++ )//Loop temperatures between 1K and Tc-1
{
    if(f(a,T,Tc,eps) != 0.0) //If the initial point is not solution, then search
    {
        for(int i=1;i<=N_iter;i++)
        {
            b=a-(f(a,T,Tc,eps)/g(a,T,Tc,eps));
            if(fabs(f(b,T,Tc,eps))<TOL) //If b is solution then stop 
            {
                T_arr[T] = T;
                me_arr[T] = (b*eps)/(3*Tc);
                break;
            }
            else
            {
                //d=fabs((b-a)/b); Error
                //cout<<" i = "<<n<<" a = "<<a<<" b = "<<b<<" |E| = "<<d*100<<" % "<<endl;
                a=b; //the new initial point is swapped with b
            }
        }
        //if for loop didn't break, consider the solution to be the last point.
        T_arr[T] = T;
        me_arr[T] = (b*eps)/(3*Tc);

    }
    else{
        T_arr[T] = T;
        me_arr[T] = (a*eps)/(3*Tc);
    }
}


return 0;
}


/*Result
 Given Trancedental equation is sin(x)-cos(x)
 Enter the initial guess of the root
1
 Enter the number of Iterations
5
 i = 1 a = 1 b = 0.782042 |E| = 27.8704 %
 i = 2 a = 0.782042 b = 0.785398 |E| = 0.427335 %
 i = 3 a = 0.785398 b = 0.785398 |E| = 0 %
 i = 4 a = 0.785398 b = 0.785398 |E| = 0 %
 i = 5 a = 0.785398 b = 0.785398 |E| = 0 %
 Root of the given equation is 0.785398

*/

