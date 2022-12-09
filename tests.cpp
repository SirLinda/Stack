#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mystacks.h"

#include <deque>
#include <iostream>
#include <type_traits>
#include <cstddef>

using namespace std;

//#ifdef _WIN32
//int main(int argc, char* argv[])
//{
//    int result = Catch::Session().run(argc, argv);
//    return result;
//}
//#endif

template<class T>
class TestStack : protected T{
protected:
    using T::data;
    decltype(data)& stack_data = data;
    T other;
};

TEMPLATE_TEST_CASE_METHOD(TestStack,"Testing Push", "[0]", MyStackV, MyStackLL) {
    auto& data = this->stack_data;
    GIVEN("A new stack."){
        THEN("Calling push multiple times should add to data."){
            UNSCOPED_INFO("data should be empty");
            REQUIRE(data.empty());
            for(int i = 0; i < 4; ++i){
                Thing t; t.value = i;
                size_t n = static_cast<size_t>(i) +1;

                this->push(t);
                UNSCOPED_INFO("Calling push(1...4) should store items in data.");
                REQUIRE(data.size() == n);
            }
        }
        THEN("Calling push multiple times should add to this object's data even if there are multiple stacks in memory."){
            UNSCOPED_INFO("data should be empty");
            REQUIRE(data.empty());
            for(int i = 0; i < 4; ++i){
                Thing t; t.value = i;
                size_t n = static_cast<size_t>(i)+1;

                this->push(t);
                if(i % 2 == 0) this->other.push(t);
                UNSCOPED_INFO("Calling push(1...4) should store items in data.");
                REQUIRE(data.size() == n);
            }
        }
    }
}

TEMPLATE_TEST_CASE_METHOD(TestStack,"Testing Pop", "[1]", MyStackV, MyStackLL) {
    auto& data = this->stack_data;
    GIVEN("A stack with n items in it already."){
        THEN("Calling pop should remove from data."){
            size_t n = rand() % 10 + 10;
            for(size_t i = 0; i < n; ++i){
                Thing t; t.value = i;
                data.push_back(t);
            }

            UNSCOPED_INFO("data should have n items");
            REQUIRE(data.size() == n);

            for(size_t i = 1; i <= n; ++i){
                Thing t; t.value = i;

                this->pop();
                UNSCOPED_INFO("Calling pop() should remove items from data.");
                REQUIRE(data.size() == n-i);
            }
        }
    }
}

TEMPLATE_TEST_CASE_METHOD(TestStack,"Testing Peek", "[2]", MyStackV, MyStackLL) {
    GIVEN("An empty stack."){
        THEN("Push n items."){
            size_t n = rand() % 10 + 10;

            for(size_t i = 0; i < n; ++i){
                Thing t; t.value = i;
                this->push(t);

                UNSCOPED_INFO("After a push, peek should return the most recent item.");
                REQUIRE(this->peek().value == t.value);
            }
        }
    }
    GIVEN("A stack with n items."){
        THEN("Push n items and then pop them."){
            size_t n = rand() % 10 + 10;
            for(size_t i = 0; i < n; ++i){
                Thing t; t.value = i;
                this->push(t);
            }
            for(size_t i = 1; i < n; ++i){
                UNSCOPED_INFO("After a pop, peek should return the most recent item.");
                int value = n-1 - i;
                this->pop();
                REQUIRE(this->peek().value == value);
            }
        }
    }
    GIVEN("An empty stack."){
        WHEN("Pushing and popping randomly."){
            THEN("Peek should always return the right value"){
                size_t n = rand() % 10 + 10;
                std::deque<Thing> dat;
                for(size_t i = 0; i < 10; ++i){
                    Thing t; t.value = rand() % 100;
                    this->push(t);
                    dat.push_back(t);
                }
                for(size_t i = 0; i < n; ++i){
                    int value = dat.back().value;
                    UNSCOPED_INFO("Peek should give the right value.");
                    REQUIRE(this->peek().value == value);
                    if(rand() % 2 == 0 && !dat.empty()){
                        UNSCOPED_INFO("After popping, peek should still give the right value.");
                        this->pop();
                        dat.pop_back();
                        value = dat.back().value;
                        REQUIRE(this->peek().value == value);
                    }else{
                        UNSCOPED_INFO("After pushing, peek should still give the right value.");
                        Thing t; t.value = rand() % 20;
                        this->push(t);
                        dat.push_back(t);
                        value = dat.back().value;
                        REQUIRE(this->peek().value == value);
                    }
                }
            }
        }
    }
}

TEMPLATE_TEST_CASE_METHOD(TestStack,"Testing Size & Empty", "[3]", MyStackV, MyStackLL) {
    GIVEN("An empty stack."){
        THEN("Empty & Size should be correct."){
            UNSCOPED_INFO("Empty should be true.");
            REQUIRE(this->empty());
            UNSCOPED_INFO("Size should be 0.");
            REQUIRE(this->size() == 0);
        }
        THEN("Push n items."){
            size_t n = rand() % 10 + 10;
            for(size_t i = 1; i <= n; ++i){
                Thing t; t.value = i*10;
                this->push(t);
                UNSCOPED_INFO("Empty should be false.");
                REQUIRE_FALSE(this->empty());
                UNSCOPED_INFO("Size should be the number of items pushed so far.");
                REQUIRE(this->size() == i);
            }


        }
    }
}
