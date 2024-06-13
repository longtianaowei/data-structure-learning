#include <stdio.h>
#include <stdlib.h>

// 定义单链表的节点结构
typedef struct Node {
    int data;           // 数据域
    struct Node *next;  // 指针域，指向下一个节点
} Node;

// 初始化链表
Node* InitList() {
    Node *head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("内存分配失败。\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

// 向链表中插入元素
void Insert(Node *head, int position, int element) {
    Node *p = head;
    int i = 0;

    // 遍历链表，找到插入位置的前一个节点
    while (p != NULL && i < position - 1) {
        p = p->next;
        i++;
    }

    // 检查插入位置是否合法
    if (p == NULL || i > position - 1) {
        printf("插入位置不合法。\n");
        return;
    }

    // 分配新节点的内存
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败。\n");
        return;
    }

    // 插入新节点
    newNode->data = element;
    newNode->next = p->next;
    p->next = newNode;
}



// 删除链表中的元素
void Delete(Node *head, int position) {
    Node *p = head;
    int i = 0;

   // 遍历链表，找到插入位置的前一个节点
    while (p->next != NULL && i < position - 1) {
        p = p->next;
        i++;
    }

    if (p->next == NULL || i > position - 1) {
        printf("删除位置不合法。\n");
        return;
    }

    // 将指针 temp 指向要删除的节点。
    Node *temp = p->next;
    //将当前节点的下一节点指向要删除节点的下一节点，跳过要删除的节点。 这里的temp为要删除的节点 p为删除节点的前一个节点
    p->next = temp->next;
    free(temp);
}

// 查找链表中的元素
int Find(Node *head, int element) {
    Node *p = head->next;
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
int Update(Node *head, int element,int upValue) {
    Node *p = head->next;
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

// 打印链表
void PrintList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放链表的内存
void FreeList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    Node *list = InitList();

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
        printf("元素30已被更新,新的单链表为");
        PrintList(list);
    } else {
        printf("元素30不在顺序表中。\n");
    }

    FreeList(list);

    return 0;
}

