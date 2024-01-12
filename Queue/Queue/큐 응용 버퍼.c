#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}queueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(queueType* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(queueType* q)
{
	return q->front == q->rear;
}

int is_full(queueType* q)
{
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void queue_print(queueType* q)
{
	printf("QUEUE(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(queueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(queueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(queueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


int main(void)
{
	queueType q;
	element item;
	init_queue(&q);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		if (rand() % 5 == 0)
			enqueue(&q, rand() % 100);
		queue_print(&q);
		if (rand() % 10 == 0)
		{
			int data = dequeue(&q);
		}
		queue_print(&q);
	}
	return 0;

}