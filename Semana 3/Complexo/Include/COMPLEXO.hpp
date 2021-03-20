

#ifndef COMPLEXO_HPP
#define COMPLEXO_HPP

// Bibliotecas
#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define rad2deg (180/PI)
#define deg2rad (PI/180)

using namespace std;

class num_complexo{
	public:
		double r;	// Parte real
		double i;	// Parte imaginaria
		double m;	// Modulo
		double a;	// Argumento em graus
		num_complexo(double r_, double i_);
};

class operacao{
	public:
		num_complexo soma(num_complexo c1, num_complexo c2);
		num_complexo sub(num_complexo c1, num_complexo c2);
		num_complexo mult(num_complexo c1, num_complexo c2);
		num_complexo div(num_complexo c1, num_complexo c2);
};

#endif
