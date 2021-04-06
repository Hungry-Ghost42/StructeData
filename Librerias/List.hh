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
      Node* next;

    public:
      Node( const T& d)
        : data(d)
        , next(nullptr) {}
      const T& getData() {return data;}
      Node* getNext() {return next;}
      void setNext(Node* n) {next = n;}
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
            }
            last = n;
            sz += 1;
          }

        //push_front
        void push_front(const T& e){
          Node* n = new Node(e);
          n -> setNext(first);
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

        if(first == nullptr) {
          last = nullptr;
        }
        delete n;
        sz -= 1;
      }

      //Funcion 'pop_back' elimina el ultimo elemento de la lista.
      void pop_back() {
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
      }

      void remove (const T& e){
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
          } else{   //Si no encuentra el numero, mueve los nodos una posicion.
          preNode = n;
          n = n->getNext();
            }
          }
        }
      }


  };


#endif
