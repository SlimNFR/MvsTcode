#include<iostream>
#include<cmath>
#include<fstream>

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
int T = 0;
int Tc=631;
double eps = 1.0;
int size = Tc+1; //including T=0
int T_arr[size];
double me_arr[size];
double TOL = 1e-10;

int N_iter = 200;


std::ofstream f1;
f1.open("output.txt", std::ofstream::out);


a = 1000; //initial Guess

T_arr[0] = 0; //Deal with the 0K case
me_arr[0] = 1.0;

T_arr[Tc]=Tc; //Deal with the T=Tc case
me_arr[Tc]=0.0;


for(T = 1;T<Tc; T++ )//Loop temperatures between 1K and Tc-1
{
    a = 1000;        
    if(f(a,T,Tc,eps) != 0.0) //If the initial point is not solution, then search
    {
        for(int i=1;i<=N_iter;i++)
        {
            b=a-(f(a,T,Tc,eps)/g(a,T,Tc,eps));
            if(fabs(f(b,T,Tc,eps))<TOL) //If b is solution then stop 
            {
                T_arr[T] = T;
                me_arr[T] = (b*eps*T)/(3*Tc);
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
        me_arr[T] = (b*eps*T)/(3*Tc);

    }
    else{
        T_arr[T] = T;
        me_arr[T] = (a*eps*T)/(3*Tc);
    }
}

for(T=0;T<Tc+1;T++)
{

    f1<<T_arr[T]<<" "<<me_arr[T]<<"\n";

}
f1.close();

return 0;
}



