#ifndef MYSTACK_H
#define MYSTACK_H

#define _GLIBCXX_STACK 1
#include <cstddef>
#include <vector>
#include <list>

class Thing{
public:
    int value = -1;

    Thing(){}
};

class MyStackV
{
public:
    void push(Thing& t);
    void pop();

    Thing& peek();

    size_t size() const;
    bool empty() const;

protected:
    std::vector<Thing> data;
};

class MyStackLL
{
public:
    void push(Thing& t);
    void pop();

    Thing& peek();

    size_t size() const;
    bool empty() const;

protected:
    std::list<Thing> data;
};

#endif // MYSTACK_H
