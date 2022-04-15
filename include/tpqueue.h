// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 public:
  TPQueue() : first(0), last(0) {}
  void push(T temp) {
    int i = last++;
    while ((arr[i % size].prior < temp.prior) && (--i >= first)) {
      arr[(i + 1) % size] = arr[i % size];
    }
  }
  T pop() {
    return arr[(first++) % size];
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
