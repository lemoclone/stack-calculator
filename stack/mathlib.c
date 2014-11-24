#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "mathlib.h"


u_ll combination(u_ll n, u_ll m){
	if(n < m)
		return -1;
	u_ll x, y;
	u_ll tmp = MAX(m,n-m);
	x = factscope(n,tmp+1);
	y = fact(MIN(m,n-m));
	printf("%lld/%lld\n",x,y);
	return x/y;
}

/*calculate factorial number*/
u_ll fact(u_ll n){
	if(n < 0)
		return -1;
	else if(n == 0)
		return 1;
	else if(n == 1)
		return 1;
	else
		return n*fact(n-1);
}

/*calculate factorial number in the scope [m,n]*/
u_ll factscope(u_ll n, u_ll m){
	printf("%lld\n",n);
	if(n < m)
		return -1;
	else if(n == m)
		return m;
	else
		return n*factscope(n-1,m);
}



/*calculate factorial number with tail recursive*/
u_ll facttail(u_ll n, u_ll a){

}

u_ll calculate(char operator, u_ll num_1, u_ll num_2){
	if(operator == '+')
		return num_1+num_2;
	else if(operator == '-')
		return num_1-num_2;
	else if(operator == '*')
		return num_1*num_2;
	else if(operator == '/')
		return num_1/num_2;
	else if(operator == '^')
		return pow(num_1,num_2);
	else 
		return 0;
}















