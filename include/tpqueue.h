// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
  T arr[size] = { 0 };
  int l, f;
 public:
  void push(T x) {
    int j = l;
    for ( ; (j >= f) && arr[j % size].prior < x.prior; --j) {
      arr[(j + 1) % size] = arr[j % size];
    }
    arr[(j + 1) % size] = x;
    ++l;
  }
  T pop() {
    return arr[(f++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
