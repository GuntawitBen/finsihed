#include <iostream>
#ifndef stack_h
#define  stack_h
#include "node.h"
using namespace std;

class Stack{
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

Stack::Stack(NodePtr t){
  if(t) {
    top=t;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}

void Stack::push(char x){ 
   NodePtr new_node=new NODE(x);
  if(new_node) {
	 	new_node->set_next(top); //2 Connect to the previous top
    top = new_node;          //3
    ++size;                  //4
   }
  else cout << "No memory left for new nodes" << endl;
}


char Stack::pop() {
 	 NodePtr t=top;
	 char value;		
	 if(t) {
     value=t->get_value();
     top=t->get_next();
	   //finished
     delete t;
     --size;
     return value;
     }
	 cout<<"Empty stack"<<endl;
   return 0;
	}

Stack::~Stack() {
  cout<<"Clearing all stacks"<<endl;
  int i;
  NodePtr t=top;
  for(i=0;i<size;i++){
  top = t->get_next();
  delete t;
  t = top;
  }
}

#endif