#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode
{
	element data;
	struct listNode* link;
	struct listNode* rlink;
}listNode;

void init(listNode* headNode)
{
	headNode->link = headNode;
	headNode->rlink = headNode;
}

void print_list(listNode* headNode)
{
	listNode* p;
	for (p = headNode->rlink; p != headNode; p = p->rlink)
	{
		printf("<-|%d|->", p->data);
	}
	printf("\n");
}

void insert(listNode* before, element item)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = before;
	newNode->rlink = before->rlink;
	before->rlink = newNode;
	before->rlink->link = newNode;
}

void delete(listNode* headNode, listNode* removeNode)
{
	if (removeNode == headNode) return;
	removeNode->link->rlink = removeNode->rlink;
	removeNode->rlink->link = removeNode->link;
	free(removeNode);
}

int main()
{
	listNode* head = (listNode*)malloc(sizeof(listNode));
	init(head);
	printf("추가단계\n");
	for (int i = 0; i < 5; i++)
	{
		insert(head, i);
		print_list(head);
	}
	printf("삭제단계\n");
	for (int i = 0; i < 5; i++)
	{
		print_list(head);
		delete(head, head->rlink);
	}
	free(head);
	return 0;
}