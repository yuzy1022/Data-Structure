#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct
{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}dequeType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(dequeType* q)
{
	q->front = q->rear = 0;
}

int is_empty(dequeType* q)
{
	return (q->front == q->rear);
}

int is_full(dequeType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void deque_print(dequeType* q)
{
	printf("DEQUE(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
		} while (i != q->rear);
	}
	printf("\n");
}

void add_rear(dequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(dequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(dequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(dequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(dequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	element item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return item;
}

element get_rear(dequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

int main()
{
	dequeType q;
	init_deque(&q);
	for (int i = 0; i < 3; i++)
	{
		add_front(&q, i);
		deque_print(&q);
	}
	for (int i = 0; i < 3; i++)
	{
		delete_rear(&q);
		deque_print(&q);
	}
	return 0;
}