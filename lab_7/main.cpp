#include <iostream>
#include "quetype.h"
#include "quetype.cpp"

using namespace std;

template <class t>
void isEmpty(QueType<t> a);
template <class t>
void isFull(QueType<t> a);
template <class t>
void enQueue(QueType<t> &a, t Item);
template <class t>
void print(QueType<t> &a);
template <class t>
void deQueue(QueType<t> &a, t Item);


int count;

int main()
{
    QueType<int> a(5);
    isEmpty(a);
    enQueue(a,5);
    enQueue(a,7);
    enQueue(a,2);
    enQueue(a,4);
    isEmpty(a);
    isFull(a);
    enQueue(a,6);
    print(a);

    isFull(a);
    enQueue(a,8);
    int item;
    deQueue(a,item);
    deQueue(a,item);
    print(a);
    deQueue(a,item);
    deQueue(a,item);
    deQueue(a,item);

    print(a);
    deQueue(a, item);


    int usr_input;
    cin >> usr_input;
    QueType<string> b(usr_input + 1);

    b.Enqueue("1");

    while(!b.IsFull()){

    string item_s;
        b.Dequeue(item_s);

        cout << item_s << "\n";
        string c = item_s + "0";
        string d = item_s + "1";

        b.Enqueue(c);
        b.Enqueue(d);


    }











}
template <class t>
void isEmpty(QueType<t> a){
    if(a.IsEmpty() == true){
        cout<< "Queue is Empty" << "\n";
    }
    else{
        cout<< "Queue is not Empty" << "\n";
    }
}

template <class t>
void isFull(QueType<t> a){
    if(a.IsFull() == true){
        cout<< "Queue is Full" << "\n";
    }
    else{
        cout<< "Queue is not Full" << "\n";
    }
}
template <class t>
void enQueue(QueType<t> &a, t Item){
    try{
        a.Enqueue(Item);
        count++;
    }
    catch( FullQueue e){
        cout << "Queue Overflow" << "\n";
    }

}

template <class t>
void deQueue(QueType<t> &a, t Item){
    try{
        a.Dequeue(Item);
        count--;
    }
    catch( EmptyQueue e){
        cout << "Queue Underflow" << "\n";
    }

}

template <class t>
void print(QueType<t> &a){

    int count_fn = count;
    t arr[count_fn];

    for(int i = 0; i < count_fn; i++){
        a.Dequeue(arr[i]);
        count--;

    }

    for(int i = 0; i < count_fn; i++ ){
        cout << arr[i] << "\t";
    }

    cout << "\n";

    for(int i = 0; i < count_fn; i++){
        enQueue(a, arr[i]);
    }
}
