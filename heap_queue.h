#ifndef SD_PROJ2_HEAP_QUEUE_H
#define SD_PROJ2_HEAP_QUEUE_H
#include"base.h"
#include"queue_node.h"
#include "heap.h"

class Heap_queue:public Base{
private:
    Heap heap;
public:
    Heap_queue();
    void insert(int v,int p);//v-value, p-priority
    node extract_max();
    node find_max();
    void modify_key(node e,int p);
    int get_size();
    bool isEmpty();
    void print();
    ~Heap_queue();
};

#endif
