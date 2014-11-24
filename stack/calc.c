#include <stdlib.h>
#include <stdio.h>

#include "calc.h"

int calc_string(char *cs){

	Stack *stack = newStack(0,NULL,NULL,NULL);	
	int operand = 0;
	int prcd[2];
	int num_oper = 0;
	prcd[0] = prcd[1] = 0;	
	char c;
	int result;

	while((c = *cs)!= '\0'){
		cs++;
		if(isdigit(c)){
			operand = (10*operand) + c - '0';
		}else{
			stack_push(stack,newElmt(operand,"opd",10,NULL));
			stack_display(stack);
			if(c == '^')
				prcd[num_oper] = 2;
			else if(c == '*' || c == '/')
				prcd[num_oper] = 1;
			else if(c == '-' || c == '+')
				prcd[num_oper] = 0;
			else if(c == '(')
				prcd[num_oper] = 3;
			else if(c == ')')  
				prcd[num_oper] = 4;
			num_oper++;
			printf("num_oper:%d oper:%c prcd[1]:%d prcd[0]:%d\n",num_oper,c,prcd[1],prcd[0]);
			
			if(num_oper == 2){
				if(prcd[1]<=prcd[0] && prcd[1]!=3)
					stack_calculate(stack);
				prcd[0] = prcd[1];
		
				if(prcd[1]==4){
					stack_calculate_parenthesis(stack);
					prcd[0] = ((*stack).top)->prty;
				}
						
				num_oper = 1;
			}	
			operand = 0;
			if(prcd[1]!=4)			
				stack_push(stack,newElmt(c,"opr",prcd[1],NULL));
			}
		}
	stack_push(stack,newElmt(operand,"vss",10,NULL));
	
	while((*stack).size >1)
			stack_calculate(stack);
	
	result = ((*stack).top)->pid;
	stack_destroy(stack);
	return result;
}

int calc_string2(char *cs){

	Stack *stack = newStack(0,NULL,NULL,NULL);	
	int operand = 0;
	int prcd[2];
	int num_oper = 0;
	prcd[0] = prcd[1] = 0;	
	char c;
	int result;

	while((c = *cs)!= '\0'){
		cs++;
		if(isdigit(c)){
			operand = (10*operand) + c - '0';
		}else{
			stack_push(stack,newElmt(operand,"opd",1,NULL));
			
			if(c == '^')
				prcd[num_oper] = 2;
			else if(c == '*' || c=='/')
				prcd[num_oper] = 1;
			else if(c == '-' || c=='+')
				prcd[num_oper] = 0;
			num_oper++;
			// printf("num_oper:%d oper:%c prcd[1]:%d prcd[0]:%d\n",num_oper,c,prcd[1],prcd[0]);
			
			if(num_oper == 2){
				if(prcd[1]<=prcd[0])
					stack_calculate(stack);
				prcd[0] = prcd[1];
				num_oper = 1;
			}	
			operand = 0;	
			stack_push(stack,newElmt(c,"opr",2,NULL));
			}
		}
	stack_push(stack,newElmt(operand,"vss",1,NULL));
	while((*stack).size >1)
		stack_calculate(stack);
	result = ((*stack).top)->pid;
	stack_destroy(stack);
	return result;
}