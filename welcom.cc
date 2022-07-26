#include <iostream>
#include "myVector.hpp"
#include <vector>
void proc(){
    MyVec<int > vec(4);
    vec.reserve(6);
    std::cout<<vec.size()<<std::endl;
    vec.push_back(1);
    vec.push_back(2);
    for(int i = 0;i<10000000;i++){
        vec.push_back(i);
    }
    std::cout<<std::endl;
    auto p = new int[100000000];
    *p = 1000;
    int* mp = (int*)malloc(10);
    //std::this_thread::sleep_for( std::chrono::seconds(1));
    return;
}
void pro2(){
    std::vector<int> vec;
    vec.reserve(5);
    for(int i = 0;i<100;i++){
        vec.push_back(i);
    }
    std::this_thread::sleep_for( std::chrono::seconds(2));
    return;
}

void newtest()
{
	int *p = new int[10]; //申请40字节
	return;
}

void malloctest()
{
	int *q = (int*)malloc(10); //申请10字节
	return;
}
int main(){
    malloctest();
    newtest();
    int  i=0;
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
