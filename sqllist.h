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

// 05������˳�����ɾ�������ظ�Ԫ��
bool del_repated(SqlList *l) {
	// ˫ָ��,����ȵ�ʱ����ָ���ֵ�ɿ�ָ���滻 ��ָ��++,��ָ��ÿ�ζ�Ҫ++ 
	if (l->length <= 1) {
		return true;
	}
	int i=0,j=1;
	while (j < l->length) {
		if (l->data[i] != l->data[j]) {
			// ��i++�ٸ�ֵ 
			i++;
			l->data[i] = l->data[j];
		}
		j++;
	}
	l->length = i+1;
}

// 06����������˳����Ϊһ���µ�����˳������к�������
bool compile_array(SqlList *l1,SqlList *l2,SqlList *l3) {
	// ���������鰴��˳������һ���µ�����
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

// �ҵ�������xֵ������Ԫ���ཻ��,�Ҳ���������������ʹ˳���������
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



