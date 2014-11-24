#ifndef MATHLIB_H
#define MATHLIB_H
#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long  u_ll;
#define MAX(x,y) x > y ? x : y
#define MIN(x,y) x < y ? x : y

/*select m element from a set with n elements*/
u_ll combination(u_ll n, u_ll m);
u_ll factscope(u_ll n, u_ll m);
u_ll fact(u_ll n);

#endif