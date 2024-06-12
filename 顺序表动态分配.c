#include <stdio.h>
#include <stdlib.h>

// 定义顺序表结构
typedef struct {
    int *data;  // 存放顺序表的元素
    int length; // 顺序表的当前长度
    int capacity; // 顺序表的最大容量
} SeqList;

// 初始化顺序表
void InitList(SeqList *list, int initialSize) {
    list->data = (int *)malloc(initialSize * sizeof(int));
    if (list->data == NULL) {
        printf("内存分配失败。\n");
        exit(1);
    }
    list->length = 0;
    list->capacity = initialSize;
}

// 判断顺序表是否为空
int IsEmpty(SeqList list) {
    return list.length == 0;
}

// 判断顺序表是否已满
int IsFull(SeqList list) {
    return list.length == list.capacity;
}

// 扩展顺序表的容量
void ExpandList(SeqList *list) {
    int newCapacity = list->capacity * 2;
    int *newData = (int *)realloc(list->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("内存重新分配失败。\n");
        exit(1);
    }
    list->data = newData;
    list->capacity = newCapacity;
}

// 向顺序表中插入元素
int Insert(SeqList *list, int position, int element) {
    if (position-1 < 0 || position-1 > list->length) {
        printf("插入位置不合法。\n");
        return 0;
    }
    if (IsFull(*list)) {
        ExpandList(list);
    }
    // 将插入位置之后的元素后移
    for (int i = list->length; i > position-1; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[position-1] = element; // 插入新元素
    list->length++;                 // 顺序表长度增加
    return 1;
}

// 删除顺序表中的元素
int Delete(SeqList *list, int position) {
    if (IsEmpty(*list)) {
        printf("顺序表为空，无法删除元素。\n");
        return 0;
    }
    if (position-1 < 0 || position-1 >= list->length) {
        printf("删除位置不合法。\n");
        return 0;
    }
    // 将删除位置之后的元素前移
    for (int i = position-1; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--; // 顺序表长度减少
    return 1;
}

// 按查找顺序表中的元素
int Find(SeqList list, int element) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == element) {
            return i+1; // 返回元素位置
        }
    }
    return -1; // 元素不存在
}

// 按值查找顺序表中的元素并修改 （改）
int Update(SeqList *list, int element, int upValue) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == element) {
            // 更新值
            list->data[i] = upValue;
            return 1;
        }
    }
    return -1; // 元素不存在
}

// 打印顺序表
void PrintList(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

// 释放顺序表的内存
void FreeList(SeqList *list) {
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->capacity = 0;
}

int main() {
    SeqList list;
    InitList(&list, 5);

    Insert(&list, 1, 10);
    Insert(&list, 2, 20);
    Insert(&list, 3, 30);
    PrintList(list);

    Delete(&list, 1);
    PrintList(list);

    int position = Find(list, 30);
    if (position != -1) {
        printf("元素30的位置是：%d\n", position);
    } else {
        printf("元素30不在顺序表中。\n");
    }

    int upposition = Update(&list,30,33);
     if (upposition != -1) {
        printf("元素30的已被更新,新的顺序表为");
        PrintList(list);
    } else {
        printf("元素30不在顺序表中。\n");
    }

    FreeList(&list);

    return 0;
}
