#ifndef SD_PROJ2_ARRAY_LIST_H
#define SD_PROJ2_ARRAY_LIST_H
//template class for array list based on dynamic array implementation form first project
#include<iostream>
#include <cmath>
using namespace std;
template <typename T> class ArrayList{
private:
    T*tab = NULL;
    int size;
    int capacity;
public:
    ArrayList();
    ArrayList(int s);
    void append(int i,T data);
    void push_back(T data);
    void del_back();
    void push_front(T data);
    void del_front();
    void del(int i);
    int search(T data);
    void resize();
    T get(int i);
    int get_size();
    int get_capacity();
    void set(int i,T data);
    void swap_elements(int a,int b);
    ~ArrayList();
};

template<typename T>ArrayList<T>::ArrayList() : tab(new T[4]),size(0),capacity(4){};//constructor without argument (tab with 4 slots)

template<typename T>ArrayList<T>::ArrayList(int s) : tab(new T[s]),size(0),capacity(s){};//constructor with argument

template<typename T> void ArrayList<T>::resize() {
    if(size>=capacity){//size up
        capacity*=2;
        T*temp=new T[capacity];
        for(int i=0;i<size;i++) temp[i]=tab[i];//coping old tab to new tab
        delete[] tab;
        tab=temp;
    }
    if(size<floor(0.5*capacity)){//size down
        capacity=floor(0.5*capacity);
        T*temp=new T[capacity];
        for(int i=0;i<size;i++) temp[i]=tab[i];//coping old tab to new tab
        delete[] tab;
        tab=temp;
    }
}

template<typename T> void ArrayList<T>::append(int i, T data) {
    size++;
    resize();
    for(int j=size-1;j>i;j--) tab[j]=tab[j-1];
    tab[i]=data;
}

template<typename T> void ArrayList<T>::del(int i) {
    for(int j=i;j<size;j++) tab[j]=tab[j+1];
    size--;
    resize();
}

template<typename T> void ArrayList<T>::push_back(T data) {
    size++;
    resize();
    tab[size-1]=data;
}

template<typename T> void ArrayList<T>::del_back() {
    size--;
    resize();

}

template<typename T> void ArrayList<T>::push_front(T data) {
    size++;
    resize();
    for(int i=size-1;i>0;i--) tab[i]=tab[i-1];
    tab[0]=data;
}

template<typename T> void ArrayList<T>::del_front() {
    for(int i=0;i<size-1;i++) tab[i]=tab[i+1];
    size--;
    resize();
}

template<typename T> int ArrayList<T>::search(T data) {
    for(int i=0;i<size;i++){
        if(tab[i]==data) return i;
    }
}

template<typename T> T ArrayList<T>::get(int i){
    return tab[i];
}

template<typename T> int ArrayList<T>::get_size() {
    return size;
}

template<typename T> int ArrayList<T>::get_capacity() {
    return capacity;
}

template<typename T> void ArrayList<T>::set(int i, T data) {
    tab[i]=data;
}

template<typename T> void ArrayList<T>::swap_elements(int a, int b) {
    swap(tab[a],tab[b]);
}

template<typename T> ArrayList<T>::~ArrayList() {//destructor with deleting tab memory
    delete[] tab;
}

#endif
