#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

QueueElmt* new_element(int pid, char *name, int prty, QueueElmt *prev){
	QueueElmt *elmt;
	if((elmt = (QueueElmt *)malloc(sizeof(QueueElmt))) == NULL)
		return NULL;
	(*elmt).pid = pid;
	(*elmt).name = name;
	(*elmt).prty = prty;
	
	return elmt;
}

Queue* new_queue(int size, QueueElmt *head, QueueElmt *tail, void *data){
	Queue *queue;
	if((queue = (Queue *)malloc(sizeof(Queue))) == NULL)
		return NULL;
	(*queue).size = 0;
	(*queue).head = NULL;
	(*queue).tail = NULL;
	return queue;
}

int queue_dequeue(Queue *queue){
	if((*queue).size < 0)
		return -1;
	(*queue).head = ((*queue).head)->next;
	(*queue).size--;
	return 0;
}

int queue_enqueue(Queue *queue, QueueElmt *queueElmt){
	if((*queue).size > 100)
		return -1;
	
	if((*queue).size == 0){
		(*queue).tail = queueElmt;
		(*queue).head = queueElmt;
	}else{
		QueueElmt *tmp = (*queue).tail;
		(*queue).tail = queueElmt;
		(*queueElmt).prev = tmp;
		(*tmp).next = queueElmt;
	}	
	(*queue).size++;
	return 0;
}

void display1_queue(Queue *queue){
	while((*queue).size > 0){
		printf("%d %s %d\n",((*queue).head)->pid,((*queue).head)->name,((*queue).head)->prty);
		queue_dequeue(queue);
	}	
}

void display2_queue(Queue *queue){
	while((*queue).head != NULL){
		printf("%d %s %d\n",((*queue).head)->pid,((*queue).head)->name,((*queue).head)->prty);
		queue_dequeue(queue);
	}	
}





















