#include"heap.h"
#include"queue_node.h"

using namespace std;
void Heap::heapify_up(node e){}
void Heap::heapify_down(node e){}
node Heap::parent(int i){}
node Heap::left_child(int i){}
node Heap::right_child(int i){}

void Heap::insert(node e) {
    HeapArray.push_back(e);
    heapify_up(e);
}

node Heap::extract_max() {
    HeapArray.swap_elements(0,HeapArray.get_size()-1);
}
node Heap::find_max() {}
node Heap::find_by_key(int p) {}
node Heap::find_by_value(int v) {}
void Heap::del(int v) {}
void Heap::modify_key(int v, int p) {}
Heap::~Heap(){};
