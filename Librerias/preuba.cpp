#include <iostream>
#include "List.hh"

int main() {

  List<int> A;
 for(int i=0;i<=10;i++) {
    A.push_back(i);
  }
  cout<<A.size()<<endl;
    A.push_front(6);
    A.push_back(7);
    A.print();
    cout<<A.size()<<endl;
  /*
  A.push_back(7);
    cout<<A.size()<<endl;
    A.print();  */

    A.remove(7);
    cout<<A.size()<<endl;
    A.print();
    A.reverse();
    A.print();
    //HOla xd

    //cout << "hola";
}
