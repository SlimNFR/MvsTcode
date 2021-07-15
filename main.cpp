//---This is the main.cpp file. It calls the main routines of the code.


//---Standard libraries
#include<cmath>
#include<fstream>
#include<iostream>

//---User-defined libraries
#include"CubicSpline.h"
#include"rootfind.h"
//#include"

//---Variables

//---Functions

double f(double x, double T, double Tc, double eps)
{//This is the function I need to find roots for
    return ( (eps/3.0)*(T/Tc)*x - 1.0/(tanh(x)) + 1.0/x );
}
double g(double x, double T, double Tc, double eps)
{//The derivative of my function I need to find roots for
    return ( (eps/3.0)*(T/Tc)  + pow( (1.0/sinh(x)),2.0 ) - 1.0/(x*x)  );
}


int main()
{

std::ofstream f1, f2;
f1.open("output_NR.txt", std::ofstream::out);
f2.open("output_interpol.txt", std::ofstream::out);

int T = 0;
int Tc=631;
int N_iter = 200;
double eps = 1.0;
double TOL = 1e-10;
double m_e=0.0;

rootfind::x0 = 1000.0; //Initial guess for NR algorithm



for(T=0;T<=Tc;T++)
{
	if(T==0 || T==Tc)
	{//The NR algorithm will not work for T=0 or T=Tc.
		
		CubicSpline::x_interpol.push_back(T);
		if(T==0){m_e=1.0; CubicSpline::y_interpol.push_back(m_e);}
		if(T==Tc){m_e=0.0; CubicSpline::y_interpol.push_back(m_e);}

		f1<<T<<" "<<m_e<<"\n";
	}

    else 
    {
	    if(T<=Tc-50 && T%50 == 0){

	    	m_e=rootfind::NewtonRaphson(f,g,rootfind::x0,T,Tc,eps,TOL,N_iter);
	    	std::cout<<m_e<<"  MEEEEE\n";
	        CubicSpline::x_interpol.push_back(T);
	        CubicSpline::y_interpol.push_back(m_e);
	        f1<<T<<" "<<m_e<<"\n";
	        std::cout<<"x and y: "<<CubicSpline::x_interpol.back()<<" "<<CubicSpline::y_interpol.back()<<"\n";

	    }

	    else if (T>Tc-50 && T%1 == 0){
	        m_e=rootfind::NewtonRaphson(f,g,rootfind::x0,T,Tc,eps,TOL,N_iter);
	        CubicSpline::x_interpol.push_back(T);
	        CubicSpline::y_interpol.push_back(m_e);
	        f1<<T<<" "<<m_e<<"\n";
	        std::cout<<"x and y: "<<CubicSpline::x_interpol.back()<<" "<<CubicSpline::y_interpol.back()<<"\n";
	    }
	}	
    
}

//---Cubic interpolation

int n = CubicSpline::x_interpol.size();
n--;

CubicSpline::b.resize(n);
CubicSpline::c.resize(n+1);
CubicSpline::d.resize(n);

CubicSpline::interpolate(n,CubicSpline::x_interpol,CubicSpline::y_interpol,CubicSpline::b,CubicSpline::c,CubicSpline::d);


std::cout<<"i, ai, bi, ci, di: \n";
int id;
for (T = 0; T <=631; T++)
{
    CubicSpline::get_xinterval_id(CubicSpline::x_interpol, T, id);
    std::cout<<T<<" "<<CubicSpline::y_interpol[id]<<" "<<CubicSpline::b[id]<<" "<<CubicSpline::c[id]<<" "<<CubicSpline::d[id]<<"\n";
    f2<<T<<" "<<CubicSpline::polynome(CubicSpline::y_interpol[id],CubicSpline::b[id],CubicSpline::c[id],CubicSpline::d[id],T,CubicSpline::x_interpol[id])<<"\n";
}

f1.close();
f2.close();




}


//---End of main.cpp file
