#include<stdio.h>
#define MaxSize=50
typedef struct {
	int data[MaxSize]; // 顺序表的元素
	int length;	 // 当前的长度 
}SqlList;
// 顺序表习题
// 01
bool Del_Min(SqlList &L,int &value) {
	// 删除顺序表中L最小元素节点，并通过value返回
	if (L.length == 0) {
		return false;
	}
	value = L.data[0]; // 从0开始找
	int pos = 0;
	for (i := 1;i < L.length;i++) {
		if (L.data[i] < value) {
			value = L.data[i];
			pos = i;
		}
	} 
	L.data[pos] = L.data[L.length-1]; // 空出的位置由最后一个元素替换 
	L.length--; // 减少长度 
	return true;
}
