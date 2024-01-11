#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct stackNode
{
	element data;
	struct stackNode* link;
}stackNode;

typedef struct
{
	stackNode* top;
}linkedStackType;


void init(linkedStackType* s)
{
	s->top = NULL;
}

int is_empty(linkedStackType* s)
{
	return s->top == NULL;
}

int is_full(linkedStackType* s)
{
	return 0;
}

void push(linkedStackType* s, element item)
{
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = item;
	newNode->link = s->top;
	s->top = newNode;
}

void print_stack(linkedStackType* s)
{
	for (stackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

element pop(linkedStackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 공백상태입니다.");;
		exit(1);
	}
	element item = s->top->data;
	stackNode* tmp = s->top;
	s->top = s->top->link;
	free(tmp);
	return item;
}


element peek(linkedStackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 공백상태입니다.");;
		exit(1);
	}
	return s->top->data;
}

int main()
{
	linkedStackType* s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}