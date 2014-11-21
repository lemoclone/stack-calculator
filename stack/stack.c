#include <stdlib.h>

#include "stack.h"

StackElmt* newElmt(int pid, char *name, int prty, StackElmt *next){
	StackElmt *new_element;
	if((new_element = (StackElmt *)malloc(sizeof(StackElmt))) == NULL)
		return NULL;
	(*new_element).pid = pid;
	(*new_element).name = name;
	(*new_element).prty = prty;
	
	return new_element;
}

Stack* newStack(int size, StackElmt *top, StackElmt *bottom, void *data){
	Stack *new_stack;
	if((new_stack = (Stack *)malloc(sizeof(Stack))) == NULL)
		return NULL;
	(*new_stack).size = 0;
	(*new_stack).top = NULL;
	(*new_stack).bottom = NULL;
	
	return new_stack;
}

int stack_push(Stack *stack,StackElmt *stackElmt){
	if((*stack).size == MAXSIZE)
		return -1;
	if((*stack).size == 0)
		(*stack).bottom = stackElmt;	
		
	StackElmt *tmpElmt = (*stack).top;
	(*stack).top = stackElmt;
	(*stackElmt).next = tmpElmt;
	
	(*stack).size++;
	return 0;
}

int stack_pop(Stack *stack){
	if((*stack).size == 0)
		return -1;
	(*stack).top = ((*stack).top)->next;
	
	(*stack).size--;
	return 0;
}

int stack_isempty(Stack *stack){
	return (*stack).size == 0 ? 1:-1;
}
int stack_isfull(Stack *stack){
	return (*stack).size == MAXSIZE ? 1:-1;
}