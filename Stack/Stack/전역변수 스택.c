#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //���� �ִ� ũ��
typedef int element; //�������� �ڷ���
element stack[MAX_STACK_SIZE]; //1���� �迭
int top = -1;

int is_empty()
{
	return (top == -1);
}

int is_full()
{
	return (top == MAX_STACK_SIZE - 1);
}

void push(element item)
{
	if (is_full())
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;

	}
	else stack[++top] = item;
}

int pop()
{
	if (is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

int peek()
{
	if (is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main()
{
	push(3);
	push(5);
	push(1);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", peek());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}