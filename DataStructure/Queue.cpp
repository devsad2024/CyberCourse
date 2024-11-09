#include "queue.h"
#include <iostream>

// initialize array with inputed size and put it in queue struct
void initQueue(Queue* q, unsigned int size) {
	q->queue = new unsigned int[size];
	q->size = size;
}

// deletes array and resets pointer in queue Struct
void cleanQueue(Queue* q) {
	delete[] q->queue;
	q->queue = new unsigned int[q->size];
	q->people_in_queue = 0;
}

// adds to array of struct of the queue newValue at the index 0
void enqueue(Queue* q, unsigned int newValue) {
	// checks if it can add more people in queue
	if (isFull(q)) {
		std::cout << "Queue is already full\n";
	}
	else {
		// setting new value
		q->queue[q->people_in_queue] = newValue;
		// incrementing people amount
		q->people_in_queue++;
	}
}

// deletes first item of the queue array of struct and returns the new first item or -1 if array is empty
int dequeue(Queue* q) {
	if (isEmpty(q)) {
		std::cout << "The queue is empty";
		return -1;
	}
	else {
		int poped = q->queue[0];
		// move elements one step backward
		for (size_t i = 0; i < q->people_in_queue - 1; i++)
		{
			q->queue[i] = q->queue[i + 1];
		}
		// decrementing size and clearing copy arr
		q->people_in_queue--;
		// returning the 1st element
		return poped;
	}

}

// checks if people amount in queue is 0
bool isEmpty(Queue* s) {
	return (s->people_in_queue == 0) ? true : false;
}

 // checks if people in queue are the same as size of queue
bool isFull(Queue* s) {
	return (s->people_in_queue == s->size) ? true : false;
}

