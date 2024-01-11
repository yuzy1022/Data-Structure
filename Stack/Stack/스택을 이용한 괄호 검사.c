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

int check_matching(const char* in)
{
	stackType s;
	init_stack(&s);
	char ch, open_ch; //ch=다음문자 open_ch=스택에서 뽑아낸 문자
	int i, n = strlen(in); //n = 문자열 길이

	for (i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch)
		{
		case '(': case '{': case '[':
			push(&s, ch);
			break;
		case ')': case '}': case ']':
			if (is_empty(&s)) return 0;
			open_ch = pop(&s);
			if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']'))
			{
				return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) //스택에 남아있으면 오류
		return 0;
	return 1;
}



int main(void)
{
	char* p = "[{A[(i+1)]=0;})";
	if (check_matching(p))
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;

}