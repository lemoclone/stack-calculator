#include <stdio.h>
#include <math.h>

#include "calc.h"

#define MAXLENGTH 100;

int main(){
	char *test[] = {"((((((3+(((((5*4)*5))))))))))","(13+14)*5","(13-14)*5","3*(4+5)","3+(4*5)^2","3*(4-5)^2","3*4^(5-2)","3+4*5-4*2+3","3+4*(5*4-18)^2+3","3*4*(5-2*4)","(3^(((2*3-4^1*(2-1)+4*2))))+3"};
	int i;
	for(i=0; i<11; i++)
		 printf("%s=%d\n",test[i],calc_string(test[i]));
	printf("%f %f\n",calculate('^',-4,2),pow(4,0.5));
	
	for(i=0; i<5; i++)
		printf("%d %f\n",i,pow(i,2));
	return 0;
}