#include <iostream>
#include <cstring>
#include "stack.h"

int main(int argc, char* argv[]) {
  int j;
  for (j = 1; j < argc; j++) {
    Stack s;
    int i;
    int match = 1;  // Start with matched parentheses
    int openCount = 0;
    int closeCount = 0;
    for (i = 0; i < strlen(argv[j]); i++) {
      switch (argv[j][i]) {
        case '[':
        case '{':
          s.push(argv[j][i]);
          openCount++;
          break;
        case ']':
          closeCount++;
          if (s.isEmpty() || s.pop() != '[')
            match = 0;
          break;
        case '}':
          closeCount++;
          if (s.isEmpty() || s.pop() != '{')
            match = 0;
          break;
      }
    }

    if (!s.isEmpty() || openCount > closeCount) {
      std::cout << "Too many open parentheses" << std::endl;
    }
    else if (closeCount > openCount) {
      std::cout << "Too many close parentheses" << std::endl;
    }
    else if (match == 0) {
      std::cout << "Parentheses did not match" << std::endl;
    }
    else {
      std::cout << "Parentheses matched" << std::endl;
    }
  }
  return 0;
}






/*
  for (i=1; i<argc; i++){
    if (argv[i][0] == 'x'){
      s.pop();
    }
    else {
      s.push(atoi(argv[i]));
    }
  }
*/