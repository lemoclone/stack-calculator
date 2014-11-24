#include <stdio.h>

#include "calc.h"

#define MAXLENGTH 100;

int main(){
	char *test[] = {"3+(5-4)*5","13+14*5","13-14*5","3*4+5","3+4*5^2","3*4-5^2","3*4^5-2","3+4*5-4*2+3","3+4*5-4^2+3","3*4*5-2","3^2*3-2+3"};
	int i;
	for(i=0; i<1; i++)
		printf("%s=%d\n",test[i],calc_string(test[i]));
		
	// Stack *stack = newStack(0,NULL,NULL,NULL);
	// stack_push(stack,newElmt(3,"opd",1,NULL));
	// stack_push(stack,newElmt(4,"opd",1,NULL));	
	// stack_push(stack,newElmt(5,"opd",1,NULL));
	// stack_push(stack,newElmt(6,"opd",1,NULL));	
		
	// stack_display(stack);
	// stack_display(stack);
	
	// Stack *stack = newStack(0,NULL,NULL,NULL);	

	// int operand = 0;
	// int prcd[2];
	// int num_oper = 0;
	// prcd[0] = prcd[1] = 0;
	
	// int number,num_1,num_2;
	// char oper;
	// char c;
	// char *test[] = {"3+4*5","13+14*5","13-14*5","3*4+5","3+4*5^2","3*4-5^2","3*4^5-2","3+4*5-4*2+3","3+4*5-4^2+3","3*4*5-2","3^2*3-2+3"};
	// char *test2[] = {"3*4*5-2"};
	
	// int i;
	// for(i=0; i<11; i++){
		// prcd[0] = prcd[1] = num_oper = 0;
		// operand = 0;
		// printf("%s",test[i]);
		
		// while((c = *test[i])!= '\0'){
		// test[i]++;
		// if(isdigit(c)){
			// operand = (10*operand) + c - '0';
		// }else{
			// StackElmt *elmtOperand = newElmt(operand,"opd",1,non);
			// stack_push(stack,elmtOperand);
			// if(c == '^')
				// prcd[num_oper] = 2;
			// else if(c == '*' || c=='/')
				// prcd[num_oper] = 1;
			// else if(c == '-' || c=='+')
				// prcd[num_oper] = 0;
			// num_oper++;
			// printf("num_oper:%d oper:%c prcd[1]:%d prcd[0]:%d\n",num_oper,c,prcd[1],prcd[0]);
			
			// if(num_oper == 2){
				// if(prcd[1]<=prcd[0])
					// stack_calculate(stack);
				// prcd[0] = prcd[1];
				// num_oper = 1;
			// }	
			// operand = 0;	
			// stack_push(stack,newElmt(c,"opr",2,non));
			// }
		// }
	
		// stack_push(stack,newElmt(operand,"vss",1,non));
		// while((*stack).size >1)
			// stack_calculate(stack);
		// printf("%s = %d\n",test[i],((*stack).top)->pid);
		// stack_clear(stack);
	// }
	return 0;
}