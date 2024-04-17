#ifndef SD_PROJ2_BASE_H
#define SD_PROJ2_BASE_H
#include "queue_node.h"
class Base{//base class for all data structures with virtual methods
public:
    virtual void insert(int e,int p)=0;//e-element, p-priority
    virtual node extract_max()=0;
    virtual node find_max()=0;
    virtual void modify_key(int e,int p);
    virtual int get_size()=0;
    virtual void print()=0;
    virtual ~Base(){};
};

#endif
