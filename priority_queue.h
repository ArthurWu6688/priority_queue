//
// Created by 93539 on 2023/6/24.
//

#ifndef PRIORITY_QUEUE_PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_PRIORITY_QUEUE_H

#include <vector>

namespace wyp {
    template<class T>
    class less {
    public:
        bool operator()(const T &left, const T &right) {
            return left < right;
        }
    };

    template<class T>
    class greater {
    public:
        bool operator()(const T &left, const T &right) {
            return left > right;
        }
    };

    template<class T, class Container = std::vector<T>, class Compare = less<T>>
    class priority_queue {
    public:
        template<class InputIterator>
        priority_queue(InputIterator first, InputIterator last) {
            _con(first, last);
        }

        priority_queue() {

        }

        bool empty() const {
            return _con.empty();
        }

        std::size_t size() const {
            return _con.size();
        }

        const T &top() const {
            return _con.front();
        }

        ////建大堆
        void adjust_up(std::size_t child) {
            Compare com;
            std::size_t parent = (child - 1) / 2;
            while (child) {
                if (com(_con[parent], _con[child])) {
                    std::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                } else {
                    break;
                }
            }
        }

        void push(const T &value) {
            _con.push_back(value);
            adjust_up(_con.size() - 1);
        }

        ////默认建大堆
        void adjust_down(std::size_t parent) {
            Compare com;
            std::size_t child = parent * 2 + 1;
            while (child < _con.size()) {        //_con[child] < _con[child + 1]
                if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) {
                    ++child;
                }
                if (com(_con[parent], _con[child])) {
                    std::swap(_con[parent], _con[child]);
                    parent = child;
                    child = parent * 2 + 1;
                } else {
                    break;
                }
            }
        }

        void pop() {
            std::swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
//            for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i) {
//                adjust_down(i);
//            }
            adjust_down(0);
        }

    private:
        Container _con;
    };

} // wyp

#endif //PRIORITY_QUEUE_PRIORITY_QUEUE_H
