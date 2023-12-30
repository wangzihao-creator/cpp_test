#ifndef BLOCKQUEUE_H_
#define BLOCKQUEUE_H_

#include<queue>
#include<mutex>
#include<condition_variable>
using namespace std;

template<class T>
class BlockQueue{
public:
    explicit BlockQueue(size_t MaxCapicity = 1000);
    ~BlockQueue();

    const size_t size();
    const size_t capcity();

    void push(const T & item); 
    bool pop(T & item);

private:
    std::queue<T> queue_;
    const size_t capicity_;
    std::mutex mtx_;
    bool is_closed;
    condition_variable cond_pro, cond_cos;
};

template<class T>
BlockQueue<T>::BlockQueue(size_t MaxCapicity) : capicity_(MaxCapicity){
    assert(MaxCapicity > 0);
    lock_guard<mutex> locker(mtx_);
    is_closed = false;
}

template<T>
BlockQueue<T>::~BlockQueue(){
    {
        std::lock_guard<std::mutex> locker(mtx_);
        is_closed = true;
        queue_.clear();
    }
    cond_pro.notify_all();
    cond_cos.notify_all();
}

template<T>
const size_t BlockQueue<T>::size(){
    lock_guard<mutex> locker(mtx_);
    return queue_.size();
}

template<T>
const size_t BlockQueue<T>::capicity(){
    lock_guard<mutex> locker(mtx_);
    return capicity_;
}

template<T>
void BlockQueue<T>::push(const T & item){
    unique_lock<mutex> locker(mtx_);
    while(queue_.size() > capicity_){
        cond_pro.wait(locker);
    }
    queue_.push(item);
    cond_cos.notify_one();
}

template<T>
bool Blockqueue<T>::pop(T & item){
    unique_lock<mutex> locker(mtx_);
    while(queue_.size() == 0){
        cond_cos.wait(locker);
        if(is_closed) return false;
    }
    item = queue_.front();
    queue_.pop();
    cond_pro.notify_one();
    return ture;
}

#endif