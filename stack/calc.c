#include <stdlib.h>
#include <stdio.h>

#include "calc.h"

int getprecedence(char c);
int calc_string(char *cs){

	Stack *stack = stack_new(0,NULL,NULL,NULL);	
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
			/*If c is not digit and left parenthesis, push the operand into the stack.*/
			if(c != '(')
				stack_push(stack,elmt_new(operand,"opd",-1,NULL));
			operand = 0;
			if(DEBUGM)
				stack_display_instack(stack);
			/*Use prcd[2] track the operaters.*/
			prcd[num_oper] = getprecedence(c);
			num_oper++;
			
			if(DEBUGM)
				printf("num_oper:%d oper:%c prcd[1]:%d prcd[0]:%d\n",num_oper,c,prcd[1],prcd[0]);
			
			if(num_oper == 2){
				/*If currents precedence higher than previous,calculate the stack,set the operand by the result,waiting the next loop(or the out loop) to push into the stack.*/
				if(prcd[1]<prcd[0] && prcd[0]!=3)
					stack_calculate(stack);
				/*Set the previous precedence to the currents.*/
				prcd[0] = prcd[1];
				num_oper = 1;
				
				/*If the right parenthesis is counted,there must be a left parenthesis before it,so the stack can be evaluated to there,and set the operand by the result,waiting the next loop(or the out loop) to push into the stack.*/
				if(prcd[1] == 4){
					operand = stack_calculate_parenthesis(stack);
					if(DEBUGM)
						printf("stack size: %d operand: %d\n",(*stack).size,operand);
						/*If all the element has popped up,set the num_oper 0*/
					if((*stack).size != 0){
						prcd[0] = (*stack).top->prty;
						if(DEBUGM){
							stack_display_instack(stack);
							printf("%c %s %d\n",(*stack).top->pid,(*stack).top->name,(*stack).top->prty);
						}		
					}else{
						num_oper = 0;
						prcd[0] = prcd[1] = 0;
					}
					}		
				}	
			/*Push the operator after the evaluation of stack(if possible).*/
			if(getprecedence(c)!=4)			
				stack_push(stack,elmt_new(c,"opr",prcd[0],NULL));
			}
		}
	/*Push the last operand to the stack.*/
	stack_push(stack,elmt_new(operand,"vss",-1,NULL));
	
	//stack_display(stack);
	while((*stack).size >1)
			stack_calculate(stack);
	
	result = ((*stack).top)->pid;
	stack_destroy(stack);
	return result;
}

int getprecedence(char c){
	if(c == '^')
		return 2;
	else if(c == '*' || c == '/')
		return 1;
	else if(c == '-' || c == '+')
		return 0;
	else if(c == '(')
		return 3;
	else if(c == ')')  
		return 4;
	else
		return 0;
}

int calc_string2(char *cs){

	Stack *stack = stack_new(0,NULL,NULL,NULL);	
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
			stack_push(stack,elmt_new(operand,"opd",1,NULL));
			
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
			stack_push(stack,elmt_new(c,"opr",2,NULL));
			}
		}
	stack_push(stack,elmt_new(operand,"vss",1,NULL));
	while((*stack).size >1)
		stack_calculate(stack);
	result = ((*stack).top)->pid;
	stack_destroy(stack);
	return result;
}