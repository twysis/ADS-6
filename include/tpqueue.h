// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 public:
  TPQueue() : first(0), last(0) {}
  int getSize() {
    return last - first;
  }
  void push(T temporary) {
  if (getSize() >= size) {
    throw std::string("full");
  } else {
      int i = last++;
      while ((arr[i % size].prior < temporary.prior) && (--i >= first)) {
        arr[(i + 1) % size] = arr[i % size];
      }
      arr[(i + 1) % size] = temporary;
    }
  }
  T pop() {
    return arr[(first++) % size];
  }
  T front() {
    return arr[(first) % size];
  }
  T back() {
    return arr[(last - 1) % size];
  }
 private:
  T arr[100];
  int first, last;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
