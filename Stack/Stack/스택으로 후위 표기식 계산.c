#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct
{
	int top;
	element data[MAX_STACK_SIZE];
}stackType;


//스택 초기화 함수
void init_stack(stackType* s)
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
		fprintf(stderr, "스택 포화 에러\n");
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
		fprintf(stderr, "스택 공백 에러\n");
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
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)];
	}
}


//후위표기식 계산 함수
int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	stackType s;

	init_stack(&s);
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '/' && ch != '*') //피연산자면 스택에 넣음
		{
			push(&s, ch - '0'); //문자로 저장된 숫자를 숫자로 바꾸기 위해 '0'을 빼줌
		}
		else //연산자면 스택에서 피연산자 두 개 뽑아서 연산 후 결과 값을 다시 스택에 넣음
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}


int main()
{
	int result;
	char a[9] = "82/3-32*+";
	printf("후위표기식 : 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과 : %d", result);
	return 0;
}