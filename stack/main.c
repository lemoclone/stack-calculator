#include <stdio.h>

#include "stack.h"

#define MAXLENGTH 100;

int main(){

	StackElmt *non;
	Stack *stack = newStack(0,non,non,non);	
	
	char c;
	int operand = 0;
	
	while((c = getchar())!= '\n'){
		if(isdigit(c)){
			operand = (10*operand) + c - '0';
		}else{
			printf("%d\n",operand);
			StackElmt *elmtOperand = newElmt(operand,"opd",1,non);
			StackElmt *elmtOperator = newElmt(c,"opr",2,non);
			stack_push(stack,elmtOperand);
			stack_push(stack,elmtOperator);
			operand = 0;
		}	
	};
	StackElmt *elmt = newElmt(operand,"vss",1,non);
	stack_push(stack,elmt);

	// StackElmt *elmt = newElmt(923,"vss",1,non);
	// printf("%d %s %d\n",(*elmt).pid,(*elmt).name,(*elmt).prty);
	
	// StackElmt *elmt2 = newElmt(876,"deamon",4,non);
	// StackElmt *elmt3 = newElmt(123,"srvhos",2,non);
	// stack_push(stack,elmt);
	// stack_push(stack,elmt2);
	// stack_push(stack,elmt3);
	
	// printf("%d %s %d\n",((*stack).top)->pid,((*stack).top)->name,((*stack).top)->prty);
	// printf("%d %s %d\n",((*stack).bottom)->pid,((*stack).bottom)->name,((*stack).bottom)->prty);
	
	// printf("%d %d\n",stack_isempty(stack),stack_isfull(stack));
	while((*stack).size>0){
		if(((*stack).top)->prty ==2)
			printf("%c %s %d\n",((*stack).top)->pid,((*stack).top)->name,((*stack).top)->prty);
		else 
			printf("%d %s %d\n",((*stack).top)->pid,((*stack).top)->name,((*stack).top)->prty);
		stack_pop(stack);
	}
	
	
	return 0;
}