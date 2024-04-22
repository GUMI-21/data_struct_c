#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
// sqllist.h
typedef struct {
	int data[MaxSize]; // 顺序表的元素
	int length;	 // 当前的长度 
}SqlList;

// 顺序表习题;
// 01;
bool Del_Min(SqlList *L,int *value) {
	// 删除顺序表中L最小元素节点，并通过value返回
	if (L->length == 0) {
		return false;
	}
	*value = L->data[0]; // 从0开始找
	int i,pos = 0;
	for (i = 1;i < L->length;i++) {
		if (L->data[i] < *value) {
			*value = L->data[i];
			pos = i;
		}
	} 
	L->data[pos] = L->data[L->length-1]; // 空出的位置由最后一个元素替换 
	L->length--; // 减少长度 
	return true;
}

// 02
bool Del_Min2(SqlList *l,int *value) {
	// 循环交换数组中的元素
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
		printf("请输入正确的s与t\n");
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
