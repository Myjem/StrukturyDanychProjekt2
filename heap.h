#ifndef SD_PROJ2_HEAP_H
#define SD_PROJ2_HEAP_H
#include"ArrayList.h"
#include"queue_node.h"

class Heap{
private:
    ArrayList tab;
public:
    int parent(int i);//i-index
    int left_child(int i);
    int right_child(int i);
    void insert();
    int extract_max();
    int find_max();
    int find_by_key(int p);//p-priority
    int find_by_value(int v);//v-value
    void del(int v);
    void modify_key(int v,int p);
    void heapify();
};

#endif
