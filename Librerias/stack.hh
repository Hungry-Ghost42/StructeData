#ifndef __STACH_HH__
#define __STACK_HH__

#include <iostream>
#include <cassert>
#include "List.hh"
#include "Vector.hh"

using namespace std;
template <typename T>

  //Implementado con Listas.
/*
  class Stack{
  private:
    List<T> storage;

  public:
    Stack() : storage(){}
    void push(const T& e) {storage.push_front(e);}
    void pop() {storage.pop_front();}
    const T& top() {return storage.front();}
    unsigned int size() {return storage.size();}
    void print() {storage.print();}
  };
*/

    //Implementacion con Vectores.
    class Stack{
    private:
      Vector<T> storage;

    public:
      Stack() : storage(){}
      void push(const T& e) {storage.push_back(e);}
      void pop() {storage.pop_back();}
      const T& top() {return storage.back();}
      unsigned int size() {return storage.size();}
      void print() { storage.print_reverse();}

    };
//

#endif
