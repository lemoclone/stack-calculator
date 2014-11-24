#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

#define MAXSIZE 100

typedef struct QueueElmt_{
	int pid;
	char *name;
	int prty;
	struct QueueElmt_ *next;
	struct QueueElmt_ *prev;
}QueueElmt;

typedef struct Queue_{
	int size;
	QueueElmt *head;
	QueueElmt *tail;
	void *data;
}Queue;

QueueElmt* new_element(int pid, char *name, int prty, QueueElmt *next);
Queue* new_queue(int size, QueueElmt *head, QueueElmt *tail, void *data);
void queue_destroy(Queue *queue);
int queue_dequeue(Queue *queue);
int queue_enqueue(Queue *queue, QueueElmt *queueElmt);


#endif
