#include <iostream>
#include <string>
using namespace std;

void login();
void menu();
void addDelivery();
void addRest();


struct Deliverdata{

     string name, direction;
     int Persons,amount, payType, maindish, mouth, drink, telephone;
};
struct Deliverdata DataD;


struct Restdata{

     string name;
     int Persons, amount, payType, maindish, mouth, drink, telephone;
};
struct Restdata DataR;


int main(){
login();
menu();
}


void login(){

    string user, password, userVery, passVery;

    cout<<"\t\t\tSING-IN DEl USUARIO\n";
    cout<<"\t\t\t-------------------\n";
    cout <<"\tUSUARIO: ";
    getline(cin, user); userVery=user;
    cout <<"\n\tPASSWORD: ";cin.ignore();
    getline(cin, password); passVery=password;
    cout<< "\tHa sido registrado exitosamente!\n\n";
    user=" "; password=" ";

    cout<<"\t\t\tLOGIN DEl USUARIO\n";
    cout<<"\t\t\t-----------------\n";
    cout <<"\tUSUARIO: "; cin.ignore();
    getline(cin, user); 
    cout <<"\n\tPASSWORD: "; cin.ignore();
    getline(cin, password);

    if(user == userVery && password == passVery){
        cout<<"\t\t\tBienvenido!\n";
    }
    else{
        cout<<"\tLa contraseña y/o usuario son incorrectos!\n";
    }

}

void menu(){
     int opcion=0;
     cout<<"\n\t\t\t    Menu";
     cout<<"\n\t 1> Agregar 1 pedido a domicilio";
     cout<<"\n\t 2> Agregar 1 encargo en restaurante";
     cout<<"\n\t 3> Ver pedidos a domicilio";
     cout<<"\n\t 4> Ver encargos en el restaurante";
     cout<<"\n\t 5> Ver total de venta\n\n";
     cin>>opcion;

     switch (opcion){
         case 1:
          addDelivery();
           break;
         case 2:
          addRest();
         break;
        }

}

void addDelivery(){

   cout << "\n\t\t\t Bienvenido al portal de ingreso!";
   cout << "\n\t Ingrese su nombre: ";
    getline(cin, DataD.name); cin.ignore();
   cout << "\n\t Digite su dirección: ";
    getline(cin, DataD.direction); cin.ignore();
   cout << "\n\t Digite su numero telefonico: ";cin.ignore();
    cin >> DataD.telephone;
   cout << "\n\t Ingrese el plato principal: "; 
   cout << "\n\t 1> Pizza. \n\t 2> Ensalada. \n\t 3> Pasta. \n\t Opcion: ";
    cin >> DataD.maindish;  
    cout << "\n\t Escoja la entrada que desee para acompañar: "; 
    cout << "\n\t 1> Rollitos de queso. \n\t 2> Papas fritas. \n\t Opcion: ";
    cin >> DataD.mouth;
   cout << "\n\t: Seleccione la bebida que desee: \n\t 1> Gaseosa. \n\t 2> Te. \n\t Opcion: ";
    cin >> DataD.drink; 

}

void addRest(){
 
    cout << "\n\t\t\t Bienvenido al portal de ingreso!";
   cout << "\n\t Ingrese su nombre: ";
    getline(cin, DataR.name); cin.ignore();
   cout << "\n\t Digite la cantidad de personas acompañantes: ";
    cin >> DataR.Persons; cin.ignore();
   cout << "\n\t Ingrese el plato principal: "; 
   cout << "\n\t 1> Pizza. \n\t 2> Ensalada. \n\t 3> Pasta. \n\t Opcion: ";
    cin >> DataR.maindish; cin.ignore();  
    cout << "\n\t Escoja la entrada que desee para acompañar: "; 
    cout << "\n\t 1> Rollitos de queso. \n\t 2> Papas fritas. \n\t Opcion: ";
    cin >> DataR.mouth;cin.ignore();
   cout << "\n\t: Seleccione la bebida que desee: \n\t 1> Gaseosa. \n\t 2> Te. \n\t Opcion: ";
    cin >> DataR.drink; 

}