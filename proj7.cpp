
#include <iostream>
#include <fstream>
#include <algorithm>
#include "card.h"
#include "priorityqueue.h"

bool empty();
int main() {
    int randSeed;
//Must read a file named pqseed.txt which contains a single integer
    std::ifstream inFile("pqseed.txt");
    inFile >> randSeed;

//Instantiates both a min priority queue and a max priority queue, using the PriorityQueue template
//PriorityQueue <card, compare> myMaxQueue
PriorityQueue <Card, MaxHeap<Card>> maxQueue;
PriorityQueue <Card, MinHeap<Card>> minQueue;

//Instantiates two arrays of 13 Card objects each.
Card cardSpades[13];
Card cardHearts[13];

//One array will have the 13 cards of the Spades suit,
//the other will have 13 Hearts cards
//Each of these is a standard C++ array

    for (int i = 0; i < 13 ; i++) {
        cardSpades[i] = Card(i+ 1, spades);
    }

    for (int i = 0; i < 13 ; i++) {
        cardHearts[i] = Card(i+ 1, hearts);
    }

    srand(randSeed);
//Each card array must be shuffled
    std::random_shuffle(std::begin(cardSpades), std::end(cardSpades));

    std::random_shuffle(std::begin(cardHearts), std::end(cardHearts));


//Enqueues the 13 Spades cards (in order, from array index 0 through12) into the max priority queue,
//displaying the heap’s contents after each enqueue
    for (int i = 0; i < 13; i++) {
        std::cout << "Enqueued " << cardSpades[i] << "  ";
        maxQueue.enqueue(cardSpades[i]);
        maxQueue.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;


//Dequeues each card individually from the max priority queue until it is empty - displays the heap’s contents
//after each dequeue
    for (int i = 0; i < 13; i++) {
        maxQueue.dequeue();
        maxQueue.print();
        std::cout << std::endl;
    }
    std::cout << "Max Heap is empty.\n";
    std::cout << std::endl;

//Enqueues the 13 Hearts cards (in order, from array index 0 through12) into the min priority queue,
//displaying the heap’s contents after each enqueue
    for (int i = 0; i < 13; i++) {
        std::cout << "Enqueued " << cardHearts[i] << "   ";
        minQueue.enqueue(cardHearts[i]);
        minQueue.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

//Dequeues each card individually from the min priority queue until it is empty - displays the heap’s contents
//after each dequeue
    for (int i = 0; i < 13; i++) {
        minQueue.dequeue();
        minQueue.print();
        std::cout << std::endl;
    }
    std::cout << "Min Heap is empty.\n";
inFile.close();
return 0;
}





