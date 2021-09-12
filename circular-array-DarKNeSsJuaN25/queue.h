#include "circulararray.h"

template <typename T>
class Queue : public CircularArray<T>{
public:
    Queue(int _capacity): CircularArray<T>(_capacity){
    }
    void enqueue(int data){
        if(CircularArray<T>::is_empty()){
            this->array[0] = data;
            this->front = this->back = 0;
        }
        else if(CircularArray<T>::is_full())
            cout << "Array lleno";
        else if(this->back == this->capacity -1 && this->front !=0){
            this->back = 0;
            this->array[this->back] = data;
        }
        else{
            this->back = CircularArray<T>::next(this->back);
            this->array[this->back] = data;
        }
    };
    int dequeue(){
        this->array[this->front] = -1;
        if(this->front == -1)
            cout << "Array vacio";
        else if(this->front == this->back){
            this->front = this->back = -1;
        }
        else if(this->front == this->capacity-1 ){
            this->front = 0;
        }
        else{
            this->front =  CircularArray<T>::next(this->front);
        }
    };
    string display(){
        auto res = CircularArray<T>::to_string();
        return res;
    }
};

