#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
// sqllist.h
typedef struct {
	int data[MaxSize]; // ˳����Ԫ��
	int length;	 // ��ǰ�ĳ��� 
}SqlList;

// ˳���ϰ��;
// 01;
bool Del_Min(SqlList *L,int *value) {
	// ɾ��˳�����L��СԪ�ؽڵ㣬��ͨ��value����
	if (L->length == 0) {
		return false;
	}
	*value = L->data[0]; // ��0��ʼ��
	int i,pos = 0;
	for (i = 1;i < L->length;i++) {
		if (L->data[i] < *value) {
			*value = L->data[i];
			pos = i;
		}
	} 
	L->data[pos] = L->data[L->length-1]; // �ճ���λ�������һ��Ԫ���滻 
	L->length--; // ���ٳ��� 
	return true;
}

// 02
bool Del_Min2(SqlList *l,int *value) {
	// ѭ�����������е�Ԫ��
	int i;
	for (i = 0;i < l->length/2; i ++) {
		int tmp = l->data[i];
		l->data[i] = l->data[l->length-i-1];
		l->data[l->length-i-1] = tmp;
	}
	return true;
}

// 03
bool del_x(SqlList *l,int x) {
	int i,k = 0;
	for (i=0;i<l->length;i++) {
		if (l->data[i] != x) {
			l->data[k] = l->data[i];
			k++;
		}
	}
	l->length=k;
}

// 04
bool del_s_t(SqlList *l,int s,int t) {
	if (s >= t || l->length == 0) {
		printf("��������ȷ��s��t\n");
		return false;
	}
	int i,k=0;
	for (i=0;i<l->length;i++) {
		if (l->data[i] <= s || l->data[i] >= t) {
			l->data[k] = l->data[i];
			k++;
		}
	}
	l->length = k;
	return true;
}
