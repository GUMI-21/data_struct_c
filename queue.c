#include<stdio.h>
#define MaxSize 10
#include<stdbool.h>
#include<stdlib.h>
typedef struct {
	// 静态数组存放队列元素 
	int data[MaxSize];
	// 队头指针front和队尾指针rear 
	int front,rear;
}SqQueue; 

// 判断队列是否为空
bool QueueEmpty(SqQueue Q) {
	// 头指针=尾指针 
	if (Q.rear == Q.front) {
		return true;
	}
	return false;
}

// 循环队列入队
bool EnQueue(SqQueue *Q,int x) {
	if ((Q->rear+1 ) % MaxSize == Q->front) {
		return false;
	}
	// x插入队尾 
	Q->data[Q->rear] = x;
	// 队尾指针后移 
	Q->rear = (Q->rear+1)%MaxSize; 
	return true;
} 

// 出队
bool DeQueue(SqQueue *Q,int *x) {
	if (Q->rear == Q->front) {
		return false;
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

// 获取队头元素的值 
bool GetHead(SqQueue *Q,int *x) {
	if (Q->rear == Q->front) {
		return false;
	}
	*x = Q->data[Q->front];
	return true;
}

// 链式队列定义
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	// 队列的队头和队尾指针
	LinkNode *front,*rear; 
}LinkQueue;

// 初始化队列(带头结点) 不带头结点的话 Q->front不用指定next 
void InitLinkQueue(LinkQueue *Q) {
	Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q->front->next = NULL;
} 

// 判断队列是否为空 
bool IsEmptyLink(LinkQueue *Q) {
	if (Q->front == Q->rear) {
		return true;
	} 
	return false;
}

// 新元素入队（带头结点）
void LinkEnQueue(LinkQueue *Q,int x) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	// 替换表尾结点 
	Q->rear->next=s;
	Q->rear=s; 
}

// 队列元素出队（带头结点）
bool LinkDeQueue(LinkQueue *Q,int *x) {
	if (Q->front == Q->rear) {
		return false;
	}
	LinkNode *p = Q->front->next;
	*x = p->data;
	Q->front->next = p->next;
	// 是最后一个节点出队修改rear指针 
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	free(p);
	return true;
}



 













