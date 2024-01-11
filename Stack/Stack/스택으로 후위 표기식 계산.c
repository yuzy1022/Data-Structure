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


//���� �ʱ�ȭ �Լ�
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


//����ǥ��� ��� �Լ�
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
		if (ch != '+' && ch != '-' && ch != '/' && ch != '*') //�ǿ����ڸ� ���ÿ� ����
		{
			push(&s, ch - '0'); //���ڷ� ����� ���ڸ� ���ڷ� �ٲٱ� ���� '0'�� ����
		}
		else //�����ڸ� ���ÿ��� �ǿ����� �� �� �̾Ƽ� ���� �� ��� ���� �ٽ� ���ÿ� ����
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
	printf("����ǥ��� : 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("��� : %d", result);
	return 0;
}