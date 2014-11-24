#include <stdio.h>

#include "queue.h"

int main(){
	QueueElmt *non;
	Queue *queue = new_queue(0,non,non,non);	

	QueueElmt *elmt1 = new_element(923,"vss",1,non);
	printf("%d %s %d\n",(*elmt1).pid,(*elmt1).name,(*elmt1).prty);
	QueueElmt *elmt2 = new_element(223,"deamon",1,non);
	QueueElmt *elmt3 = new_element(321,"ssh",1,non);
	
	queue_enqueue(queue,elmt1);
	queue_enqueue(queue,elmt2);
	queue_enqueue(queue,elmt3);
	
	display1_queue(queue);
	free(queue);
	return 0;
}