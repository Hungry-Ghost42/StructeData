#ifndef __QUEUE_HH__
#define __QUEUE_HH__

#include <iostream>
#include <cassert>
#include "List.hh"
#include "Vector.hh"

using namespace std;
template <typename T>

/*
  //Implementacion con Listas.
  class Queue{
  private:
    List<int> storage;
  public:
  void push(const T& e){storage.push_back(e); }
  void pop() { storage.pop_front();}
  const T& top() {return storage.front();}
  unsigned int size() {return storage.size();}
  void print() {storage.print();}
};
*/

  //Implementacion con vectores.
  class Queue{
  private:
    Vector<int> storage;
  public:
    void push(const T& e){storage.push_back(e);}
    void pop() {storage.pop_front();}
    const T& top() {return storage.front();}
    unsigned int size() {return storage.size();}
    void print() { storage.print();}
  };

#endif
