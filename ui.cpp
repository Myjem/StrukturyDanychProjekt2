#include "ui.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<fstream>
#include <string>
#include "base.h"
#include "heap_queue.h"
#include "array_queue.h"
#include "queue_node.h"
using namespace std;

void ui() {
    while (true) {
        int number, mode;//mode==type of stucture, number==operation
        Base*tab;
        cout << "Wybierz strukture: " << endl;
        cout << "[1] Kolejka priorytetowa na kopcu" << endl;
        cout << "[2] Kolejka priorytetowa na tablicy dynamicznej" << endl;//work in progress
        cout << "[0] Zakoncz" << endl << endl;
        cout << "Wybor: ";
        cin >> mode;
        cout << endl;
        bool start = true;//for closing ui
        switch (mode) {//making structure
            case 1: {
                Heap_queue *t= new Heap_queue;
                tab=t;
                break;
            }
            case 2: {
                //SingleListHead *t = new SingleListHead;
                //tab=t;
                array_queue *t = new array_queue;
                tab=t;
                break;
            }
            default: {
                cout << "Program zakonczony";
                return;
            }
        }

        while (start == 1) {
            switch (mode) {
                case 1: {
                    cout << "Kolejka priorytetowa na kopcu:" << endl;
                    break;

                }
                case 2: {
                    cout << "Kolejka priorytetowa na tablicy dynamicznej:" << endl;
                    break;
                }
                default: {
                    cout << "Zly tryb";
                    start = 0;
                    break;
                }
            }
            cout << "[1] Zbuduj z pliku" << endl;
            cout << "[2] Utworz losowo" << endl;
            cout << "[3] Dodaj element" << endl;
            cout << "[4] Wydobadz najwiekszy element" << endl;
            cout << "[5] Znajdz najwieszy element" << endl;
            cout << "[6] Zmien priorytet elementu" << endl;
            cout << "[7] Wyswietl" << endl;
            cout << "[0] Wroc do menu" << endl << endl;
            cout << "Wybor: ";
            cin >> number;
            cout << endl;
            switch (number) {
                case 0: {
                    start = false;
                    delete tab;
                    break;
                }
                case 1: {
                    string name = "";
                    cout << "Podaj nazwe pliku: ";
                    cin >> name;
                    cout << "Podaj ilosc danych: ";
                    cin >> number;
                    cout << endl;
                    if (tab->get_size() != 0) {//deleting old structures
                        switch (mode) {
                            case 1: {
                                delete tab;
                                Heap_queue *temp = new Heap_queue;
                                tab = temp;
                                break;

                            }
                            case 2: {
                                
                                //SingleListHead *temp = new SingleListHead;
                                //tab = temp;
                                delete tab;
                                array_queue *temp = new array_queue;
                                tab = temp;
                                break;
                            }
                        }
                    }
                    fstream file;
                    file.open(name, ios::in);//uploading data
                    for (int i = 0; number > i and file.eof() != 1; i++) {
                        string value,prio;
                        getline(file,value,' ');
                        getline(file,prio);
                        tab->insert(stoi(value), stoi(prio));
                    }
                    file.close();
                    cout << endl << "Wczytano" << endl << endl;
                    break;
                }
                case 2: {
                    srand(time(NULL));
                    cout << "Podaj ilość danych: ";
                    cin >> number;
                    if (tab->get_size() != 0) {
                        switch (mode) {//deleting old stucture
                            case 1: {
                                delete tab;
                                Heap_queue *temp = new Heap_queue;
                                tab = temp;
                                break;

                            }
                            case 2: {
                                delete tab;
                                array_queue *temp = new array_queue;
                                tab = temp;
                                break;
                            }
                        }
                    }
                    int max;
                    cout << "Podaj najwieksza mozliwa liczbe: ";
                    cin >> max;
                    for (int i = 0; number > i; i++) tab->insert((rand()%max)+1,(rand()%(5*number))+1);//generating random numbers
                    cout << endl << "Wygenerowano elementy o wartosciach z przedzialu <0,"<< max << "> o priorytetach z przedzialu <0,"<<5*number <<">"<<endl << endl;
                    break;
                }
                case 3: {
                    int temp;
                    cout << "Podaj wartosc do dodania: ";
                    cin >> number;
                    cout << "Podaj priorytet: ";
                    cin >> temp;
                    if (temp < 0) {
                        cout << endl << "Priorytet musi byc dodatni!" << endl << endl;
                        break;
                    }
                    tab->insert(number,temp);
                    cout << endl << "Dodano" << endl << endl;
                    break;
                }
                case 4: {
                    node extract=tab->extract_max();
                    cout<<"Usunieto element o wartosci: "<<extract.value<<" o priorytecie: "<<extract.priority<<endl;
                    break;
                }
                case 5: {
                    node extract=tab->find_max();
                    cout<<"Element o wartosci: "<<extract.value<<" ma najwiekszy prioryt: "<<extract.priority<<endl;
                    break;
                }
                case 6:{
                    int val,prio,new_prio;
                    cout<<"Podaj wartosc elementu: ";
                    cin>>val;
                    cout<<"Podaj aktualny priorytet elementu: ";
                    cin>>prio;
                    cout<<"Podaj nowy priorytet elementu: ";
                    cin>>new_prio;
                    node temp={val,prio};
                    tab->modify_key(temp,new_prio);
                    cout<<"Zmieniono priorytet elementu"<<endl;
                    break;
                }
                case 7: {
                    tab->print();
                    break;
                }
                default: {
                    start = false;
                    break;
                }
            }
        }
    }
}