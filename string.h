#include<stdio.h>
#include<stdlib.h>
// string.h

// ˳��洢 
typedef struct {
	char ch[50];  
	int length;
}SString;

// �ѷ���洢
typedef struct {
	char *ch; // ����������洢����chָ�򴮵ĵ�ַ 
	int length;
}; 

// ��ʽ�洢
typedef struct StringNode {
	char ch[4]; // ÿ���ڵ��4���ַ�
	struct stringNode *next;
}StringNode,*String; 

