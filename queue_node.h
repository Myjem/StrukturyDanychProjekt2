#ifndef SD_PROJ2_QUEUE_NODE_H
#define SD_PROJ2_QUEUE_NODE_H
struct node{
    int value;
    int priority;

    bool operator==(const node& other) const {
        return (value == other.value) && (priority == other.priority);
    }
};
#endif
