#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //스택 최대 크기
typedef int element; //데이터의 자료형
element stack[MAX_STACK_SIZE]; //1차원 배열
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
		fprintf(stderr, "스택 포화 에러\n");
		return;

	}
	else stack[++top] = item;
}

int pop()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

int peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
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