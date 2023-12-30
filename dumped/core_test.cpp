#include <iostream>
#include "blockqueue.h"
#include"SharedPtr.h"
using namespace std;

int main(){
    // BlockQueue bl(12);
    // BlockQueue bw;
    // unique_ptr<BlockQueue> bq_uni(new BlockQueue(22));
    // auto bq_uni2(std::make_unique<BlockQueue>(42));
    // BlockQueue * bq = new BlockQueue(32);

    // int * bq1 = NULL;
    // *bq1 = 0;

    // vector<int> res(5);
    // cout << res.at(100) << endl;
    // cout << res.capacity() << " "<<res.size() << endl;

    SharedPtr<int> shared = new SharedPtr<int>();

    return 0;
}