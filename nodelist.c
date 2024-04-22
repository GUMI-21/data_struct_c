#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

// ���������1 
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
// ���������2
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
	// ɾ����С�ڵ�
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

// 03 ��д�㷨����ͷ���ĵ�����͵����ã������ռ临�Ӷ�Ϊ0(1)
LinkList invert_list(LinkList L) {
	LNode *pre,*curr = L->next,*next;
	pre->next=NULL; // ��Ϊ�±��β��� 
	while(curr != NULL) {
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	L->next = pre; // ͷָ��ָ���µ�β��� 
	return L;
}

// 04 һ����ͷ���ĵ������У����нڵ��Ԫ��ֵ����ɾ���������н��ڸ���������ֵ֮���Ԫ�أ������ڣ�
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
			pre = curr; // ���ڵ���Ҫɾ��ʱpre����Ҫ�仯 
		}
		curr= curr->next;
	}
}

// 06 
LinkList DisCreat_2(LinkList A) {
	LinkList B = (LinkList)malloc(sizeof(LNode)); // ����B���ͷ
	B->next=NULL;
	LNode *p = A->next,*q;
	LNode *ra = A; // raʼ��ָ��A��β���
	while(p != NULL) {
		ra->next = p; ra = p; // ��*p������A�ı�β
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







