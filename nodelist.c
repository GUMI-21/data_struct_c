#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

// 链表书后题1 
void delx(LinkList L,int x) {
	if (L==NULL) {
		return;
	}
	LNode *p=L->next,*pre=L,*q;
	while(p!=NULL) {
		if (p->data == x) {
			q=p;
			p=p->next;
			pre->next=p;
			free(q);
		} else {
			pre=p;
			p=p->next;
		}
	}
}
// 链表书后题2
void delLinstMin(LinkList L) {
	if (L==NULL || L->next==NULL) {
		return;
	}
	LNode *p=L->next,*pre=L,*minNode=p,*preMin=L, *tmp;
	int min=p->data;
	while(p!=NULL) {
		if (p->data < min) {
			min=p->data;
			minNode=p;
			preMin = pre;
		}
		pre = p;
		p = p->next;
	}
	// 删除最小节点
	tmp = minNode;
	preMin->next=minNode->next;
	free(tmp);
} 

int fun(int n) {
	if(n=1) {
		return 1;
	}
	else return 2*Func(n/2)+n; 
}

// 03 试写算法将带头结点的单链表就地逆置，辅助空间复杂度为0(1)
LinkList invert_list(LinkList L) {
	LNode *pre,*curr = L->next,*next;
	pre->next=NULL; // 作为新表的尾结点 
	while(curr != NULL) {
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	L->next = pre; // 头指针指向新的尾结点 
	return L;
}

// 04 一个带头结点的单链表中，所有节点的元素值无序，删除表中所有介于给定的两个值之间的元素（若存在）
void del_list_x(LinkList L,int x,int y) {
	if (L==NULL || L->next == NULL) {
		return;
	}
	LNode *curr=L->next,*pre=L,*q;
	while (curr != NULL) {
		if (curr->data <y && curr->data > x) {
			q = curr;
			pre->next = curr->next;
			free(q);
		} else {
			pre = curr; // 本节点需要删除时pre不需要变化 
		}
		curr= curr->next;
	}
}

// 06 
LinkList DisCreat_2(LinkList A) {
	LinkList B = (LinkList)malloc(sizeof(LNode)); // 创建B表表头
	B->next=NULL;
	LNode *p = A->next,*q;
	LNode *ra = A; // ra始终指向A的尾结点
	while(p != NULL) {
		ra->next = p; ra = p; // 将*p连链到A的表尾
		p=p->next;
		if(p!=NULL) {
			q=p->next;
			p->next=B->next;
			B->next=p;
			p=q;
		} 
	}
	ra->next = NULL;
	return B;
}







