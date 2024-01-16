#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode
{
	element data;
	struct listNode* link;
}listNode;

void error(char* message)
{
	fprintf(stderr, "%s", message);
	exit(1);
}

listNode* insert_first(listNode* head, element item)
{
	listNode* p = (listNode*)malloc(sizeof(listNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}

listNode* insert(listNode* head, listNode* pre, element item)
{
	listNode* p = (listNode*)malloc(sizeof(listNode));
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}


listNode* delete_first(listNode* head)
{
	listNode* remove;
	if (head == NULL) return NULL;
	remove = head;
	head = remove->link;
	free(remove);
	return head;
}

listNode* delete(listNode* head, listNode* pre)
{
	listNode* remove = pre->link;
	pre->link = remove->link;
	free(remove);
	return head;
}

void print_list(listNode* head)
{
	for (listNode* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main(void)
{
	listNode* head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}
