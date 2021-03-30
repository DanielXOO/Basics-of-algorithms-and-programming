#include "Queue.h"

Queue::Queue(int value) : head(nullptr), tail(nullptr)
{
	push(value);
}

void Queue::pop()
{
	head = head->prev;

}

void Queue::push(int value)
{
	Node* tmp = new Node;
	tmp->data = value;
	tmp->next = tail;
	tmp->prev = head;
	if (empty()) head = tmp;
	tail = tmp;
	head->prev = tail;
}

