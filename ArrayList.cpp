#include "ArrayList.h"
#include <cmath>

using namespace std;

ArrayList::ArrayList() : tab(new int[4]),size(0),capacity(4){};//constructor without argument (tab with 4 slots)

ArrayList::ArrayList(int s) : tab(new int[s]),size(0),capacity(s){};//constructor with argument

void ArrayList::resize() {
    if(size>=capacity){//size up
        capacity*=2;
        int*temp=new int[capacity];
        for(int i=0;i<size;i++) temp[i]=tab[i];//coping old tab to new tab
        delete[] tab;
        tab=temp;
    }
    if(size<floor(0.5*capacity)){//size down
        capacity=floor(0.5*capacity);
        int*temp=new int[capacity];
        for(int i=0;i<size;i++) temp[i]=tab[i];//coping old tab to new tab
        delete[] tab;
        tab=temp;
    }
}

void ArrayList::append(int i, int data) {
    size++;
    resize();
    for(int j=size-1;j>i;j--) tab[j]=tab[j-1];
    tab[i]=data;
}

void ArrayList::del(int i) {
    for(int j=i;j<size;j++) tab[j]=tab[j+1];
    tab[size-1]=0;
    size--;
    resize();
}

void ArrayList::push_back(int data) {
    size++;
    resize();
    tab[size-1]=data;
}

void ArrayList::del_back() {
    tab[size-1]=0;
    size--;
    resize();

}

void ArrayList::push_front(int data) {
    size++;
    resize();
    for(int i=size-1;i>0;i--) tab[i]=tab[i-1];
    tab[0]=data;
}

void ArrayList::del_front() {
    for(int i=0;i<size-1;i++) tab[i]=tab[i+1];
    tab[size-1]=0;
    size--;
    resize();
}

int ArrayList::search(int data) {
    for(int i=0;i<size;i++){
        if(tab[i]==data) return i+1;
    }
    cout<<"Brak elementu"<<endl;//cout for ui
    return 0;
}

int ArrayList::get(int i){
    return tab[i];
}

int ArrayList::get_size() {
    return size;
}

int ArrayList::get_capacity() {
    return capacity;
}

void ArrayList::set(int i, int data) {
    tab[i]=data;
}

void ArrayList::print() {
    for(int i=0;size>i;i++)
        cout<<tab[i]<<"; ";
    cout<<endl;
}

ArrayList::~ArrayList() {//destructor with deleting tab memory
    delete[] tab;
}