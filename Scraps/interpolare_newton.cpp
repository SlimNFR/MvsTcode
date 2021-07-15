#include<iostream>
#include<vector>

#define n 5
double interpolareNewton(std::vector<double> x[],std::vector<double> y[],double xcurent, double &yc);

int main()
{

    double x[n+1],y[n+1],xc=5.0,ycurent;

    x[1]=1; y[1]=2;
    x[2]=2; y[2]=5;
    x[3]=3; y[3]=10;
    x[4]=4; y[4]=17;
    x[5]=5; y[5]=26;


    /*x[1]=0.0;     y[1]=1.0;
    x[2]=50.0;    y[2]=0.97285;
    x[3]=100.0;   y[3]=0.944043;
    x[4]=150.0;   y[4]=0.913232;
    x[5]=200.0;   y[5]=0.879931;
    x[6]=250.0;   y[6]=0.843423;
    x[7]=300.0;   y[7]=0.802631;
    x[8]=350.0;   y[8]=0.755994;
    x[9]=400.0;   y[9]=0.701332;
    x[10]=450.0;  y[10]=0.635519;
    x[11]=500.0;  y[11]=0.55356;
    x[12]=550.0;  y[12]=0.445617;
    x[13]=600.0;  y[13]=0.282133;
    x[14]=620.0;  y[14]=0.169605;
    x[15]=631.0;  y[15]=0.0;
*/
/*
    x[2]=100; y[2]=0.944043;
    x[3]=200; y[3]=0.879931;
    x[4]=400; y[4]=0.701332;
    x[5]=500; y[5]=0.55356;
    x[6]=600; y[6]=0.282133;
    x[7]=631; y[7]=0.0;
  */  
    printf("Valoarea lui x:%lf\n",xc);
    interpolareNewton(x,y,xc,&ycurent);
    //printf("Valoarea functiei in x:%lf",ycurent);

    return 0;
}
void interpolareNewton(double x[],double y[],double xcurent, double *yc)
{
    int j=1,i;
    int n1;
    n1=n;

    double D[n],suma=0.0,p=1.0,a;
    a=y[1];
    do
    {
       for(i=1;i<=n1-1;i++)
       {
           D[i]=((y[i+1]-y[i])/(x[i+j]-x[i]));
           y[i]=D[i];
       }
       for(i=1;i<=j;i++)
       {
           p*=(xcurent-x[i]);
       }
       suma+=(y[j+1]*p);
       n1--;
       j++;
   }
   while(n1!=1);
   *yc=a+suma;

   printf("%e",*yc);

}
