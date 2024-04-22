#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct {
	int data[MaxSize]; // ��̬������ջ�е�Ԫ��
	int top; 
} SqStack; 

// ��ʼ��ջ
void InitStack(SqStack *S) {
	S->top=-1;
}

// �ж�ն�Ƿ�Ϊ��
bool StackEmpty(SqStack *S) {
	if (S->top == -1) {
		return true;
	} else {
		return false;
	}
}

// ����Ԫ����ջ
bool Push(SqStack *S,int x) {
	if (S->top == MaxSize - 1) { // ջ�������� 
		return false;
	}
	// ָ���ȼ�1 
	S->data[++S->top] = x;
	return true;
} 

// ��ջ����
bool Pop(SqStack *S,int *x) {
	// ջ�ձ��� 
	if (S->top == -1) {
		return false;
	}
	*x = S->data[S->top--];
	return true;
} 

// ��ջ��Ԫ��
bool GetTop(SqStack *S,int *x) {
	if (S->top == -1) {
		return false;
	}
	*x = S->data[S->top];
	return true;
} 

// ����ͷ����ʽջ
typedef struct StackNode{
	int data;
	struct StackNode *next;
}LiStack; 

// �ж�ջ�Ƿ�Ϊ��
bool LiStackEmpty(LiStack *s) {
	if (s==NULL || s->next == NULL) {
		return true;
	}
	return false;
} 

// ����Ԫ����ջ
bool LiPush(LiStack *s,int x) {
	// �½ڵ���Ҫ�����ڴ� 
	LiStack *p = (LiStack*)malloc(sizeof(LiStack));
	if (p == NULL) {
		return true;
	}
	p->data=x;
	p->next = s->next->next;
	s->next = p;
	return true; 
} 

// ��ջ����
bool LiPop(LiStack *s,int *x) {
	if (s==NULL || s->next == NULL) return false;
	LiStack *p = s->next;
	// �ǵö�ȡ��ջ��ֵ 
	*x = p->data;
	s->next = p->next;
	free(p);
	return true;
} 

// ��ջ��Ԫ��
bool LiGetTop(LiStack *S,int *x) {
	if (S==NULL || S->next == NULL) return false;
	*x = S->next->data;
	return true;
} 



 

