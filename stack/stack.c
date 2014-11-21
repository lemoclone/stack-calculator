#include <stdlib.h>

#include "stack.h"

StackElmt newElmt(int pid, char *name, int prty, StackElmt *next){
	StackElmt *new_element;
	if((new_element = (StackElmt *)malloc(sizeof(StackElmt))) == NULL)
		return *new_element;
	(*new_element).pid = pid;
	(*new_element).name = name;
	(*new_element).prty = prty;
	
	return *new_element; 
}

Stack newStack(int size, StackElmt *top, StackElmt *bottom, void *data){
	Stack *new_stack;
	if((new_stack = (Stack *)malloc(sizeof(Stack))) == NULL)
		return *new_stack;
	(*new_stack).size = 0;
	(*new_stack).top = NULL;
	(*new_stack).bottom = NULL;
	
	return *new_stack;
}