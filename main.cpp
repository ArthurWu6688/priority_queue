#include <iostream>
#include "priority_queue.h"

void test_priority_queue1(){
    wyp::priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(8);
    pq.push(2);

    while(!pq.empty()){
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    test_priority_queue1();

    return 0;
}