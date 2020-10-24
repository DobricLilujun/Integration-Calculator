#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

double function (double x,double t)
{
	if(x < t)
	{
		return x;
	}
	else
	{
		return t;
	}
	// return (2*x)*(t-1);
	// return exp(-2*fabs(x-t));
	// return sin(x)*cos(t);
}