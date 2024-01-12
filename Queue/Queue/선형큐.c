#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}queueType;


//오류함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


//큐 초기화
void init_queue(queueType* q)
{
	q->front = -1;
	q->rear = -1;
}


//큐 내용을 전부 출력
void queue_print(queueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i < q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}


int is_full(queueType* q)
{
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(queueType* q)
{
	return (q->front == q->rear);
}

void enqueue(queueType* q, element item)
{
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(queueType* q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
		return -1;
	}
	return q->data[++(q->front)];
}

int main()
{
	int item = 0;
	queueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	printf("%d\n", dequeue(&q)); queue_print(&q);
	printf("%d\n", dequeue(&q)); queue_print(&q);
	printf("%d\n", dequeue(&q)); queue_print(&q);
	return 0;
}