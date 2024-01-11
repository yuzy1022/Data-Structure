#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct //스택에 저장되는 데이터를 구조체로 정의
{
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
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
	else
	{
		stack[++top] = item;
	}
}

element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return stack[top--];
	}
}

element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return stack[top];
	}
}

int main()
{
	element item = { 2018021097, "park", "seoul" };
	push(item);
	element pop_item = pop();
	printf("%d\n", pop_item.student_no);
	printf("%s\n", pop_item.name);
	printf("%s\n", pop_item.address);
	element peek_item = peek();
	return 0;
}