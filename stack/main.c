#include <stdio.h>

#include "stack.h"

int main(){
	printf("Hello\n");
	Stack stack;
	
	StackElmt *next;
	StackElmt elmt = newElmt(923,"vss",1,next);
	printf("%d %s %d\n",elmt.pid,elmt.name,elmt.prty);
	return 0;
}