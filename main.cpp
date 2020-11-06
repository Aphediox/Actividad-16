#include "laboratorio.h"
using namespace std;

int main(){
     laboratorio L1;
     string op;
     while (true)
     {
         cout << "1) Agregar Computadora" << endl;
         cout << "2) Mostrar" << endl;
         cout << "3) Respaldar " << endl;
         cout << "4) Recuperar " << endl;
         cout << "5) Insertar" << endl;
         cout << "6) Inicializar" << endl;
         cout << "7) Eliminar" << endl;
         cout << "8) Ordenar" << endl;
         cout << "9) Buscar" << endl;
         cout << "0) Salir " << endl;
         getline(cin, op);

         if(op == "1"){
            computadora aux ;
            cin >> aux;
            L1.agregarCP(aux);
         }
         else if (op == "2"){
            L1.mostrar();
         }
         else if (op == "3"){
            L1.respaldar();
         }
         else if (op == "4"){
            L1.recuperar();
         }
         else if (op == "5"){
            computadora aux;
            size_t n;
            cout << "Posicion: ";
            cin >> n; cin.ignore();
            if(n >= L1.size()){
                cout << "Posicion no valida" << endl;
            }
            else{
                cin >> aux;
                L1.insertar(aux, n);    
            }
            
         }
         else if (op == "6"){
             size_t n;
             computadora aux;
             cin >> aux;

             cout << "Tam: " ;
             cin >> n; cin.ignore();

             L1.inicializar(aux, n);
         }
         else if(op == "7"){
             size_t n;
             cout << "Posicion: ";
             cin >> n; cin.ignore();
             if (n >= L1.size()){
                 cout << "Posicion no valida." << endl;
             }
             else{
                 L1.eliminar(n);
             }
         }
         else if(op == "8"){
            L1.ordenar();
         }
         else if(op =="9"){
             computadora aux;
             cin >> aux;

            computadora *ptr = L1.buscar(aux);
            if(ptr == nullptr){
                cout << "No encontrado. " << endl;
            }
            else{
                cout << *ptr << endl;
            }
         }
         else if (op == "0"){
             break;
         }
     }
     
    return 0;
}