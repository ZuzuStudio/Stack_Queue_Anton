#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include"stack_queue.h"

void Enqueue(Node_int *&, Node_int *&, int);
int Dequeue(Node_int *&, Node_int *&);
void Clear(Node_int *&, Node_int *&, int = -1);
int OnEnd(Node_int *);
int OnBegin(Node_int *);

#endif
