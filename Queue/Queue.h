#pragma once
#include <iostream>


class Node
{
public:
	int data;
	Node* next;
	Node* prev;
};

class Queue
{
private:
	Node* head;
	Node* tail;
public:
	Queue() : head(nullptr), tail(nullptr) {}
	Queue(int value);
	bool empty() const { return head == nullptr && tail == nullptr; }; //проверка на пустоту
	int front() const { return head->data; }; //обращение к первому элменту
	int back() const { return tail->data; }; //обращение к последнему элементу
	void pop(); //удаление первого элемента
	size_t size();
	void push(int value);
};

