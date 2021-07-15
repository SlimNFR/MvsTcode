//---This is the CubicSpline.h file.
#pragma once

#ifndef CUBICSPLINE_H
#define CUBICSPLINE_H

//---Standard libraries
#include<vector>

//---User-defined libraries


//---Namespace CubicSpline

namespace CubicSpline{
	
//---Variables


//---Functions
double polynome(double a, double b, double c,double d, double x, double xj);
double get_xinterval_id(std::vector<double>x_arr, double x, int &id);
double interpolate(int n, std::vector<double> x,std::vector<double> a,
                   std::vector<double> &b, std::vector<double> &c, std::vector<double> &d);
}

#endif
//---End of CubicSpline.h file.