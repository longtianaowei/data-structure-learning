#include <stdio.h>
#include <stdlib.h>

// 定义双向链表的节点结构
typedef struct DNode {
    int data;               // 数据域
    struct DNode *prev;     // 指向前一个节点的指针
    struct DNode *next;     // 指向下一个节点的指针
} DNode;

// 初始化双向链表
DNode* InitList() {
    DNode *head = (DNode*)malloc(sizeof(DNode));
    if (head == NULL) {
        printf("内存分配失败。\n");
        exit(1);
    }
    head->prev = NULL;
    head->next = NULL;
    return head;
}

// 向双向链表中插入元素
void Insert(DNode *head, int position, int element) {
    DNode *p = head;
    int i = 0;

    while (p != NULL && i < position - 1) {
        p = p->next;
        i++;
    }

    if (p == NULL || i > position - 1) {
        printf("插入位置不合法。\n");
        return;
    }

    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("内存分配失败。\n");
        return;
    }

    newNode->data = element;
    newNode->next = p->next;
    newNode->prev = p;
    if (p->next != NULL) {
        p->next->prev = newNode;
    }
    p->next = newNode;
}


// 删除双向链表中的元素
void Delete(DNode *head, int position) {
    DNode *p = head->next;
    int i = 1;

    while (p != NULL && i < position) {
        p = p->next;
        i++;
    }

    if (p == NULL || i > position) {
        printf("删除位置不合法。\n");
        return;
    }

    p->prev->next = p->next;
    if (p->next != NULL) {
        p->next->prev = p->prev;
    }
    free(p);
}



// 查找双向链表中的元素
int Find(DNode *head, int element) {
    DNode *p = head->next;
    int position = 1;

    while (p != NULL) {
        if (p->data == element) {
            return position;
        }
        p = p->next;
        position++;
    }
    return -1; // 元素不存在
}

// 更新链表中的元素
int Update(DNode *head, int element,int upValue) {
    DNode *p = head->next;
    int position = 1;

    while (p != NULL) {
        if (p->data == element) {
            p->data = upValue;
            return position;
        }
        p = p->next;
        position++;
    }
    return -1; // 元素不存在
}

// 打印双向链表
void PrintList(DNode *head) {
    DNode *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放双向链表的内存
void FreeList(DNode *head) {
    DNode *p = head;
    while (p != NULL) {
        DNode *temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    DNode *list = InitList();

    Insert(list, 1, 10);
    Insert(list, 2, 20);
    Insert(list, 3, 30);
    PrintList(list);

    Delete(list, 2);
    PrintList(list);

    int position = Find(list, 30);
    if (position != -1) {
        printf("元素30的位置是：%d\n", position);
    } else {
        printf("元素30不在链表中。\n");
    }

    int upposition = Update(list,30,33);
    if (upposition != -1) {
        printf("元素30已被更新,新的双链表为");
        PrintList(list);
    } else {
        printf("元素30不在链表中。\n");
    }

    FreeList(list);

    return 0;
}
