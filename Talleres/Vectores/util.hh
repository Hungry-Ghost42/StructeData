#ifndef __UTIL_HH__
#define __UTIL_HH__


#include <random>
#include "Vector.hh"


using namespace std;


random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(1, 10);

// Genera un entero aleatorio en el intervalo [1,10]
int randInt() { return distrib(gen); }

// Genera un vector de tamaño size con enteros aleatorios.
Vector<int> randVector(unsigned int size) {
  Vector<int> result;

  for(unsigned int i=0;i < size; i++) {
    result.push_back(randInt());
  }
    return result;
  }
#endif
