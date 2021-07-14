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
double T = 600.0;
double Tc=631.0;
double eps = 1.0;
int i;
cout<<" Given Trancedental equation: eps*T/Tc)*x - 1.0/(tanh(x)) + 1.0/x "<<endl;
cout<<" Enter the initial guess of the root "<<endl;
cin>>a;
cout<<" Enter the number of Iterations "<<endl;
cin>>i;
if(f(a,T,Tc,eps) != 0.0)
{
 for(n=1;n<=i;n++)
 {
  b=a-(f(a,T,Tc,eps)/g(a,T,Tc,eps));
  if(f(b,T,Tc,eps)==0)
  {
   cout<<" i = "<<n<<" Root of the given equation is "<<b<<endl;
  }
  else
  {
   d=fabs((b-a)/b);
   cout<<" i = "<<n<<" a = "<<a<<" b = "<<b<<" |E| = "<<d*100<<" % "<<endl;
   a=b;
  }
 }
 cout<<" Root of the given equation is "<<b<<endl;
}
else
{
 cout<<" Root of the given equation is "<<a<<endl;
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

