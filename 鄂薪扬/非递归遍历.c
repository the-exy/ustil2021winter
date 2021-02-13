#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
	char data;
	struct node *left;
	struct node *right;
}Node, *Tree;

Tree create_tree(){
	Node *root = NULL;
	char ch;
	scanf("%c", &ch); // 例：输入 ABD##E##C##
 
	if (ch != '#'){
		root = (Node*)malloc(sizeof(Node));
		root->data = ch;
		root->left = create_tree(); 
		root->right = create_tree();
	}
	else{
		root = NULL;
	}
	return root;
}
 

// 非-递归前序遍历二叉树
void preOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int k = -1;
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		k++;
		stack[k] = root;
		while (k > -1){
			node = stack[k--];
			printf(" %c - ", node->data);
			if (node->right != NULL){
				stack[++k] = node->right;
			}
			if (node->left != NULL){
				stack[++k] = node->left;
			}
		}
	}
}


// 非-递归实现中序遍历二叉树
void inOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	node = root;
	while (node != NULL || top > 0){
		while (node != NULL){
			stack[++top] = node;
			node = node->left;
		}
		node = stack[top--];
		printf(" %c - ", node->data);
		node = node->right;
	}
}


void backOrderNRec(Tree root){
	Node *p = root;
	Node *stack[MAXSIZE];
	int num = 0;
	Node *have_visited = NULL;
	while (NULL != p || num>0)
	{
		while (NULL != p)
		{
			stack[num++] = p;
			p = p->left;
		}
		p = stack[num - 1];
		if (NULL == p->right || have_visited == p->right)
		{
			printf(" %c - ", p->data);
			num--;
			have_visited = p;
			p = NULL;
		}
		else
		{
			p = p->right;
		}
	}
}
void main(){
printf("非递归前序遍历--- \n");
	preOrderNRec(root);
	printf("\n");
	printf("非递归中序遍历--- \n");
	inOrderNRec(root);
	printf("\n");
	printf("非递归后序遍历--- \n");
	backOrderNRec(root);
	printf("\n");
}
