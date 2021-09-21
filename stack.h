#include "circulararray.h"

template<typename T>
class Stack: public CircularArray<T>{
public:
    Stack(int _capacity): CircularArray<T>(_capacity){
        this->back = this->front = -1;
    };
    void push(int data){
        if(CircularArray<T>::is_empty()){
            this->back = this->front = 0;
            this->array[this->front] = data;
        }
        else if(CircularArray<T>::is_full()){
            cout<< "Esta lleno";
        }
        else{
            this->back = CircularArray<T>::next(this->back);
            this->array[this->back] = data;
        }
    }
    int pop(){
        if(CircularArray<T>::is_empty()){
            cout << "Esta vacio";
        }
        else if(this->back == this->front){
            this->array[this->back] = -1;
            this->back = this->front = -1;
        } else{
            this->array[this->back] = -1;
            this->back = CircularArray<T>::prev(this->back);
        }
    }
    string display(){
        auto res = CircularArray<T>::to_string();
        return res;
    }
};