#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "config.h"
#include "demo_package.h"

#ifndef HAVE_POW
	#include "math_function.h"
#else
	#include <math.h>
#endif

int main(int argc, char** argv){

	if (argc < 3){
		printf("%s Version %d.%d\n", argv[0], Demo_VERSION_MAJOR, Demo_VERSION_MINOR);
		printf("Usage: %s base exponent \n", argv[0]);
		return 1;
	}
	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
#ifndef HAVE_POW
	printf("Now we use out own math library. \n");
	double result = power(base, exponent);
#else
	printf("Now we use the standard library.\n");
	double result = pow(base, exponent);
#endif
	printf("%g ^ %d is %g\n", base, exponent, result);
	DemoPackage::Print("");
	return 0;
}
