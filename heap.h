#ifndef SD_PROJ2_HEAP_H
#define SD_PROJ2_HEAP_H
#include"array_list.h"
#include"queue_node.h"

class Heap{
private:
    ArrayList<node>HeapArray;
    void heapify_up(node e);
    void heapify_down(node e);
public:
    Heap();
    node parent(int i);
    node left_child(int i);
    node right_child(int i);
    void insert(node e);
    node extract_max();
    node find_max();
    node find_by_key(int p);//p-priority
    node find_by_value(int v);//v-value
    void del(int v);
    void modify_key(int v,int p);
    ~Heap();
};

#endif
