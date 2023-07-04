//#include <stdio.h>
#include <math.h>
#include "sigmoid.h"

int sigmoid(double n) {
	printf("Hello\n");
	double value = 1 / (1 + pow(EULER_NUMBER, -n));
	printf("value %lf \n",value);
	if(value>=.5)
	{
	return 1;
	}
else
	{
	return 0;
	}
}

float sigmoidf(float n) {
    return (1 / (1 + powf(EULER_NUMBER_F, -n)));
}

long double sigmoidl(long double n) {
    return (1 / (1 + powl(EULER_NUMBER_L, -n)));
}

double relud(double n)
{
if (n < 0)
	{
	printf("Relud(%lf) = 0\n",n);
	return 0;
	}
else
	{
	printf("Relud(%lf) ==  %f\n",n,n);
	return n;
	}

}

float relu(float n)
{
if (n < 0)
	{
	printf("Relu(%f) %f\n",n,n);
	return 0;
	}
else
	{
	printf("Relu(%f) %f\n",n,n);
	return n;
	}

}
/*
int main()
{
int op=0;
float fl = sigmoidf(0.37); 
printf("sig(0.37)=%f",fl);
if(fl>=.5)
	{
	op = 1;
	printf(" == %d\n",op);
	}
else
	{
	op = 0;
	printf(" == %d\n", op);
	}
fl = sigmoidf(-7.7); 
printf("sig(-7.7)=%f",fl);
if(fl>=.5)
	{
	op = 1;
	printf(" == %d\n",op);
	}
else
	{
	op = 0;
	printf(" == %d\n", op);
	}
//printf(sigmoid(7));
//printf(sigmoidf(0.37));
//printf(sigmoidf(-7.7));
relu(7.2);
relu(-0.2);
}
*/
