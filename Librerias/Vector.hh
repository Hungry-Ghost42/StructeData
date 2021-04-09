  #ifndef __VECTOR_HH__
  #define __VECTOR_HH__
  #include <cassert>
  #include <iostream>



  using namespace std;

  template <typename T>

  class Vector{
  private:
    unsigned int sz;
    unsigned int capacity;
    double policy;
    T* storage;

  public:
    Vector() {
      sz = 0;
      capacity = 8;
      storage = new T[capacity];
    }

    Vector<T>& operator=(const Vector<T>& other) {
    if (this != &other) {
      sz = other.sz;
      capacity = other.capacity;
      storage = new T[capacity];
      for (unsigned int i = 0; i < sz; i++) {
        storage[i] = other.storage[i];
      }
    }
    return *this;
  }

    Vector(const Vector<T>& other) {
      sz = other.sz;
      capacity = other.capacity;
      storage = new T[capacity];

      for(unsigned int i = 0; i < sz; i++) {
        storage[i] = other.storage[i];
      }
    }

    Vector(unsigned int c, double p = 1.5) {
      assert(p > 1.0);
      sz = 0;
      capacity = c;
      policy = p;
      storage = new T[capacity];
    }



    ~Vector() { delete[] storage;}

    unsigned int size()  { return sz;}

    void push_back(const T& e) {
      if(sz == capacity) {
        resize();
      }
      storage[sz] = e;
      sz += 1;
    }

    void push_front(const T& e) {
      if(sz == capacity) {
        resize();
      }
      for( unsigned int i = sz ; i > 0; i --) {
        storage[i] = storage[i-1];
      }
      storage[0] = e;
      sz += 1;
    }

    bool isValid(unsigned pos) { return pos >= 0 && pos < sz;}

    void swap(unsigned int i, unsigned int j) {
      if(!isValid(i)) {
        cout << i << " : no es valida " << sz << endl;
      }
      if(!isValid(j)) {
        cout << j << " : no es valida " << sz << endl;
      }
      assert(i >= 0 && i < sz && "Primera posicion no es valida");
      assert(j >= 0 && j < sz && "Segunda posicion no es valida");

      T tmp = storage[i];
      storage[i] = storage[j];
      storage[j] = tmp;
    }

  private:
    void resize() {

      unsigned int newCapacity = capacity * 2;
      T* newStorage = new T[newCapacity];
        for(unsigned int i = 0; i < sz; i++) {
          newStorage[i] = storage[i];
        }
        delete[] storage;
        storage = newStorage;
        capacity = newCapacity;

    }

  public:
    T& at(unsigned int p) {
      assert(p >= 0 && p < sz && "Posicion invalida. ");
      return storage[p];
    }

    bool empty() {return sz == 0;}

    T& front() {
      assert(!empty() && "El vector no puede estar vacio.");
      return storage[0];
    }

    T& back() {
      assert(!empty() && "El vector no puede estar vacio.");
      return storage[sz - 1];
    }

    void print() {
      for(unsigned int i = 0; i < sz; i++) cout << " " << at(i);
      cout << endl;

    }



    void bsort() {
      for(unsigned int i = 0; i < sz; i++) {
        for(unsigned int j = 0; j < sz -1 - i; ++j) {
          if(storage[j] > storage[j+1]) swap(j, j+1);
        }
      }
    }


    void qsort(int der = 0,  int izq = 0) {
      int i = izq, j = der;
      int pivote = storage[ (izq + der) / 2];
      while( i <= j) {
         while(storage[j] > pivote) j--;
          if( i <= j) {
            swap(i, j);
            i++;
            j--;
          }
      }
      if(izq < j)
        qsort(j, izq);
      if(i < der)
        qsort(der, i);

    }

    //Operaciones pedagogicas
    size_t usedMem() {
    return ( sizeof(unsigned int) * 2 +
     capacity * sizeof(T) +
     sizeof(T*) );
    }

    size_t usefulMem() {
      return sizeof(T*) +
      2*sizeof(unsigned int) +
      sz * sizeof(T);
    }

    //Implementaciones.
    //funcion find

    unsigned int find(T& num) {
      unsigned int pos = sz;
      for(unsigned int i = 0; i < sz; i++) {
        if( num == storage[i] ) { pos = i;}
      }
      return pos;
    }

    //reverse
    void reverse() {
      unsigned int i = 0, j = sz - 1;
      while(i < j) {
      swap(i,j);    //O(1)
        i++;  
        j--;
      }
    }

    //Slice
    Vector<T> slice(unsigned int a, unsigned int b) {
      Vector<T> vect(b-a);
      for(unsigned int i = a; i < b; i++){
        vect.push_back(storage[i]);
      }
      return vect;
    }

    //Funcion para ordenar pares e impares
    void even(){
      int i = 0, j = sz - 1;

      while(i < j){
        if(storage[i] % 2 == 0) {
          i++;
        }
        if(storage[j] % 2 !=  0) {
          j--;
        }

        if(storage[i] % 2 != 0 && storage[j] % 2 == 0) {
          swap(i,j);
          i++;
          j--;
        }
      }
    }

    //Funcion 'rotate' que rota los elementos 'n' posiciones
    void rotate( int p){
      int tmp, tmp2;
      int i = sz - 1, j = 0;
      tmp = storage[i]  ;
      while(p > 0){
        while(j < sz){
        if(i-1 < 0) { i = sz;}
        tmp2 = storage[i-1];
        storage[i-1] = tmp;
        i--;
        j++;
        tmp = tmp2;
      }
        cout << "tmp: " << tmp << "  tmp2: " << tmp2 << endl;
        print();
        j = 0;
        p--;
      }


    }

  };
#endif
