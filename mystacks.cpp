#include "mystacks.h"

/**
 * @brief MyStackV::push  Push t to the top of the vector based stack.
 * @param t
 */
void MyStackV::push(Thing &t)
{
    data.push_back(t);

}

/**
 * @brief MyStackV::pop Pop from the top of the vector based stack.
 */
void MyStackV::pop()
{
    data.pop_back();
}

/**
 * @brief MyStackV::peek
 * @return Return a reference to the .backp item in the stack.
 */
Thing &MyStackV::peek()
{
    return data.back();
}

/**
 * @brief MyStackV::size
 * @return Return the number of items stored in the stack.
 */
size_t MyStackV::size() const
{
    return data.size();
}

/**
 * @brief MyStackV::empty
 * @return Return a boolean value indicating whether the stack is empty.
 */
bool MyStackV::empty() const
{
    return data.empty();
}

/**
 * @brief MyStackLL::push Push t to the top of the Doubly Linked List based stack.
 * @param t
 */
void MyStackLL::push(Thing &t)
{
    data.push_back(t);
}

/**
 * @brief MyStackLL::pop Pop from the top of the linked list based stack.
 */
void MyStackLL::pop()
{
    data.pop_back();
}

/**
 * @brief MyStackLL::peek
 * @return Return a reference to the top item in the stack.
 */
Thing &MyStackLL::peek()
{
    return data.back();
}

/**
 * @brief MyStackLL::size
 * @return Return the number of items stored in the stack.
 */
size_t MyStackLL::size() const
{
    return  data.size();
}

/**
 * @brief MyStackLL::empty
 * @return Return a boolean value indicating whether the stack is empty.
 */
bool MyStackLL::empty() const
{
   return data.empty();
}
