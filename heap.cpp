#include"heap.h"
#include"queue_node.h"

using namespace std;

bool Heap::isEmpty() {
    if(HeapArray.get_size()==0) return 1;
    else return 0;
}

void Heap::heapify_up(int i){
    int par=parent(i);
    if(par<0 or HeapArray.get(i).priority<HeapArray.get(par).priority) return;
    else
    {
        HeapArray.swap_elements(i,par);
        heapify_up(par);
    }

}

void Heap::heapify_down(int i){
    if(HeapArray.get_size()==1) return;
    int l_ch= left_child(i);
    int r_ch= right_child(i);
    if(l_ch>HeapArray.get_size()-1 or r_ch>HeapArray.get_size()-1) return;
    if(HeapArray.get(i).priority>HeapArray.get(l_ch).priority and HeapArray.get(i).priority>HeapArray.get(r_ch).priority) return;
    else
    {
        if(HeapArray.get(r_ch).priority>HeapArray.get(l_ch).priority) {
            HeapArray.swap_elements(i,r_ch);
            heapify_down(r_ch);
        }
        else {
            HeapArray.swap_elements(i,l_ch);//if children priority are equal I take left child
            heapify_down(l_ch);
        }

    }
}

int Heap::parent(int i){
    return (i-1)/2;
}
int Heap::left_child(int i){
    return (2*i)+1;
}
int Heap::right_child(int i){
    return (2*i)+2;
}

void Heap::insert(node e) {
    HeapArray.push_back(e);
    heapify_up(HeapArray.get_size()-1);
}

node Heap::extract_max() {
    if(isEmpty()==1) return{-1,-1};
    node max=HeapArray.get(0);
    HeapArray.swap_elements(0,HeapArray.get_size()-1);
    HeapArray.del_back();
    heapify_down(0);
    return max;

}
node Heap::find_max() {
    if(isEmpty()==1) return{-1,-1};
    return HeapArray.get(0);
}
node Heap::find_by_key(int p) {
    if(isEmpty()==1) return{-1,-1};
    for(int i=0;i<HeapArray.get_size();i++){
        if(HeapArray.get(i).priority==p) return HeapArray.get(i);
    }
    return{-1,-1};
}
node Heap::find_by_value(int v) {
    if(isEmpty()==1) return{-1,-1};
    for(int i=0;i<HeapArray.get_size();i++){
        if(HeapArray.get(i).value==v) return HeapArray.get(i);
    }
    return{-1,-1};
}


void Heap::del(node e) {
    if(isEmpty()==1) return;
    for(int i=0;i<HeapArray.get_size();i++){
        if( HeapArray.get(i).value==e.value and HeapArray.get(i).priority==e.priority){
            HeapArray.swap_elements(i,HeapArray.get_size()-1);
            HeapArray.del_back();
            heapify_down(i);
            return;

        }
    }

}

void Heap::modify_key(node e, int p) {
    for(int i=0;i<HeapArray.get_size();i++){
        if( HeapArray.get(i).value==e.value and HeapArray.get(i).priority==e.priority){
            int temp=HeapArray.get(i).priority;
            HeapArray.set(i,e);
            if(p>temp) heapify_up(i);
            else heapify_down(i);
            return;
        }
    }
}

int Heap::get_size() {
    return HeapArray.get_size();
}

