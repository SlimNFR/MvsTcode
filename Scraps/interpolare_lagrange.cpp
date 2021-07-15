#include <stdio.h>
#include <stdlib.h>
#define n 15
void interpolareLagrange(double x[],double y[],double xcurent,double *yc);
int main()
{
    double x[n+1],y[n+1],ycurent,xcurent;
    xcurent=510.0;
    x[1]=1.0;     y[1]=0.99;
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

    interpolareLagrange(x,y,xcurent,&ycurent);
    printf("Valoarea lui x:%lf",xcurent);
    printf("\nValoarea functiei in x este:%lf",ycurent);
    return 0;
}
void interpolareLagrange(double x[],double y[],double xcurent,double *yc)
{
    double p,suma;
    int i,k;

    suma=0;
    for(k=0;k<=n;k++)
    {

    p=1;
        for(i=0;i<=n;i++)
        {

            if(i!=k)p*=(xcurent-x[i])/(x[k]-x[i]);

        }

        suma+=y[k]*p;
    }
    *yc=suma;
}