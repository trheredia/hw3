#include <iostream>
#include "stack.h"

int main(){
  Stack<int> testStack;

  if(testStack.empty()){
    std::cout << "empty ʕ •ᴥ•ʔ" << std::endl;
  }
  else {
    std::cout << "not empty!!!" << std::endl;
  }

  std::cout << "size: " << testStack.size() << std::endl;

  std::cout << "testing push" << std::endl;
  testStack.push(1);
  testStack.push(2);
  testStack.push(3);

  std::cout << "new size: " << testStack.size() << std::endl;
  std::cout << "does top work?" << testStack.top() << std::endl;

  std::cout << "does pop work?" << std::endl;
  testStack.pop();
  std::cout << "post-pop: " << testStack.top() << std::endl;

  std::cout << "let's pop the rest" << std::endl;
  testStack.pop();
  testStack.pop();

  std::cout << "checking if empty works now" << std::endl;
  if(testStack.empty()){
    std::cout << "emptttyyyyyy" << std::endl;
  }
  else{
    std::cout << "uh oh... not empty?" << std::endl;
  }

  return 0;
}