#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct
{
	element array[MAX_LIST_SIZE];
	int size;
}arrayListType;

void error(char* message)
{
	fprintf(stderr, "%s", message);
	exit(1);
}

void init(arrayListType* l)
{
	l->size = 0;
}

int is_full(arrayListType* l)
{
	return l->size == MAX_LIST_SIZE;
}

int is_empty(arrayListType* l)
{
	return l->size == 0;
}

void print_list(arrayListType* l)
{
	int i;
	for (i = 0; i < l->size; i++)
	{
		printf("%d->", l->array[i]);
	}
	printf("\n");
}

void insert_last(arrayListType* l, element item)
{
	if (is_full(l))
		error("리스트 오버플로우");
	l->array[(l->size)++] = item;
}

void insert(arrayListType* l, int pos, element item)
{
	if (!is_full(l) && pos >= 0 && pos <= l->size)
	{
		for (int i = l->size - 1; i >= pos; i--)
			l->array[i + 1] = l->array[i];
		l->array[pos] = item;
		l->size++;
	}
}

element delete(arrayListType* l, int pos)
{
	if (is_empty(l) && pos >= l->size)
		error("위치오류");
	element item = l->array[pos];
	for (int i = pos; i < l->size - 1; i++)
		l->array[i] = l->array[i + 1];
	l->size--;
	return item;
}


int main()
{
	arrayListType l;
	init(&l);

	insert(&l, 0, 10); print_list(&l);
	insert(&l, 0, 20); print_list(&l);
	insert(&l, 0, 30); print_list(&l);
	insert_last(&l, 40); print_list(&l);
	delete(&l, 0); print_list(&l);
	return 0;

}