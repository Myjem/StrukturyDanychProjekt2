#include "heap_queue.h"
#include "queue_node.h"

using namespace std;

Heap_queue::Heap_queue() {}

void Heap_queue::insert(int v, int p) {
    node temp={v,p};
    heap.insert(temp);
}

node Heap_queue::extract_max() {
    return heap.extract_max();
}

node Heap_queue::find_max() {
    return heap.find_max();
}

void Heap_queue::modify_key(node e, int p) {
    heap.modify_key(e,p);
}

int Heap_queue::get_size() {
    return heap.get_size();
}

bool Heap_queue::isEmpty() {
    return heap.isEmpty();
}

void Heap_queue::print() {
    cout<<"Ilosc elementow w kolejce: "<<get_size()<<endl;
    while(isEmpty()!=1){
        node temp=extract_max();
        cout<<"Wartosc: "<<temp.value<<" Priorytet: "<<temp.priority<<endl;
    }
}

Heap_queue::~Heap_queue(){}