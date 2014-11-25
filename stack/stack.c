#include <stdlib.h>

#include "stack.h"

StackElmt* elmt_new(int pid, char *name, int prty, StackElmt *next){
	StackElmt *new_element;
	if((new_element = (StackElmt *)malloc(sizeof(StackElmt))) == NULL)
		return NULL;
	(*new_element).pid = pid;
	(*new_element).name = name;
	(*new_element).prty = prty;
	
	return new_element;
}

Stack* stack_new(int size, StackElmt *top, StackElmt *bottom, void *data){
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
	int num_2,num_1,result;
	char oper;
	/*Consider three different cases of a+(b*c) and a+b*c and (a+b*c)*/
	while((*stack).size > 1 && (*stack).top->next->prty != 3){
		num_2 = stack_pop(stack);
		oper = stack_pop(stack);
		num_1 = stack_pop(stack);
		result = calculate(oper,num_1,num_2);
		if(DEBUGM)
			printf("stack_calculate: %c %d %d %d\n",oper,num_1,num_2,result);
		stack_push(stack,elmt_new(result,"opd",-1,NULL));
	}
	return result;
}

int stack_calculate_parenthesis(Stack *stack){
	int num_2,num_1,result;
	char oper;
	/*Consider three different cases of a+(b*c) and a+b*c and (a+b*c)*/
	while((*stack).size >1){
		num_2 = stack_pop(stack);
		oper = stack_pop(stack);
		if(oper =='(')
			return num_2;
		else {
			num_1 = stack_pop(stack);
			result = calculate(oper,num_1,num_2);
			stack_push(stack,elmt_new(result,"opd",-1,NULL));
			if(DEBUGM)
				printf("stack_calculate_parenthesis: %c %d %d %d\n",oper,num_1,num_2,result);	
		}
	}
	return result;
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
		if((*p).prty == -1)
			printf("%d",(*p).pid);
		else 
			printf("%c",(*p).pid);
		p = (*p).next;
	}
	printf("\n");
	return 0;
}

int stack_display_instack(Stack *stack){
	StackElmt *p;
	p = (*stack).top;
	while(p != NULL){
		if((*p).prty == -1)
			printf("%d %s %d\n",(*p).pid,(*p).name,(*p).prty);
		else 
			printf("%c %s %d\n",(*p).pid,(*p).name,(*p).prty);
		p = (*p).next;
	}
	printf("\n");
	return 0;
}