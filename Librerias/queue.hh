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
    List<T> storage;

  public:
  Queue() : storage{}
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
    Vector<T> storage;
  public:
    Queue() : storage() {}
    void push(const T& e){storage.push_back(e);}
    void pop() {storage.pop_front();}
    const T& top() {return storage.front();}
    unsigned int size() {return storage.size();}
    void print() { storage.print();}
  };//

//---------------------------------------------------//
template <typename T>
class Dequeue{
  private:
    List<T> storage;
  public:
    Dequeue() : storage() {}
    void push_back(const T& e){storage.push_back(e); }
    void push_front(const T& e){storage.push_front(e); }
    void pop_front() { storage.pop_front();}
    void pop_back() { storage.pop_back();}
    const T& top() {return storage.front();}
    const T& back() {return storage.back();}
    unsigned int size() {return storage.size();}
    void print() {storage.print();}
  };

#endif
