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

// 05从有序顺序表中删除所有重复元素
bool del_repated(SqlList *l) {
	// 双指针,不相等的时候慢指针的值由快指针替换 慢指针++,快指针每次都要++ 
	if (l->length <= 1) {
		return true;
	}
	int i=0,j=1;
	while (j < l->length) {
		if (l->data[i] != l->data[j]) {
			// 先i++再赋值 
			i++;
			l->data[i] = l->data[j];
		}
		j++;
	}
	l->length = i+1;
}

// 06将两个有序顺序表合为一个新的有序顺序表，并有函数返回
bool compile_array(SqlList *l1,SqlList *l2,SqlList *l3) {
	// 将两个数组按照顺序填入一个新的数组
	int i=0,j=0,k=0;
	while(i < l1->length && j <= l2->length) {
		if (l1->data[i] <= l2->data[j]) {
			l3->data[k] = l1->data[i];
			i++;
		} else {
			l3->data[k] = l2->data[j];
			j++;
		}
		k++;
	}
	while(i<l1->length) {
		l3->data[k] = l1->data[i];
		i++;
		k++;
	}
	while(i<l2->length) {
		l3->data[k] = l2->data[i];
		i++;
		k++;
	}
	l3->length = k;
	return true;
}

// 找到有序表的x值后与后继元素相交换,找不到则插入有序表中使顺序表仍有序
bool SearchExchangeInsert(int A[],int x) {
	int low=0,high=sizeof(A)/sizeof(A[0])-1;
	int mid;
	while(low<=high) {
		mid = (low+high)/2;
		if (A[mid]=x) break;
		else if (A[mid] <x) low=mid+1;
		else high = mid-1;
	}
	if (A[mid] == x && mid != high-1) {
		int t;
		t = A[mid];
		A[mid] = A[mid+1];
		A[mid] = t;
	}
	if (low > high) {
		int i;
		for (i = high-1;i>high;i--) A[i+1] = A[i];
		A[i+1]=x;
	}
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// 09
void samekey(int A[],int B[],int C[],int n) {
	int i = 0,j = 0,k = 0;
	while (i<n&&j<n&&k<n) {
		if (A[i] == B[j] && B[j] == C[k]) {
			printf("%d\n",A[i]);
			i++;k++;j++;
		} else {
			int maxNum=max(A[i],max(B[j],C[k]));
			if (A[i] < maxNum)i++;
			if (B[j] < maxNum)j++;
			if (C[k] < maxNum)k++;
		}
	}
}



