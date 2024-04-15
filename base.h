#ifndef SD_PROJ2_BASE_H
#define SD_PROJ2_BASE_H
class Base{//base class for all data structures with virtual methods
public:
    virtual void insert(int e,int p)=0;//e-element, p-priority
    virtual int extract_max()=0;
    virtual int peek()=0;
    virtual void modify_key(int e,int p);
    virtual int get_size()=0;
    virtual void print()=0;
    virtual ~Base(){};
};

#endif
