#include <iostream>
#include "stacktype.h"
#include "stacktype.cpp"

using namespace std;

template <class ItemType>
struct Stack{
    StackType<ItemType> Stack;
    int count;
 };
 
 Stack <int>heights;
 Stack <int>res_heights;
 Stack <int>position;

template <class ItemType>
void pushToStack(Stack<ItemType> &Stack, ItemType Item);
template <class ItemType>
int popFromStack(Stack<ItemType> &Stack);
template <class ItemType>
void print_Stack(Stack<ItemType> &Stack);
template <class ItemType>
void deleteBottomItem(Stack<ItemType> &Stack);
template <class ItemType>
void calculate_area(Stack<ItemType> &_Stack, Stack<ItemType> &res_heights, Stack<ItemType> &position);


int main(){
    int stack_size;
    cin >> stack_size;

    for(int i = 0; i < stack_size; i++){
        int item;
        cin >> item;
        pushToStack(heights, item);
    }

    print_Stack(heights);
    calculate_area(heights, res_heights, position);
}

template <class ItemType>
void pushToStack(Stack<ItemType> &Stack, ItemType Item){
    try{
        Stack.Stack.Push(Item);
        Stack.count++;
    }catch(FullStack e){
        cout << "Stack Overflow" << "\n";
    }
}

template <class ItemType>
int popFromStack(Stack<ItemType> &Stack){
    try{
        ItemType temp = Stack.Stack.Top();
        Stack.Stack.Pop();
        Stack.count--;
        return temp;
    }catch(EmptyStack e){
        cout << "Stack Underflow" << "\n";
    }
}

template <class ItemType>
void print_Stack(Stack<ItemType> &Stack){
    int count_func = Stack.count;
    ItemType arr[count_func];

    for(int i = 0; i < count_func; i++){
        arr[i] = popFromStack(Stack);
    }

    for(int i = 0; i < count_func; i++ ){
        cout << arr[i] << " ";
    }cout << "\n";

    for(int i = count_func - 1; i >= 0 ; i--){
        pushToStack(Stack, arr[i]);
    }

}

template <class ItemType>
void deleteBottomItem(Stack<ItemType> &Stack){
    int count_func = Stack.count;
    ItemType arr[count_func];

    for(int i = 0; i < count_func; i++){
        arr[i] = popFromStack(Stack);
    }

    for(int i = count_func - 1; i > 0 ; i--){
    pushToStack(Stack, arr[i]);
    }

}

//https://www.youtube.com/watch?v=VNbkzsnllsU
template <class ItemType>
void calculate_area(Stack<ItemType> &_Stack, Stack<ItemType> &res_heights, Stack<ItemType> &position){
    cout << _Stack.Stack.Top();
    int bar, temp_height, area, limit_count;
    cout << bar;
    while(bar < 5){
        limit_count = 0;
        if(res_heights.Stack.IsEmpty() || _Stack.Stack.Top() > temp_height){
            temp_height = _Stack.Stack.Top();
            pushToStack(position, _Stack.count);
            pushToStack(res_heights, temp_height);
            bar++;
            cout << bar;
        }else{
            area = res_heights.Stack.Top() * (bar - limit_count);
        }
    }
    cout <<  area;

}

