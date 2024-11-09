#include "stack.h"

void push(Stack* s, unsigned int element)
{
	LinkedList* node = new LinkedList;
	node->element = element;
	node->next = s->head;
	s->head = node;
}

int pop(Stack* s)
{
	if (isEmpty(s)) { return -1; }
	LinkedList* tmp = s->head;
	s->head = s->head->next;
	unsigned int poped_el = tmp->element;
	delete(tmp);
	return poped_el;
}

// put null in main element of stack - head of linked list
void initStack(Stack* s)
{
	s->head = nullptr;
}

// delete all nodes of stack and set head to nullptr
void cleanStack(Stack* s)
{
	LinkedList* tmp = s->head;
	while (s->head != nullptr) {
		tmp = s->head;
		delete(s->head);
		s->head = tmp->next;
	}
	s->head = nullptr;
	delete(tmp);
}

// if stack has no LinkedList head, then its empty
bool isEmpty(Stack* s)
{
	if (s->head == nullptr) { return true; }
	return false;
}

// Stack can never be full
bool isFull(Stack* s)
{
	return false;
}
