#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
 s.push(5);
  s.push(1);
  s.push(7);
  s.push(6);
  s.pop();//6
  s.pop();//7
  s.push(3);
  s.push(4);
 s.pop();//4
  s.pop();//3
  s.pop();//1
    s.pop();//5
    s.pop();
    s.pop();
}