#include <iostream>

using namespace std;

int main() {

int numero, aux, min, nuevo=0, max=0, medio=10;

cin  >> numero;
cout << "Numero: " << numero << endl;
//if(numero/1000 >= 1 && numero/1000 < 10){
    aux = numero;
    min = aux%10;
      while(aux > 0){

        if(aux%10 >= max) {max = aux%10;}
        if(aux%10 <= min) {min = aux%10;}
        aux /= 10;
      }
      nuevo += max;
      nuevo += min*1000;

      while(numero > 10){

       if(numero%10 == min ) {numero /= 10; min = 10;}
        else if(numero%10 == max ) {numero /= 10; max = 10;}
          else if(medio == 10 ){medio = numero%10; numero /= 10;
            if(numero < 10) {medio += numero*10; }
             else{ medio += numero%10*10; numero /= 10;}}


    }

      if(medio%10 > medio/10){
        nuevo += (medio%10)*10 + (medio/10)*100;
      } else {nuevo += (medio%10)*100 + (medio/10)*10; }

  cout << "Resultado: " << nuevo << endl; 
//}else{cout<<"El numero no es de 4 digitos.";}

return 0;
}
