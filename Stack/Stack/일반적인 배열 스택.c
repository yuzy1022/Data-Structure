#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct
{
	int top;
	element data[MAX_STACK_SIZE];
}stackType;


//���� �ʱ�ȭ �Լ�
void init_stack(stackType *s) 
{
	s->top = -1;
}

int is_empty(stackType* s)
{
	return (s->top == -1);
}

int is_full(stackType* s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(stackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

element pop(stackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}

element peek(stackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)];
	}
}


int main()
{
	stackType stack;
	stackType stack2;

	init_stack(&stack);
	init_stack(&stack2);
	push(&stack, 5);
	push(&stack, 3);
	push(&stack2, 5);
	push(&stack2, 3);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack2));
	printf("%d\n", pop(&stack2));
	printf("%d\n", peek(&stack2));


}