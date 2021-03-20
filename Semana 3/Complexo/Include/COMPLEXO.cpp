#include "COMPLEXO.hpp"

num_complexo::num_complexo(double r_, double i_){
	r = r_;
	i = i_;
	m = sqrt(pow(r,2) + pow(i,2)); 
	a = atan(i/r) * rad2deg;
};

num_complexo operacao::soma(num_complexo c1, num_complexo c2){
	double r = c1.r + c2.r;
	double i = c1.i + c2.i;
	return num_complexo(r,i);
};

num_complexo operacao::sub(num_complexo c1, num_complexo c2){
	double r = c1.r - c2.r;
	double i = c1.i - c2.i;
	return num_complexo(r,i);
};

num_complexo operacao::mult(num_complexo c1, num_complexo c2){
	double r = c1.r*c2.r - c1.i*c2.i;
	double i = c1.r*c2.i + c1.i*c2.r;
	return num_complexo(r,i);
};

num_complexo operacao::div(num_complexo c1, num_complexo c2){
	operacao operacao;
	
	num_complexo c2_conj(c2.r, -c2.i);
	num_complexo r1 = operacao.mult(c1,c2_conj);
	double den = pow(c2.r,2) + pow(c2.i,2);
	
	return num_complexo(r1.r/den,r1.i/den);
};
