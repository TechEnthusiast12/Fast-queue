//  FastQueue.hpp
// Parash Sherpa

#ifndef FastQueue_hpp


// Header file

#define FastQueue_hpp

#include <iostream>
#include <vector>
using namespace std;

// This template class gives the functionality of a fast queue
template<class T>
class FastQueue {
private:
    std::vector<T> container_;  // Using vector as our underlying container object
    int head;     // Index of the top element in the queue
    int tail;     // Index of the bottom of the queue
    int size_ ; // This private member keeps track of the number of elements in the queue
    void Reallocate(); // This helper function deals with reallocation of the container if the size exceeds the capacity
    
public:
    
    FastQueue(); //Constructor
    void enqueue(const T& element); // Adds the element to the end of the queue
    
    void dequeue(); // Removes the element from the top of the queue
    
    const T& front() const; // Returns a reference to the first element of the queue
    
    const T& back() const;   // Returns a reference to the last element of the queue
    
    T& at(size_t index); // Returns a reference to the element at the index provided
    
    int size() const;      // Returns how many elements are in the queue
    
    size_t capacity() const;  // Returns the maximum size of the queue
    
    void shrink_to_fit();   // shrinks the size of the queue to the number of elements in it
    
};
#include "FastQueue.cpp"
#endif /* FastQueue_hpp */

