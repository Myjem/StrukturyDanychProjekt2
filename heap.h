#ifndef SD_PROJ2_HEAP_H
#define SD_PROJ2_HEAP_H
#include"array_list.h"
#include"queue_node.h"

class Heap{
private:
    ArrayList<node>tab;
    void heapify_up();
    void heapify_down();
public:
    Heap();
    void insert();
    node extract_max();
    node find_max();
    node find_by_key(int p);//p-priority
    node find_by_value(int v);//v-value
    void del(int v);
    void modify_key(int v,int p);
    ~Heap();
};

#endif
