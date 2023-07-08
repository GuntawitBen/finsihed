#include <iostream>
#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
private:
	NodePtr top;
	int size;

public:
	Stack(NodePtr = NULL);
	~Stack();
	char pop();
	void push(char);
	bool isEmpty() const;
	char getTop() const;
	char getData() const;
};

bool Stack::isEmpty() const {
  return (top == NULL);
}

Stack::Stack(NodePtr t) {
	if (t) {
		top = t;
		size = 1;
	}
	else {
		top = NULL;
		size = 0;
	}
}

void Stack::push(char x) {
	NodePtr new_node = new NODE(x);
	if (new_node) {
		new_node->set_next(top);
		top = new_node;
		++size;
	}
	else {
		std::cout << "No memory left for new nodes" << std::endl;
	}
}

char Stack::pop() {
	NodePtr t = top;
	char value;
	if (t) {
		value = t->get_value();
		top = t->get_next();
		delete t;
		--size;
		return value;
	}
	std::cout << "Empty stack" << std::endl;
	return 0;
}

Stack::~Stack() {
	std::cout << "Clearing all stacks" << std::endl;
	NodePtr t = top;
	while (t) {
		top = t->get_next();
		delete t;
		t = top;
	}
}

#endif