#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
	element* data;
	int capacity;  //현재 크기
	int top; 
}stackType;

void init_stack(stackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element) * s->capacity);
}

void delete(stackType* s)
{
	free(s);
}

int is_full(stackType* s)
{
	return (s->top == s->capacity - 1);
}

int is_empty(stackType* s)
{
	return (s->top == -1);
}

void push(stackType* s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(stackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}



int main()
{
	stackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	free(s.data);
	return 0;
}