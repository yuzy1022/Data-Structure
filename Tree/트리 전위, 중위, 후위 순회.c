#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode
{
	int data;
	struct treeNode* left, * right;
}treeNode;

void inorder(treeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void preorder(treeNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(treeNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

treeNode n1 = { 1, NULL, NULL };
treeNode n2 = { 4, &n1, NULL };
treeNode n3 = { 16, NULL, NULL };
treeNode n4 = { 25, NULL, NULL };
treeNode n5 = { 20, &n3, &n4 };
treeNode n6 = { 15, &n2, &n5 };
treeNode* root = &n6;


int main()
{
	printf("중위 순회");
	inorder(root);
	printf("\n");

	printf("전위 순회");
	preorder(root);
	printf("\n");

	printf("후위 순회");
	postorder(root);
	printf("\n");

	return 0;
}