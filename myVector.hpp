#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
template <typename T>
class MyVec{   
public:
typedef std::unique_ptr<T[]> T_ptr;
MyVec():_size(0), _capacity(0),data(nullptr){}
MyVec(size_t size):_capacity(size*2){
    data = std::make_unique<T[]>(_capacity);
    _size = 0;
}
size_t size(){
    return _size;
}
void push_back(const T& val){
    if(_size >= _capacity){
        resize();
        data[_size] = val;
        _size++;
    }
    else{
        data[_size] = val;
        _size++;
    }
}
//coding
MyVec(const MyVec& vec){
    if (this == &vec) return;
    data(new T[vec._capacity]);
    for(int i =0;i<vec._size;i++){
        data[i] = vec.data[i];
    }
    _capacity = vec._capacity;
    _size = vec._size;
}

T& operator[](int Index){return data[Index];}

void reserve(size_t capacity){
    _capacity = capacity;
    data =  std::make_unique<T[]>(_capacity);
    std::cout<<"resize ... "<<std::endl;
}
//coding
void resize(){
    _capacity *= 2;
    T_ptr newdata(new T[_capacity] ) ;
    for(int i =0;i < _size ;i++){
        newdata[i] = data[i];
    }
    data = std::move(newdata);
    std::this_thread::sleep_for( std::chrono::seconds(2));
    std::cout<<"................resize ........... "<<std::endl;
}
private:
T_ptr data;
size_t _size;
size_t _capacity;

};