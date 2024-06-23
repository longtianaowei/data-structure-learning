#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;          // 节点数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 定义栈结构
typedef struct {
    Node *top; // 栈顶指针（指向头结点）
    int size;  // 栈的当前大小
} Stack;

// 初始化栈，创建头结点
void InitStack(Stack *s) {
    s->top = (Node *)malloc(sizeof(Node)); // 创建头结点
    if (s->top == NULL) {
        printf("内存分配失败。\n");
        exit(1);
    }
    s->top->next = NULL; // 头结点的下一个指针初始化为空
    s->size = 0;         // 栈大小初始化为0
}

// 判断栈是否为空
int IsEmpty(Stack s) {
    return s.size == 0;
}

// 压栈
int Push(Stack *s, int elem) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败。\n");
        return 0;
    }
    newNode->data = elem;         // 设置新节点的数据
    newNode->next = s->top->next; // 头插法，新节点的下一个节点为头节点的下一个节点
    s->top->next = newNode;       // 头结点的下一个节点指向新节点
    s->size++;                    // 栈大小增加
    return 1;
}

// 出栈
int Pop(Stack *s, int *elem) {
    if (IsEmpty(*s)) {
        printf("栈空，无法出栈！\n");
        return 0;
    }
    Node *temp = s->top->next;   // 临时指针指向头结点之后的第一个节点
    *elem = temp->data;          // 获取该节点的数据
    s->top->next = temp->next;   // 更新头结点的下一个指针为下一个节点
    free(temp);                  // 释放临时指针指向的节点内存
    s->size--;                   // 栈大小减少
    return 1;
}

// 获取栈顶元素
int GetTop(Stack s, int *elem) {
    if (IsEmpty(s)) {
        printf("栈空，无法获取栈顶元素！\n");
        return 0;
    }
    *elem = s.top->next->data;   // 获取头结点之后第一个节点的数据
    return 1;
}

// 打印栈
void PrintStack(Stack *s) {
    Node *current = s->top->next; // 当前节点指针指向头结点之后的第一个节点
    while (current != NULL) {
        printf("%d ", current->data); // 打印当前节点的数据
        current = current->next;      // 当前节点指针移动到下一个节点
    }
    printf("\n");
}

// 释放栈的内存
void FreeStack(Stack *s) {
    Node *current = s->top;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    s->top = NULL;
    s->size = 0;
}

int main() {
    Stack s;
    InitStack(&s);

    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);
    PrintStack(&s);

    int elem;
    GetTop(s,&elem);
    printf("栈顶元素为: %d\n", elem);
    while (!IsEmpty(s)) {
        Pop(&s, &elem);
        printf("出栈元素: %d\n", elem);
    }

    FreeStack(&s);
    return 0;
}
