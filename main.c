#include<stdio.h>
#include"mystruct.h"
#include"sqllist.h"
void printList(SqlList l) {
    printf("˳���Ԫ�أ�");
    int i;
    for ( i = 0; i < l.length; i++) {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
	printf("11111");
    SqlList list = {{1, 3, 5, 7, 9, 11, 13}, 7}; // �����ʼ˳���Ԫ��Ϊ��������
    int s = 4, t = 10; // ����ɾ����Χ�� 4 �� 10 ֮���Ԫ��

    printf("ɾ��ǰ��\n");
    printList(list);

    bool result = del_s_t(&list, s, t);

    if (result) {
        printf("ɾ���ɹ���ɾ����Χ�� %d �� %d ֮���Ԫ���ѱ�ɾ����\n", s, t);
        printf("ɾ����\n");
        printList(list);
    } else {
        printf("ɾ��ʧ�ܣ������������ s �� t ���������˳���Ϊ�ա�\n");
    }

    return 0;
}
