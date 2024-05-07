#ifndef SD_PROJ2_QUEUE_NODE_H
#define SD_PROJ2_QUEUE_NODE_H
//node for priority queue with value and priority
struct node{
    int value;
    int priority;

    //overloading operator for comparison for array_queue
    bool operator==(const node& other) const {
        return (value == other.value) && (priority == other.priority);//
    }
};
#endif
