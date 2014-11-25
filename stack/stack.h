#ifndef STACK_H
#define STACK_H
#include <stdlib.h> 

#include "stackconstant.h"
#include "mathlib.h"

#define MAXSIZE 100

typedef struct StackElmt_{
	int pid;
	char *name;
	int prty;
	struct StackElmt_ *next;
}StackElmt;

typedef struct Stack_{
	int size;
	StackElmt *top;
	StackElmt *bottom;
	void *data;
}Stack;

StackElmt* elmt_new(int pid, char *name, int prty, StackElmt *next);
Stack* stack_new(int size, StackElmt *top, StackElmt *bottom, void *data);
int stack_push(Stack *stack,StackElmt *stackElmt);
int stack_pop(Stack *stack);
int stack_isempty();
int stack_isfull();
int stack_clear();
int stack_init();
int stack_calculate(Stack *stack);
int stack_calculate_parenthesis(Stack *stack);
int stack_destroy(Stack *stack);
int stack_display(Stack *stack);
int stack_display_instack(Stack *stack);
#endif