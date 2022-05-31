#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
	using node_pointer = Node<T>*;
	T data;
	node_pointer next{ nullptr };
	node_pointer prev{ nullptr };
};

template <typename T>
class List
{
protected:
	using node_pointer = Node<T>*;
	
	node_pointer head;
	node_pointer tail;
	int size;

public:
	List() : head(nullptr), tail(nullptr), size(0) {};
	//~List();
	bool add(T* data);
	void printList();
};

template <typename T>
bool List<T>::add(T* data) {
	node_pointer new_node = new Node<T>;
	new_node->data = *data;
	new_node->next = nullptr;

	if (head == nullptr) {
		head = tail = new_node;
		new_node->prev = nullptr;
	}
	else {
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}

	++size;

	return true;
}

template <typename T>
void List<T>::printList() {
	node_pointer current = new Node<T>;
	current = head;

	while (current != nullptr) {
		cout << current->data << '\n';
		current = current->next;
	}
}

/*template <typename T>
List<T>::~List() {
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* temp = current->next;
		delete current;
		current = temp;
	}
}
*/