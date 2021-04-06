#ifndef __LIST_HH__
#define __LIST_HH__

#include <iostream>
#include <cassert>

using namespace std;
template <typename T>

  class List{
  private:
    class Node {
    private:
      //atributos de nodo.
      T data;
      Node* prev;
      Node* next;

    public:
      Node( const T& d)
        : data(d)
        , next(nullptr)
        , prev(nullptr) {}
  const T&  getData() {return data;}
      Node* getPrev() {return prev;}
      Node* getNext() {return next;}
      void  setPrev(Node* n) {prev = n;}
      void  setNext(Node* n) {next = n;}
    };

    //Atributos de lista.
    unsigned int sz;
    Node* first; //Almacena la direccion del primer elemento de la lista.
    Node* last;
  public:
      List() //Constructor de lista vac ia.
      : first(nullptr)
      , last(nullptr)
      , sz(0) {}

      bool empty() {return first == nullptr;}
      int size() {return sz;}

      //push_back
          void push_back(const T& d) {
            Node* n = new Node(d);
            if(empty()) {
              first = n;
            } else {
                last -> setNext(n);
                n -> setPrev(last);
            }
            last = n;
            sz += 1;
          }

        //push_front
        void push_front(const T& e){
          Node* n = new Node(e);
          n -> setNext(first);
          first -> setPrev(n);
          if(empty()) {
            last = n;
          }
          first = n;
          sz += 1;
        }

      //Imprimir lista version ats
      void print() {
        if(empty()) {
          cout << "<>" << endl;
        } else{
          Node* p = first;
          while(p != nullptr) {
            cout<< " " << p->getData() ;
            p = p->getNext();
          }
          cout << endl;
        }
      }

      //Funcion 'pop_front' elimina el primer elemento de la lista
      void pop_front() {
        assert(!empty() && "Lista vacia");
        Node *n = first;
        first = first -> getNext();
        first -> setPrev(nullptr);

        if(first == nullptr) {
          last = nullptr;
        }
        delete n;
        sz -= 1;
      }

      //Funcion 'pop_back' elimina el ultimo elemento de la lista.
      //Version lista simplemente enlazada
    /*  void pop_back() {
        assert(!empty() && "Lista vacia");
        if(first == last) {
          delete last;
          first = nullptr;
          last = nullptr;
        } else {
          Node *n = first;
          while(n -> getNext() != last) {
            n = n->getNext();
          }
          n->setNext(nullptr);
          delete last;
          last = n;
        }
        sz -= 1;
      } */
      //Funcion 'pop_back' elimina el ultimo elemento de la lista.
      //Version lista doblemente enlazada
      void pop_back() {
        assert(!empty() && "Lista vacia");
        if(first == last) {
          delete last;
          first = nullptr;
          last = nullptr;
        } else {
          Node *n = last ->getPrev();
          n->setNext(nullptr);
          delete last;
          last = n;
        }
        sz -= 1;
      }

        //Funcion remove //Version lista simplemente enlazada

    /*  void remove (const T& e){       //Elimina todos los indicencias
        if(!empty()) {
        Node *n = first;
        Node *preNode = n; //Puntero al nodo anterior
        while(n != nullptr) {
          if(n->getData() == e){    //Si encuentra el elemento.
            if(preNode == n) {  //Cuando es el primer elemento de la lista.
              first = first->getNext(); //'fist' apunta al siguiente nodo
              delete n; //se borra el nodo en 'n'
              n = first;
              preNode = n;
            } else {
                preNode->setNext(n->getNext()); //'preNode' apuntara al siguiente nodo de 'n'
                delete n;                     //Se borra 'n'
                n = preNode->getNext();       //'n' sera el siguiente nodo.

            }
            sz -= 1;
          } else{   //Si no encuentra el numero, mueve los nodos una posicion.
          preNode = n;
          n = n->getNext();
            }
          }
        }
      }
      void remove (const T& e){       //Elimina una vez.
          if(!empty()) {
          Node *n = first;
          Node *preNode = n; //Puntero al nodo anterior
          while(n != nullptr && n->getData() != e) { //recorre el arreglo mientras el valor en 'Data' no sea el numero a buscar
              preNode = n;          //Avanza los nodos una posicion
              n = n->getNext();
            } //Cuando
              if(preNode == n) {  //Cuando es el primer elemento de la lista.
                first = first->getNext(); //'fist' apunta al siguiente nodo
                delete n; //se borra el nodo en 'n'
                n = first;
                preNode = n;
              } else if(n != nullptr) {
                  preNode->setNext(n->getNext()); //'preNode' apuntara al siguiente nodo de 'n'
                  delete n;                     //Se borra 'n'
                  n = preNode->getNext();       //'n' sera el siguiente nodo.
              }
              sz -= 1;
            }
          }
          */

          //Funcion remove //Version lista doblemente enlazada
      void remove (const T& e) {
        if(!empty()){
            Node *n = first;
            while(n != nullptr && n->getData() != e) { //recorre el arreglo
              n = n->getNext();                       //mientras el valor en 'Data' no sea el numero a buscar
              }
            //Cuando se encuentra el elemento o termina la lista sale del while.
            if(n == first){ //Si es el primer elemento de la lista.
                first = first -> getNext();
                first -> setPrev(nullptr);
                delete n;
              }
            else {
                n -> getPrev() -> setNext(n->getNext());
                n -> getNext() -> setPrev(n->getPrev());
                delete n;
            }
            sz -= 1;
        }
      }

    void reverse() {
      Node *n;
      Node *p = first;
      while(first != last) {
        n = first;
        first = first -> getNext();
        n -> setNext(last->getNext());
        last -> setNext(n);
      }
      last = p;
    }



  };


#endif
