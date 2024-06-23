#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  // 栈的最大容量

typedef struct {
    int data[MAXSIZE];  // 存放栈中元素的数组
    int top;  // 栈顶指针
} Stack;

// 初始化栈
void InitStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmpty(Stack s) {
    return s.top == -1;
}

// 判断栈是否满
int IsFull(Stack s) {
    return s.top == MAXSIZE - 1;
}

// 压栈
int Push(Stack *s, int elem) {
    if (IsFull(*s)) {
        printf("栈满，无法压栈！\n");
        return 0;
    }
    s->data[++(s->top)] = elem;
    return 1;
}

// 出栈
int Pop(Stack *s, int *elem) {
    if (IsEmpty(*s)) {
        printf("栈空，无法出栈！\n");
        return 0;
    }
    *elem = s->data[(s->top)--];
    return 1;
}

// 获取栈顶元素
int GetTop(Stack s, int *elem) {
    if (IsEmpty(s)) {
        printf("栈空，无法获取栈顶元素！\n");
        return 0;
    }
    *elem = s.data[s.top];
    return 1;
}

int main() {
    Stack s;
    InitStack(&s);

    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);

    int elem;
    GetTop(s,&elem);
    printf("栈顶元素为: %d\n", elem);
    while (!IsEmpty(s)) {
        Pop(&s, &elem);
        printf("出栈元素: %d\n", elem);
    }
    return 0;
}
