#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
template <class T>
class CircularArray
{
protected:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    T inicio(){
        return array[front];
    }
    T final(){
        return array[back];
    }
    void push_front(T data){
        if(is_empty()){
            front= back = 0;
            array[front]=data;
        }
        else if(is_full()){
            cout << "No se pueden insertar mas elementos";
        }
        else{
            int x=back+1;
            while (x!= front){
                if(x==capacity) {
                    x = 0;
                    array[0] = array[capacity-1];
                }
                else
                    array[x] = array[x-1];
                x = prev(x);
            }
            array[front] = data;
            back = next(back);
        }

    };
    void push_back(T data){
        if(is_full()){
            cout << "No se pueden insertar mas elementos";
        }
        else if(is_empty()){
            front= back = 0;
            array[back] = data;
        }
        else{
            if (back == capacity - 1)
                back = 0;
            else
                back++;
            array[back] = data;
        }
    };
    void insert(T data, int pos){
        if(is_empty()){
            front = back = pos;
        }
        else if(is_full()){
            cout << "Esta lleno";
        }
        else if(pos ==back){
            array[next(back)] = array[back];
            array[back] = data;
            back++;
        }
        else{
            int x=back+1;
            while (x!= pos){
                if(x==capacity) {
                    x = 0;
                    array[0] = array[capacity-1];
                }
                else
                    array[x] = array[x-1];
                x = prev(x);
            }
            array[front] = data;
            back = next(back);

        }
        array[pos] = data;

    };
    T pop_front(){
        array[front] = -1;
        if(front == back) {
            front = -1;
            back = -1;
        }
        if(front == capacity - 1)
            front =0;
        else
            front++;
    };
    T pop_back(){
        array[back] = -1;
        back = prev(back);
    };
    bool is_full(){
        return next(back) == front;
    };

    virtual bool is_empty(){
        return (front == -1);
    };
    int size(){
        if(is_empty())
            return 0;
        else if(front == back)
            return 1;
        else if(back>front){
            return 1+back-front;
        }
        else{
            return capacity-(front-back-1);
        }
    };
    void clear(){
        int x= front;
        for(int q=0;q<size();q++){
            array[x] = -1;
            x = next(x);
        }
        front = -1;
        back = -1;
    };
    T &operator[](int pos){
        return array[pos];
    };
    void sort(){
        bucketSort();
    }
    void bucketSort()
    {
        vector<int>* b = new vector<int>[size()];
        int x = front;
        for (int i = 0; i <size(); i++) {
            int bi = array[x] / 10;
            b[bi].push_back(array[x]);
            x = next(x);
        }
        for (int i = 0; i < size(); i++)
            std::sort(b[i].begin(), b[i].end());
        int index = front;
        for (int i = 0; i < size(); i++)
            for (int j = 0; j < b[i].size(); j++){
                array[index] = b[i][j];
                index = next(index);
            }
    }
    bool is_sorted(){
        bool veracidad = true;
        int x = front;
        while (x!=back){
            if(array[x] > array[x+1]){
                return false;
            }
            x = next(x);
        }
        return veracidad;
    };
    void reverse(){
        int inicio= front,final = back;
        for(int q=0;q<size()/2;q++){
            swap(array[inicio],array[final]);
            inicio = next(inicio);
            final = prev(final);
        }/*
        inicio = front;
        for(int q=0;q<capacity;q++){
            cout << n_array[inicio] << ' ';
            if(inicio+1==capacity)
                inicio=0;
            else inicio++;
        }
        cout << endl;
        delete[] n_array;*/
    };
    string to_string(string sep=" ");



protected:
    int next(int);
    int prev(int);
};




template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    int q = front;
    string result = "";
    for (int i = 0; i < size(); i++){
        result += std::to_string(array[q]) + sep;
        q = next(q);
    }
    return result;
}






