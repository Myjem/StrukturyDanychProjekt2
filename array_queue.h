#ifndef SD_PROJ2_ARRAY_QUEUE_H
#define SD_PROJ2_ARRAY_QUEUE_H
#include"base.h"
#include"array_list.h"
#include"queue_node.h"

class array_queue:public Base{
    private:
    ArrayList<node> ArrayQueue;
    public:
    array_queue();
    void insert(int v,int p);//v-value, p-priority
    node extract_max();
    node find_max();
    void modify_key(node e,int p);//We have to find the node to modify priority
    int get_size();
    bool isEmpty();
    void print();
    ~array_queue();

};
#endif