#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct queueNode
{
	element data;
	struct queueNode* link;
}queueNode;

typedef struct
{
	queueNode* front, *rear;
}linkedQueueType;

void init(linkedQueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(linkedQueueType* q)
{
	return q->front == NULL;
}

int is_full(linkedQueueType* q)
{
	return 0;
}

void enqueue(linkedQueueType* q, element data)
{
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = data;
	newNode->link = NULL;
	if (is_empty(q)) 
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		q->rear->link = newNode;
		q->rear = newNode;
	}
}

element dequeue(linkedQueueType* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "큐가 공백상태입니다.");
		exit(1);
	}
	else
	{
		element data = q->front->data;
		queueNode* tmp = q->front;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(tmp);
		return data;
	}
}

void print_queue(linkedQueueType* q)
{
	queueNode* p;
	for (p = q->front; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main()
{
	linkedQueueType queue;
	init(&queue);
	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	return 0;
}