#include<stdio.h>
#include<stdlib.h>
// string.h

// 顺序存储 
typedef struct {
	char ch[50];  
	int length;
}SString;

// 堆分配存储
typedef struct {
	char *ch; // 按串长分配存储区，ch指向串的地址 
	int length;
}; 

// 链式存储
typedef struct StringNode {
	char ch[4]; // 每个节点存4个字符
	struct stringNode *next;
}StringNode,*String; 

