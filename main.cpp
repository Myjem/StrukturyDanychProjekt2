#include<iostream>
#include "ui.h"
#include<fstream>
#include<ctime>
#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include"array_queue.h"
#include"heap_queue.h"
#include "array_list.h"
using namespace std;

int main(){
    srand(time(NULL));
    int size_file=100000;
    int q=50;
    int random_push = 100001;
    int random_prio1[q];
    int random_prio2[q];
    int random_mod[q];
    ArrayList<node> nodetab;
    for(int i=0;i<q;i++){
        random_prio1[i] = ((rand()%500000) + 1);
        random_prio2[i] = ((rand()%500000) + 1);
        random_mod[i] = ((rand()%size_file) + 1);

    }
    fstream file;
    array_queue**tab=new array_queue*[q];
    for(int i=0;i<q;i++) tab[i]=new array_queue;

    file.open("data.txt",ios::in);
    for (int i = 0; size_file > i and file.eof() != 1; i++) {
        string t1,t2;
        int value, prio;
        getline(file,t1,' ');
        getline(file,t2);
        value = stoi(t1);
        prio = stoi(t2);
        node tnode = {value,prio};
        nodetab.push_back(tnode);
        for(int i=0;q>i;i++) tab[i]->insert(value,prio);
        

    }
    cout<<"ArrayQueue:" << endl;
    cout<<"Wczytano" << endl;
    cout << "Rozmiar pliku: " << size_file << endl;

     //insert
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->insert(random_push,random_prio1[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
     cout<<"Czas dodania: "<<time.count()/q<<" ns"<<endl;

    //extract
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->extract_max();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas wyjecia najwiekszego priorytetu: "<<time.count()/q<<" ns"<<endl;

    //peek
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->find_max();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas znalezienia najwiekszego priorytetu: "<<time.count()/q<<" ns"<<endl;

    //modify
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->modify_key(nodetab.get(random_mod[i]), random_prio2[i]);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas zmodyfikowania priorytetu: "<<time.count()/q<<" ns"<<endl;

    //size
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->get_size();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas dostania rozmiaru: "<<time.count()/q<<" ns"<<endl;

    for(int i=0;q>i;i++) delete tab[i];
    delete[] tab;

    //ui();
    return 0;
}