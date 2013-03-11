#include "my_queue.h"
#include <iostream>

void Enqueue(Node_int *&begin, Node_int *& end, int data){
	Node_int *p = NULL;
	p = new Node_int;
	if(end != NULL)
		begin->link = p;
	p->datum = data;
	p->link = NULL;
	begin = p;
	if(end == NULL)
		end = begin;
}

int Dequeue( Node_int *&begin, Node_int *&end){
	if(end != NULL){
		int data = end->datum;
		Node_int *p = end;
		end = end->link;
		p->datum = 0;
		delete p;
		if(end == NULL) begin = NULL;
		return data;
	}
	else return -1;
}

void Clear(Node_int *&begin, Node_int *&end, int size){
	Node_int *p = NULL;
	for(;end != NULL && size!= 0;size++){
		p = end;
		end = end->link;
		p->datum = 0;
		delete p;
	}
	if(end == NULL) begin = NULL;
}

int OnEnd(Node_int *end){
	if(end != NULL) return end->datum;
	else return -1;
}

int OnBegin(Node_int *begin){
	if(begin != NULL) return begin->datum;
	else return -1;
}