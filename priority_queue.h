//
// Created by 吴映鹏 on 2023/6/12.
//

#ifndef PRIORITY_QUEUE_PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_PRIORITY_QUEUE_H

#include <vector>

namespace wyp {
    template<class T>
    class less {
    public:
        bool operator()(const T &left, const T &right) const {
            return left < right;
        }
    };

    template<class T>
    class greater {
    public:
        bool operator()(const T &left, const T &right) const {
            return left > right;
        }
    };

    template<class T, class Container = std::vector<T>, class Compare = less<T>>
    class priority_queue {
    public:
        priority_queue() {

        }

        template<class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
                : _con(first, last) {
            ////建堆
            for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i) {
                adjust_down(i);
            }
        }

        void adjust_up(size_t child) {
            Compare com;
            size_t parent = (child - 1) / 2;
            while (child > 0) {
                if (com(_con[parent], _con[child])) {
                    std::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                } else {
                    break;
                }
            }
        }

        void push(const T &x) {
            _con.push_back(x);
            adjust_up(_con.size() - 1);
        }

        void adjust_down(size_t parent) {
            Compare com;
            size_t child = parent * 2 + 1;
            while (child < _con.size()) {
                if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) {
                    ++child;
                }
                if (com(_con[parent], _con[child])) {
                    std::swap(_con[child], _con[parent]);
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
            adjust_down(0);
        }

        const T &top() const {
            return _con[0];
        }

        bool empty() const {
            return _con.empty();
        }

        size_t size() const {
            return _con.size();
        }

    private:
        Container _con;
    };

} // wyp

#endif //PRIORITY_QUEUE_PRIORITY_QUEUE_H