#include<stdio.h>
#define MaxSize 10
#include<stdbool.h>
#include<stdlib.h>
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
	if ((Q->rear+1 ) % MaxSize == Q->front) {
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
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

// ��ȡ��ͷԪ�ص�ֵ 
bool GetHead(SqQueue *Q,int *x) {
	if (Q->rear == Q->front) {
		return false;
	}
	*x = Q->data[Q->front];
	return true;
}

// ��ʽ���ж���
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	// ���еĶ�ͷ�Ͷ�βָ��
	LinkNode *front,*rear; 
}LinkQueue;

// ��ʼ������(��ͷ���) ����ͷ���Ļ� Q->front����ָ��next 
void InitLinkQueue(LinkQueue *Q) {
	Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q->front->next = NULL;
} 

// �ж϶����Ƿ�Ϊ�� 
bool IsEmptyLink(LinkQueue *Q) {
	if (Q->front == Q->rear) {
		return true;
	} 
	return false;
}

// ��Ԫ����ӣ���ͷ��㣩
void LinkEnQueue(LinkQueue *Q,int x) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	// �滻��β��� 
	Q->rear->next=s;
	Q->rear=s; 
}

// ����Ԫ�س��ӣ���ͷ��㣩
bool LinkDeQueue(LinkQueue *Q,int *x) {
	if (Q->front == Q->rear) {
		return false;
	}
	LinkNode *p = Q->front->next;
	*x = p->data;
	Q->front->next = p->next;
	// �����һ���ڵ�����޸�rearָ�� 
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	free(p);
	return true;
}



 













