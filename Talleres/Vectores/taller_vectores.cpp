#include "Vector.hh"


using namespace std;

//Codigo quicksort linea 122 de 'Vector.hh'
//1) representar numeros en vectores

  Vector<int> number(const string& s) {
    Vector<int> num;
    for(unsigned int i = 0; i < s.length(); i++) {
      num.push_back(s[i] - '0'); //Al restarle '0' ayuda a mostrar el dato como numero.
    }                            //en vez del valor ascii
    return num;
  }

//2) Sumar elementos de dos vectores en uno nuevo.
  Vector<int> sum(Vector<int>& n, Vector<int>& m) {
    Vector<int> suma;
    int i  = n.size() - 1 , j = m.size() - 1; //iteradores empiezan al final de cada vector.
    int aux1, aux2;
    int sum1 = 0, residuo = 0;
    while(i >= 0 || j >= 0){   //Mientras al menos un iterador sea mayor o igual a 0.
      //validar si la posicion existe en el vector y asigna un valor dependiendo el caso.
      if(n.isValid(i)) aux1 = n.at(i); else aux1 = 0;   //Si la posicion no existe asigna 0.
      if(m.isValid(j)) aux2 = m.at(j); else aux2 = 0;

      sum1 = aux1 + aux2;
      //Si la suma tiene menos de 2 digitos
      if((sum1 + residuo) < 10) { //El 'residuo' es el numero de la decena.
        suma.push_front(sum1 + residuo);
        residuo = 0;
        }
        else {
          suma.push_front((sum1 + residuo) % 10); //La unidad va al vector.
          residuo = (sum1 + residuo) / 10; }      //La decena se almacena para la siguiente suma.
        i--; j--; //Control de iteracion
    }
    return suma;
  }

//Funcion multiplicar dos vectores.
  Vector<int> mult(Vector<int>& n, Vector<int>& m) {
    Vector<int> multi;
    int aux1, aux2;
    int mult = 0, pot = 1, residuo = 0;   //'pot' potencia.

    for(int i = n.size() - 1 ; i >= 0; i--) {
      Vector<int> aux;    //define el vector auxiliar en cada iteracion
      mult = 0; residuo = 0;
      if(n.isValid(i)) aux1 = n.at(i); else aux1 = 0;
        for(int j = m.size() - 1 ; j >= 0; j--) {
            if(m.isValid(j)) aux2 = m.at(j); else aux2 = 0;
            mult = (aux1 * (aux2 * pot)) + residuo;   //Hace la multiplicacion y suma.

            if(mult < 10) {             //cuando es de un digito.
              aux.push_front(mult);
              residuo = 0;
          } else{
              aux.push_front(mult % 10);
              residuo = mult / 10;
          }
          while(j == 0 && residuo != 0){    //Para separar el residuo acumulado.
              aux.push_front(residuo%10);
              residuo /= 10;
            }
        }
        pot *= 10;
        multi = sum(multi, aux);

    }

    return multi;
  }




int main() {

  //Funcion que convierte string de numeros en vector.
  string s = "723941685";
  Vector<int> numeros = number(s);
  cout << "Vector de numeros: " << endl;
  numeros.print();
  //Funcion de ordenar numeros mediante QuickSort.
  cout << "Ordenando..." << endl << "Vector ordenado: " << endl;
  numeros.bsort();  //Tiene como entrada el tamaño del vector menos unidad.
  numeros.print();
  //Funcion sumar dos vectores.
  string n1 = "43512";
  string n2 = "3472";
  Vector<int> v1 = number(n1);
  Vector<int> v2 = number(n2);
  Vector<int> v3 = sum(v1, v2);
  cout << endl <<"Sumando..." << endl;
  v1.print();
  v2.print();
  cout << "------------" << endl;
  v3.print();
  cout << endl;

  //Funcion multiplicar dos vectores.
  string n3 = "64563";
  string n4 = "342";
  Vector<int> v4 = number(n3);
  Vector<int> v5 = number(n4);
  Vector<int> v6 = mult(v4, v5);
  cout << endl <<"Multiplicando..." << endl;
  v4.print();
  v5.print();
  cout << "------------" << endl;
  v6.print();


  return 0;
}
