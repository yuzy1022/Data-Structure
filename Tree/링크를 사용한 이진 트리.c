#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode
{
	int data;
	struct treeNode* left, * right;
}treeNode;

int main()
{
	treeNode* n1, * n2, * n3;
	n1 = (treeNode*)malloc(sizeof(treeNode));
	n2 = (treeNode*)malloc(sizeof(treeNode));
	n3 = (treeNode*)malloc(sizeof(treeNode));
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;
	free(n1);
	free(n2);
	free(n3);
	return 0;
}