#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

// because i used vector containter
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapStorage;
  int m;
  PComparator c;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), c(c) {
  if(m < 2){
    throw std::invalid_argument("ary too small error");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
  heapStorage.clear();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heapStorage.push_back(item);

  size_t index = heapStorage.size() - 1;

  while(index > 0){
    size_t parentNode = (index - 1) / m;

    if(c(heapStorage[parentNode], heapStorage[index])){
      break;
    }

    T temporary = heapStorage[index];
    heapStorage[index] = heapStorage[parentNode];
    heapStorage[parentNode] = temporary;

    index = parentNode;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  if(heapStorage.empty()){
    return true;
  }
  else{
    return false;
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  if(heapStorage.empty()){
    return 0;
  }
  else{
    return heapStorage.size();
  }
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty underflow error");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapStorage[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty underflow error");
  }

  T temporary = heapStorage[0];
  heapStorage[0] = heapStorage[heapStorage.size() - 1];
  heapStorage[heapStorage.size() - 1] = temporary;

  heapStorage.pop_back();

  size_t index = 0;
  bool complete = false;

  while(!complete){
    size_t betterNode = index;
    for(int i = 0; i <= m; i++){
      size_t childNode = m * index + i;
      if(childNode < heapStorage.size() && c(heapStorage[childNode], heapStorage[betterNode])){
        betterNode = childNode;
      }
    }
    
    if(betterNode == index){
      complete = true;
    }
    else{
      T temporary = heapStorage[index];
      heapStorage[index] = heapStorage[betterNode];
      heapStorage[betterNode] = temporary;
      index = betterNode;
    }
  }
}



#endif

