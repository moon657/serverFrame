#include <iostream>
#include "myVector.hpp"
#include <chrono>
#include <thread>
void proc(){
    MyVec<int > vec(4);
    vec.reserve(5);
    std::cout<<vec.size()<<std::endl;
    vec.push_back(1);
    vec.push_back(2);
    for(int i = 0;i<8;i++){
        vec.push_back(i);
    }
    for(int i = 0;i<vec.size();i++){
        std::cout<<vec[i]<<' ';
    }
    auto p = new int[10];
    std::this_thread::sleep_for( std::chrono::seconds(5));


    return;
}

int main(){
    while (true){
        proc();
    }
    std::cout<<"   _____ __               __                  __"<<std::endl;
    std::cout<<"  / ___// /_  ___  ____  / /_  ___  _________/ /"<<std::endl;
    std::cout<<"  \\__ \\/ __ \\/ _ \\/ __ \\/ __ \\/ _ \\/ ___/ __  / "<<std::endl;
    std::cout<<" ___/ / / / /  __/ /_/ / / / /  __/ /  / /_/ /  "<<std::endl;
    std::cout<<"/____/_/ /_/\\___/ .___/_/ /_/\\___/_/   \\__,_/"<<std::endl;
    std::cout<<"               /_/                              "<<std::endl;

    std::cout<<"   Yantai 仌"<<std::endl;
    std::cout<<" _____   _____ "<<std::endl;
    std::cout<<"| ____| | ____|"<<std::endl;
    std::cout<<"|  _|   |  _|  "<<std::endl;
    std::cout<<"| |___  | |___ "<<std::endl;
    std::cout<<"|_____| |_____|"<<std::endl;

    return 0;
}