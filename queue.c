#include<stdio.h>
#define MaxSize 10
#include<stdbool.h>
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
	if ((Q->rear+1 ) % MaxSize == Q.front) {
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
	x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

// 获取队头元素的值 
bool GetHead(SqQueue Q,int *x) {
	if (Q->rear == Q->front) {
		return false;
	}
	x = Q->data[Q->front];
	return true;
}
