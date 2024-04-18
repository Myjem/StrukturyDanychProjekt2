#ifndef SD_PROJ2_HEAP_H
#define SD_PROJ2_HEAP_H
#include"array_list.h"
#include"queue_node.h"

class Heap{
private:
    ArrayList<node>HeapArray;
    void heapify_up(int i);
    void heapify_down(int i);
public:
    Heap();
    int parent(int i);
    int left_child(int i);
    int right_child(int i);
    void insert(node e);
    node extract_max();
    node find_max();
    node find_by_key(int p);//p-priority
    node find_by_value(int v);//v-value
    void del(node e);
    void modify_key(node e,int p);
    int get_size();
    bool isEmpty();
    ~Heap();
};

#endif
