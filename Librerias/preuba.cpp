#include <iostream>
#include "List.hh"
#include "stack.hh"
#include "Vector.hh"
#include <ctime>
#include <math.h>
#include "queue.hh"
using namespace std;
int main() {
/*
  char a;
  List<char> b;
  for(int i=0;i<=10;i++) {
    cout << "letra: "; cin.get(a);
     b.push_back(a);
   }
   b.print();
   b.sort();
   b.print(); */
/*
   //Stack<int> a;
   Queue<int> a;
   a.push(21);
//   cout << "1" << endl;
   a.push(42);
   a.push(69);
   a.print();
   a.pop();
   a.print();
   cout << a.top();
*/
  Dequeue<int> a;
  a.push_back(69);
  a.push_front(23);
  a.push_back(53);
  a.push_front(99);
  a.print();
  a.pop_back();
  a.pop_front();
  a.print();
  cout << endl << a.top() << "  "<< a.back();


   return 0;
}
