#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 定义一颗空树
void main() {
	BiTree root = NULL;
	// 插入根节点
	root = (BiTree) malloc(sizeof(BiTNode));
	root->data = {1};
	root->lchild=NULL;
	root->rchild=NULL; 
	
	// 插入新节点
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = {2};
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p; // 左孩子 
} 
