#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <unistd.h>
using namespace std;

mutex mtx;
condition_variable cond_a, cond_b, cond_c;

void func_a(){
    for(int i = 0; i < 10; i++){
        unique_lock<mutex> lock(mtx);
        cout << "Thread1 : A: " << i << endl;
        
        cond_a.wait(lock);
        cond_b.notify_one();
    }
}

void func_b(){
    sleep(1);
    for(int i = 0; i < 10; i++){
        unique_lock<mutex> lock(mtx);
        cout << "Thread2 : B;" << endl;
        cond_b.wait(lock);
        cond_c.notify_one();
    }
}

void func_c(){
    sleep(2);
    for(int i = 0; i < 10; i++){
        unique_lock<mutex> lock(mtx);
        cout << "Thread3 : C;" << endl;
        cond_a.notify_one();
        cond_c.wait(lock);
    }
}

int main(){
    thread t1(func_a);
    thread t2(func_b);
    thread t3(func_c);

    t1.join();
    t2.join();
    t3.join();

    // cond_a.notify_all();
    // cond_b.notify_all();
    // cond_c.notify_all();

    return 0;
}
