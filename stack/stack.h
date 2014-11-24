#ifndef STACK_H
#define STACK_H
#include <stdlib.h> 

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

StackElmt* newElmt(int pid, char *name, int prty, StackElmt *next);
Stack* newStack(int size, StackElmt *top, StackElmt *bottom, void *data);
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
#endif