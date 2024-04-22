#include<stdio.h>
#include"mystruct.h"
#include"sqllist.h"
void printList(SqlList l) {
    printf("顺序表元素：");
    int i;
    for ( i = 0; i < l.length; i++) {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
	printf("11111");
    SqlList list = {{1, 3, 5, 7, 9, 11, 13}, 7}; // 假设初始顺序表元素为奇数序列
    int s = 4, t = 10; // 测试删除范围在 4 和 10 之间的元素

    printf("删除前：\n");
    printList(list);

    bool result = del_s_t(&list, s, t);

    if (result) {
        printf("删除成功，删除范围在 %d 和 %d 之间的元素已被删除。\n", s, t);
        printf("删除后：\n");
        printList(list);
    } else {
        printf("删除失败，可能是输入的 s 和 t 不合理或者顺序表为空。\n");
    }

    return 0;
}
