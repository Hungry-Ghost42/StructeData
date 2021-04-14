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
      const T& front() {return first->getData();}

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

      //Funcion push_back de nodos

      void push_back(Node* n) {
        n ->setNext(nullptr);
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

          if(empty())
            last = n;
          else
            first -> setPrev(n);
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


        //Funcion removeAll
      void removeAll (const T& e){       //Elimina todos los indicencias
        if(!empty()) {
        Node *n = first;
        Node *aux;
        while(n != nullptr) {
          if(n->getData() == e){    //Si encuentra el elemento.
            if(n == first) {  //Cuando es el primer nodo de la lista.
              pop_front();
              n = n->getNext();
            }else if(n == last) { //Si 'n' es el ultimo nodo.
                pop_back();
                n = nullptr;
              } else {
                  n -> getPrev() -> setNext(n->getNext());
                  n -> getNext() -> setPrev(n->getPrev());
                  aux = n->getNext();
                  delete n;
                  n = aux;
                }
        sz -= 1;
          } else{   //Si no encuentra el numero, mueve los nodos una posicion.
              n = n->getNext();
            }
          }
        }
      }



          //Funcion remove //Version lista doblemente enlazada
      void remove (const T& e) {
        if(!empty()){
            Node *n = first;
            while(n != nullptr && n->getData() != e) { //recorre el arreglo
              n = n->getNext();                       //mientras el valor en 'Data' no sea el numero a buscar
              }
            //Cuando se encuentra el elemento o termina la lista sale del while.
            if(n == first){ //Si es el primer elemento de la lista.
                pop_front();
              }else if(n == last) { //Si 'n' es el ultimo nodo.
                  pop_back();
                  n = nullptr;

            }else {
                n -> getPrev() -> setNext(n->getNext());
                n -> getNext() -> setPrev(n->getPrev());
                delete n;
            }
            sz -= 1;
        }
      }


    //Funcion removeAt  elimina un nodo en una posicion

   void removeAt(const int p){
      assert(p >= 0 && p < sz && "posicion invalida");
      Node *n = first;

      for(int i=0; i < p;i++) {
        n = n->getNext();
      }
      if(n == first){ //Si es el primer elemento de la lista.
          pop_front();
        }else if(n == last) { //Si 'n' es el ultimo nodo.
            pop_back();
            n = nullptr;
      }else {
          n -> getPrev() -> setNext(n->getNext());
          n -> getNext() -> setPrev(n->getPrev());
          delete n;
      }
      sz -= 1;
    }

//funcion 'reverse' invierte una lista
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

    size_t usedMem() {

      //Nodo
      return sizeof(Node) * sz   //Punteros next y prev
      +
      //lista
      (2*sizeof(Node*) + //punteros first y last
      sizeof(unsigned int) ); //tamaño de sz

    }

    T at(int p){
      Node *n = first;
      for(int i=0; i < p;i++) {
        n = n->getNext();
      }
      return n->getData();

    }

    //Funcion mergeSort

    //Funcion 'split'
    void split(List<T>& f, List<T>& s) {
      assert(f.empty() && "Lista Vacia");
      assert(s.empty() && "Lista Vacia");
      unsigned int i = 0;
      Node* n = first;
      while(first != nullptr) {
        n = first;
        first = first -> getNext();
        if(i % 2 == 0)
          f.push_back(n);
         else
          s.push_back(n);
        i++;
      }
      last = nullptr;
      sz = 0;
    }

    //Funcion merge
    void merge(List<T>& f, List<T>& s) {
      assert(empty() && "Lista Vacia");
      Node* n = nullptr;
      while(f.first != nullptr && s.first != nullptr) {
        if(f.front() < s.front()) {
          n = f.first;
          f.first = f.first -> getNext();
        } else {
          n = s.first;
          s.first = s.first -> getNext();
        }
        push_back(n);
      }
      while(f.first != nullptr) {
        n = f.first;
        f.first = f.first -> getNext();
        push_back(n);
      }
      while (s.first != nullptr) {
        n = s.first;
        s.first = s.first -> getNext();
        push_back(n);
      }
      f.last = nullptr;
      f.sz = 0;
      s.last = nullptr;
      s.sz = 0;
    }

    //Funcion sort recursiva
    void sort() {
      if(size() <= 1){
        return;
      } else {
        List<T> f;
        List<T> s;
        split(f, s);
        f.sort();
        s.sort();
        merge(f, s);
      }
    }

  };


#endif
