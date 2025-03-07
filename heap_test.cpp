#include <iostream>
#include "heap.h"

int main() {
  Heap<int> heap;

  if(heap.empty()){
    std::cout << "issssemmmptttyyy" << std::endl;
  }
  else{
    std::cout << "omg it isn't empty" << std::endl;
  }

  std::cout << "pushing 1, 2 3!!!!!!" << std::endl;

  heap.push(1);
  heap.push(2);
  heap.push(3);

  std::cout << "new heap sizzzzeee: " << heap.size() << std::endl;

  std::cout << "what about top: " << heap.top() << std::endl;

  std::cout << "let's remove stuff" << std::endl;

  while(!heap.empty()){
    heap.top();
    heap.pop();
  }

  std::cout << "checking empty again!!!" << std::endl;

  if(heap.empty()){
    std::cout << "phew it's empty" << std::endl;
  }
  else{
    std::cout << "uh oh it's not empty" << std::endl;
  }

  return 0;
}