#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode
{
	element data;
	struct listNode* link;
}listNode;

listNode* insert_first(listNode* head, element item)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->data = item;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;
}


listNode* insert_last(listNode* head, element item)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->data = item;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}


void print_list(listNode* head)
{
	if (head == NULL) return;
	listNode* p = head->link;
	do 
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}


int main()
{
	listNode* head = NULL;
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}