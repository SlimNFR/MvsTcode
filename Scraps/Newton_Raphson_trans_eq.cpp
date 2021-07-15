#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>

#include"CubicSpline.h"



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

std::vector<double>x_to_interpol,y_to_interpol;

double xcurrent,ycurrent;
xcurrent = 612.0;

double a,b,d,n;
int T = 0;
int Tc=631;
double eps = 1.0;
int size = Tc+1; //including T=0
int T_arr[size];
double me_arr[size];
double TOL = 1e-10;

int N_iter = 200;


std::ofstream f1, f2;
f1.open("output_NR.txt", std::ofstream::out);
f2.open("output_interpol.txt", std::ofstream::out);

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


for(T=0;T<=Tc;T++)
{

    f1<<T_arr[T]<<" "<<me_arr[T]<<"\n";

    if(T<=Tc-100 && T%50 == 0){

        x_to_interpol.push_back(T_arr[T]);
        y_to_interpol.push_back(me_arr[T]);
        std::cout<<"x and y: "<<x_to_interpol.back()<<" "<<y_to_interpol.back()<<"\n";
    }

    else if (T>Tc-50 && T%1 == 0){

        x_to_interpol.push_back(T_arr[T]);
        y_to_interpol.push_back(me_arr[T]);
        std::cout<<"x and y: "<<x_to_interpol.back()<<" "<<y_to_interpol.back()<<"\n";
    }

    
}

int n_pts =x_to_interpol.size();
n_pts--;
std::vector<double>c_coeff(n_pts + 1), b_coeff(n_pts+1), d_coeff(n_pts+1);
CubicSpline::interpolate(n_pts,x_to_interpol,y_to_interpol,b_coeff,c_coeff,d_coeff);


std::cout<<"i, ai, bi, ci, di: \n";
int id;
for (int temp = 0; temp <=631; temp++)
{
    CubicSpline::get_xinterval_id(x_to_interpol, temp, id);
    std::cout<<temp<<" "<<y_to_interpol[id]<<" "<<b_coeff[id]<<" "<<c_coeff[id]<<" "<<d_coeff[id]<<"\n";
    f2<<temp<<" "<<CubicSpline::polynome(y_to_interpol[id],b_coeff[id],c_coeff[id],d_coeff[id],temp,x_to_interpol[id])<<"\n";
}

f1.close();
f2.close();

return 0;
}



