#include <stdlib.h>

#include "stack.h"
#include "mathlib.h"

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
	int tmp;
	if((*stack).size == 0)
		return -1;
	StackElmt *pop_element = (*stack).top;
	(*stack).top = ((*stack).top)->next;
	(*stack).size--;
	tmp = (*pop_element).pid; 
	free(pop_element);
	return tmp;
}

int stack_isempty(Stack *stack){
	return (*stack).size == 0 ? 1:-1;
}
int stack_isfull(Stack *stack){
	return (*stack).size == MAXSIZE ? 1:-1;
}

int stack_clear(Stack *stack){
	while((*stack).size > 0)
		stack_pop(stack);
	return (*stack).size;
}

int stack_calculate(Stack *stack){
	StackElmt *non;
	int num_2,num_1,number;
	char oper;
	while((*stack).size >1){
		num_2 = stack_pop(stack);
		oper = stack_pop(stack);
		num_1 = stack_pop(stack);
		number = calculate(oper,num_1,num_2);
		//printf("in (prcd[1]<=prcd[0]): %c %d %d %d\n",oper,num_1,num_2,number);
		stack_push(stack,newElmt(number,"opd",1,non));
	}
	return ((*stack).top)->pid;
}

int stack_calculate_parenthesis(Stack *stack){
	StackElmt *non;
	int num_2,num_1,number;
	char oper;
	while((*stack).size >1){
		num_2 = stack_pop(stack);
		oper = stack_pop(stack);
		num_1 = stack_pop(stack);
		stack_pop(stack);
		number = calculate(oper,num_1,num_2);
		//printf("in (prcd[1]<=prcd[0]): %c %d %d %d\n",oper,num_1,num_2,number);
		stack_push(stack,newElmt(number,"opd",1,non));
	}
	return ((*stack).top)->pid;
}


int stack_destroy(Stack *stack){
	if((*stack).size == 0)
		return -1;
	stack_clear;
	free(stack);
	return 0;
}

int stack_display(Stack *stack){
	StackElmt *p;
	p = (*stack).top;
	while(p != NULL){
		if((*p).prty == 10)
			printf("%d",(*p).pid);
		else 
			printf("%c",(*p).pid);
		p = (*p).next;
	}
	printf("\n");
	return 0;
}