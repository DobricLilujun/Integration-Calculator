// Firstly I thank Wang Binghui for giving me the class MathFunc which simplifies greatly my program of integrator.

#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <mathfunc.h>
#include <matrix.h>
#include <limits.h>

using namespace std;

void Sort_2SortedArray(double* a, unsigned l, unsigned m, unsigned r);
 //This function can sort two array whose inside are already sorted correctly.
 //This function is not necessary for violent search but it's useful for sorting.
 
void merge (double *a,int left,int right);
 //This function uses merge sort method to sort a array.

double violent_search_Max(MathFunc f, double lowerlimit,double upperlimit,unsigned long section);
 //This function is used for searching the maximum value of a function f between lowerlimit and upperlimit
 //the user can can define the sections which divide the domain of definition.The algorithm of this funct-
 //ion is easy so we call violent search.
 //The number of section we divide is at least 10000.

double violent_search_Min(MathFunc f, double lowerlimit,double upperlimit,unsigned long section);
 //This function is used for searching the minmum value of a function f just like violent_search_Max

Matrix Scatter_function(double x_left,double x_right,double y_lower,double y_upper,unsigned long n);
 //This function is a scatter function which uses the function rand() and the function srand() to uniformly
 //scatter many points in a specified area which is only used for integrator_Monte_Carlo.

double integrator_legend(MathFunc f,double lowerlimit,double upperlimit,unsigned n);
 //This function is a integrator which uses Gauss-Legendre quadrature to make approximation of a integration.
 //This function can only make approximation of integration from a(lowerlimit) to b(upperlimit) which are l-
 //imited numbers.
 //If b-a is very big enough than 1-(-1),the approximation is not very accurate.
 //The method of finding roots is QR algorithm which can find roots of every polynomial including the polyn-
 //omial of Gauss-Legendre.

double integrator_laguerre(MathFunc f,double lowerlimit,double upperlimit,unsigned n);
 //This function is a integrator which uses Gauss-Laguerre quadrature to make approximation of a integration.
 //This function can only make approximation of integration from a to b where there is at least one infinite
 //number.

double integrator_Hermite(MathFunc f,double lowerlimit,double upperlimit,unsigned n);
 //This function is a integrator which can uses Gauss-Hermite quadrature to make approximation of a integrat-
 //ion.
 //The integrator-Hermite can just make approximation of integration from -infty to infty.

double integrator_Chebyshev(MathFunc f,double lowerlimit,double upperlimit,unsigned n);
 //This function can only make approximation of integration from a(lowerlimit) to b(upperlimit) which are l-
 //imited numbers.

double integrator_Monte_Carlo(MathFunc f,double lowerlimit,double upperlimit,unsigned long n);
 //This function uses geometrical significance of integration to make approximation.
 //This function can only make approximation from a to b which are limited numbers.

double integrator_Rimmen(MathFunc f,double lowerlimit,double upperlimit,unsigned n);
 //This function uses simper function :step function to make approximation.
 //This accuracy of this function depends on unsigned the user choosing.

#endif
