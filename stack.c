#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct {
	int data[MaxSize]; // 静态数组存放栈中的元素
	int top; 
} SqStack; 

// 初始化栈
void InitStack(SqStack *S) {
	S->top=-1;
}

// 判断斩是否为空
bool StackEmpty(SqStack *S) {
	if (S->top == -1) {
		return true;
	} else {
		return false;
	}
}

// 新增元素入栈
bool Push(SqStack *S,int x) {
	if (S->top == MaxSize - 1) { // 栈满，报错 
		return false;
	}
	// 指针先加1 
	S->data[++S->top] = x;
	return true;
} 

// 出栈操作
bool Pop(SqStack *S,int *x) {
	// 栈空报错 
	if (S->top == -1) {
		return false;
	}
	*x = S->data[S->top--];
	return true;
} 

// 读栈顶元素
bool GetTop(SqStack *S,int *x) {
	if (S->top == -1) {
		return false;
	}
	*x = S->data[S->top];
	return true;
} 

// 带表头的链式栈
typedef struct StackNode{
	int data;
	struct StackNode *next;
}LiStack; 

// 判断栈是否为空
bool LiStackEmpty(LiStack *s) {
	if (s==NULL || s->next == NULL) {
		return true;
	}
	return false;
} 

// 新增元素入栈
bool LiPush(LiStack *s,int x) {
	// 新节点需要分配内存 
	LiStack *p = (LiStack*)malloc(sizeof(LiStack));
	if (p == NULL) {
		return true;
	}
	p->data=x;
	p->next = s->next->next;
	s->next = p;
	return true; 
} 

// 出栈操作
bool LiPop(LiStack *s,int *x) {
	if (s==NULL || s->next == NULL) return false;
	LiStack *p = s->next;
	// 记得读取出栈的值 
	*x = p->data;
	s->next = p->next;
	free(p);
	return true;
} 

// 读栈顶元素
bool LiGetTop(LiStack *S,int *x) {
	if (S==NULL || S->next == NULL) return false;
	*x = S->next->data;
	return true;
} 



 

