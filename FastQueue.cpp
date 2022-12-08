//
//  FastQueue.cpp

// Constructor
#include "FastQueue.hpp"
template<class T>
FastQueue<T>:: FastQueue(){
    container_.reserve(4);    // Reserving a size of 4 for the initial vector
    head = -1;
    tail = -1;
    size_ = 0;
}

// This private helper function deals with realloaction of the vector if the number of elements exceeds maximum capacity
template<class T>
void FastQueue<T>:: Reallocate() {
    vector<T> larger_vec;   // Temporary vector that has double the size of our container
    larger_vec.reserve(2*capacity());
    for (int i = 0; i<size_; i++) {
        larger_vec[i] = container_[(head + i)%capacity()];
    }
      container_.resize(2*capacity());
    for(int i = 0; i<size_; i++){
        container_[i] = larger_vec[i];
    }
}

// Enqueues the elements in the back of the fastqueue
template<class T>
void FastQueue<T>:: enqueue(const T& element){
    // If the size exceeds capacity then realloacate
    if((tail+1)%capacity() == head){
        Reallocate();
        head = 0;    // Set head to index 0
        tail = (size_-1) % capacity(); // Set tail to index size-1
        container_[(tail+1)%capacity()] = element;   // enqueue the element at the back
        tail = (tail + 1) % capacity();   // Increment tail
        size_++;     // Increment size of the queue
    }
    else{
        if(head == -1){
            head = 0;
        }
        container_[(tail+1)%capacity()] = element;
        tail = (tail +1) % capacity();
        size_++;
    }
}

// Removes the element from the top of the queue
template<class T>
void FastQueue<T>:: dequeue(){
    // Does nothing if size is 0
    if(size_ == 0){
        return;
    }
    else{
        head = (head+1)%capacity();
        size_--;
    }
}

// Returns the number of elements currently in the queue
template<class T>
int FastQueue<T>:: size() const{
    return size_;
}

// Returns the capacity of the queue
template<class T>
size_t FastQueue<T>::capacity() const {
    return container_.capacity();
}

// Returns the reference to the top element in the queue
template<class T>
const T& FastQueue<T>:: front() const{
    if(size_ == 0){
        throw std::out_of_range("Container Empty");
    }
    return container_[head];
}

// Returns a reference to the bottom of the queue
template<class T>
const T & FastQueue<T>:: back() const{
    if(size_ == 0){
        throw std::out_of_range("Container Empty");
    }
    return container_[tail];
}

// Returns the element at the index provided
template <class T>
T& FastQueue<T>:: at(size_t index){
    if(index >= size_){
        throw std:: out_of_range("Access to element not in range");
    }
    return container_[(head + index)%capacity()];
}

// Shrinks the capacity of the queue to match the number of elements in it
template<class T>
void FastQueue<T>:: shrink_to_fit(){
    if(capacity() > size_){
        vector<T>shrinked_vec;
        shrinked_vec.reserve(size_);
        for(int i = 0; i<size_; i++){
            shrinked_vec[i] = container_[(head + i)%capacity()];
        }
        container_.swap(shrinked_vec);
        head = 0;
        tail = size_-1;
    }
}

