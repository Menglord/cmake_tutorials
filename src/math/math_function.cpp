#include <stdlib.h>

double power(double base, int exponent){
	int result = base;
	if(exponent == 0){
		return 1;
	}
	for (int i = 1; i < exponent; ++i){
		result = result * base;
	}
	return result;
}
