template<typename T>
class SharedPtr
{
private:
    T * ptr_;
    int * count_;
public:
    SharedPtr(T * ptr = NULL) : ptr_(ptr), count_(new int(1)){}
    
    SharedPtr(const SharedPtr& s) : ptr_(s.ptr_), count_(s.count_){
        (*count_)++;
    }
    
    SharedPtr<T> & operator=(const SharedPtr& s){
        if(this != &s){
            if(--(*(this->count_)) == 0){
                delete this->ptr_;
                delete this->count_;
            }
            ptr_ = s.ptr_;
            count_ = s.count_;
            (*count_)++;
        }
        return *this;
    }

    T* operator->(){
        return this->ptr_;
    }

    ~SharedPtr(){
        --(*(this->count_));
        if(*(this->count_) == 0){
            delete ptr_;
            ptr_ = NULL;
            delete count_;
            count_ = NULL;
        }
    }
};
