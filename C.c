#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct {
    int* arr;
    int Front;
    int Tail;
    int k;
} MyCircularQueue;
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* CQ = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    CQ->arr = (int*)malloc(sizeof(int) * (k + 1));
    CQ->Front = CQ->Tail = 0;
    CQ->k = k;
    return CQ;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        obj->arr[obj->Tail] = value;
        obj->Tail++;
        obj->Tail %= (obj->k + 1);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        obj->Front++;
        obj->Front %= (obj->k + 1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->Front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    // 1
    if (obj->Tail == 0)
    {
        return obj->arr[obj->k];
    }
    else
    {
        return obj->arr[obj->Tail - 1];
    }
    // 2
    //int num=(obj->Tail + obj->k) % (obj->k+1);
    //return obj->arr[num];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->Front == obj->Tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->Tail + 1) % (obj->k + 1) == obj->Front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}



