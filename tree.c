#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// ����һ�ſ���
void main() {
	BiTree root = NULL;
	// ������ڵ�
	root = (BiTree) malloc(sizeof(BiTNode));
	root->data = {1};
	root->lchild=NULL;
	root->rchild=NULL; 
	
	// �����½ڵ�
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = {2};
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p; // ���� 
} 
