#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<unistd.h>
using namespace std;

// std::mutex mtx;
// condition_variable cond;
// bool state = 1;
// int num = 1;

// void func(int index, bool stateNeed){
//     while(1){
//         unique_lock<mutex> locker(mtx);
//         cout << "thread " << index << ", num is : " << num++ << endl ;
//         state = !state;
//         cond.notify_one();
//         cond.wait(locker, [stateNeed](){return state == stateNeed;});
//         sleep(1);
//     }
// }

// int main(){
//     thread t1(func, 1, true);
//     thread t2(func, 2, false);

//     t1.join();
//     t2.join();

//     return 0;
// }


std::mutex mtx;
condition_variable cond1, cond2;
int num = 1;

void func_odd(){
    for(int i = 0; i < 50; i++){
        unique_lock<mutex> locker(mtx);
        cout << "thread1 : "  << num++ << endl;
        cond1.wait(locker);
        cond2.notify_one();
    }
} 

void func_even(){
    sleep(1);
    for(int i = 0; i < 50; i++){    
        unique_lock<mutex> locker(mtx);
        cout << "thread2 : "  << num++ << endl;
        cond1.notify_one();
        cond2.wait(locker);
    }
} 

int main(){
    thread t1(func_odd);
    thread t2(func_even);

    t1.join();
    t2.join();

    return 0;
}