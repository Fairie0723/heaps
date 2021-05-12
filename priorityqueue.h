
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <queue>
#include "card.h"
#include <vector>
#include <string>
#include <iomanip>


//The PriorityQueue class template– This class represents a priority queue implemented using a
// binary heap. It has two type parameters: 1) The type of the element stored in the heap
// (Card in this case); 2) A comparator class type
template<typename Object, typename Comparator>
class PriorityQueue {
private:
std::vector <Object> heapArray;
Comparator compare;
int size = 0;

//heapUp (private, void) – Takes an index parameter and heaps the item up based on its priority.
void heapUp (int index) {
        //parent index
        int parentIndex = (index - 1) / 2;
        if (index == 0 || compare.HighPriority(heapArray[parentIndex], heapArray[index]))
            return;
if (compare.HighPriority(heapArray[index], heapArray[index])) {
    std::swap(heapArray[parentIndex], heapArray[index]);
    heapUp(parentIndex);
}
    }

//heapDown (private, void) – Takes an index parameter and heaps item down based on its priority.
void heapDown(int index) {
        //left child
       int leftIndex = (2 * index )+ 1;
        //right child
       int rightIndex = (2 * index) + 2;

// max heap
        int maxIndex = index;

        if (leftIndex > size){
            return;
        }
        if(compare.HighPriority(heapArray[leftIndex], heapArray[index]))
            maxIndex = leftIndex;

        if(rightIndex < size && (compare.HighPriority(heapArray[rightIndex], heapArray[maxIndex])))
            maxIndex = rightIndex;

        if(maxIndex != index){
            std::swap(heapArray[index], heapArray[maxIndex]);
            heapDown(maxIndex);
        }
    }


public:
//A constructor – Resizes the vector representing the heap to hold 50 items. – Note: This (vector) size
//represents the maximum number of elements in the heap (in this case it is more of an allocated
//capacity value). You will have to maintain a size variable that holds the actual number of elements in
//the heap at any one time, as part of your implementation

    PriorityQueue() {
        heapArray.resize(50);
    }
    //dequeue (void) – Removes the highest priority item. Does not return it.
void dequeue(){
        std::cout << "Dequeuing " << heapArray[0] << "   ";
    //remove last element
    heapArray[0] =  heapArray[size -1];

    //decrement
    size--;

    //heap down
    heapDown(0);
}

//enqueue (void) – Takes one parameter: the item to be enqueued. Enqueues the item and places it in
//the proper heap order.
void enqueue(Object item) {
    heapArray[size] = item;
    size++;

    //heap up
    heapUp(size-1);
}

//print (void) – Displays the items in the heap, from index 0 through number of elements minus 1.
void print() {

            for (int i = 0; i < size; i++) {
                std::cout <<  heapArray[i] << "  ";
            }
}
};
//- There will be two class template comparators each of which takes a type parameter. One of
//the comparators is used to compare if items are less than or equal to (<=),
template<typename Object>
class MinHeap {
public:
    bool HighPriority( const Object &lhs, const Object &rhs) const {
        return lhs <= rhs;
    }
};


//he other to compare if
//they’re greater than or equal to (>=). Each of these classes will have a single, public, bool function that
//returns the result of the above comparisons for two objects of the same type
template<typename Object>
class MaxHeap {
public:
    bool HighPriority( const Object &lhs, const Object &rhs) const  {
        return lhs >= rhs;
    }
};


#endif
