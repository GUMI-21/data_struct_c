#include<stdio.h>
#define MaxSize 10
#include<stdbool.h>
typedef struct {
	// ��̬�����Ŷ���Ԫ�� 
	int data[MaxSize];
	// ��ͷָ��front�Ͷ�βָ��rear 
	int front,rear;
}SqQueue; 

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q) {
	// ͷָ��=βָ�� 
	if (Q.rear == Q.front) {
		return true;
	}
	return false;
}

// ѭ���������
bool EnQueue(SqQueue *Q,int x) {
	if ((Q->rear+1 ) % MaxSize == Q.front) {
		return false;
	}
	// x�����β 
	Q->data[Q->rear] = x;
	// ��βָ����� 
	Q->rear = (Q->rear+1)%MaxSize; 
	return true;
} 

// ����
bool DeQueue(SqQueue *Q,int *x) {
	if (Q->rear == Q->front) {
		return false;
	}
	x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

// ��ȡ��ͷԪ�ص�ֵ 
bool GetHead(SqQueue Q,int *x) {
	if (Q->rear == Q->front) {
		return false;
	}
	x = Q->data[Q->front];
	return true;
}
