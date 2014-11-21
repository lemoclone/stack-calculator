#ifndef STACK_H
#define STACK_H
#include <stdlib.h> 

#define STACK_MAX 100

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

StackElmt newElmt(int pid, char *name, int prty, StackElmt *next);
Stack newStack(int size, StackElmt *top, StackElmt *bottom, void *data);
int stack_push(Stack *stack,StackElmt *stackElmt);
int stack_pop(Stack *stack,StackElmt *stackElmt);
int stack_isempty();
int stack_isfull();
int stack_clear();
int stack_init();
#endif