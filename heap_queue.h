#ifndef SD_PROJ2_HEAP_QUEUE_H
#define SD_PROJ2_HEAP_QUEUE_H
#include"base.h"
#include"queue_node.h"
#include "heap.h"

class Heap_queue:public Base{
private:
    Heap heap;
    int size=0;
public:
    Heap_queue();
    void insert(int e,int p)=0;//e-element, p-priority
    node extract_max()=0;
    node find_max()=0;
    void modify_key(int e,int p);
    int get_size()=0;
    void print()=0;
    ~Heap_queue();
};

#endif
