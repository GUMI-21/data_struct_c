#include<stdio.h>
#define MaxSize=50
typedef struct {
	int data[MaxSize]; // ˳����Ԫ��
	int length;	 // ��ǰ�ĳ��� 
}SqlList;
// ˳���ϰ��
// 01
bool Del_Min(SqlList &L,int &value) {
	// ɾ��˳�����L��СԪ�ؽڵ㣬��ͨ��value����
	if (L.length == 0) {
		return false;
	}
	value = L.data[0]; // ��0��ʼ��
	int pos = 0;
	for (i := 1;i < L.length;i++) {
		if (L.data[i] < value) {
			value = L.data[i];
			pos = i;
		}
	} 
	L.data[pos] = L.data[L.length-1]; // �ճ���λ�������һ��Ԫ���滻 
	L.length--; // ���ٳ��� 
	return true;
}
