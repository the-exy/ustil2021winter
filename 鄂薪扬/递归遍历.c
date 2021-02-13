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
 
// 递归前序遍历二叉树
void preOrderRec(Tree root){
	if (root != NULL){
		printf(" %c - ", root->data);
		preOrderRec(root->left);
		preOrderRec(root->right);
	}
}


// 递归中序遍历二叉树
void inOrderRec(Tree root){
	if (root != NULL){
		inOrderRec(root->left);
		printf(" %c - ", root->data);
		inOrderRec(root->right);
	}
}


void backOrderRec(Tree root){
	if (root != NULL){
		backOrderRec(root->left);
		backOrderRec(root->right);
		printf(" %c - ", root->data);
		
	}
}
void mian()
{
Tree root = create_tree();
printf("递归前序遍历--- \n");
preOrderRec(root);
	printf("\n");
	printf("递归中序遍历--- \n");
	inOrderRec(root);
	printf("\n");
	printf("递归后序遍历--- \n");
	backOrderRec(root);
	printf("\n");
}
