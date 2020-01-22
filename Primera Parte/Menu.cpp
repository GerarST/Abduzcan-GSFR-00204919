#include <iostream>
#include <string>
using namespace std;

struct address{
    int HouseNumber;
    string city, state;
};

struct Deliverdata{
     int Persons, amount, payType, maindish, mouth, drink, telephone;
     string name;
     address Direction;
};
struct Deliverdata DataD;

struct Restdata{
     int Persons,amount, payType, maindish, mouth, drink, telephone;
     string name;
     address Direction;
};
struct Restdata DataR;

bool login();
void menu();
void addDelivery(Deliverdata *Deliv, int size);
void addRest(Restdata *Rest, int size);
void OpMenu(int n, int opcion, int Naux1, int Naux2);
void PrintDeliv(Deliverdata *Deliv, int size);
void PrintRest(Restdata *Rest, int size);

bool isAdmin = false;

int main(){
    int n = 0, opcion = 0, Naux = 0;
    Deliverdata Deliv[n];
    Restdata Rest[n]; 
    if(login() == false)
        return 0;

    menu();
    cin >> opcion;
     
 cin.ignore();
}

bool login(){

    string user, password = "cin.clear", userVery, passVery;
    int userType;
    
    cout<<"\t\t\t MENU DE INICIO DE CESION.\n";
    cout<<"\t\t\t Que tipo de cuenta desea usar?: \n\t 1> Administrador. \n\t 2> Empleado. \n\t Opcion: ";
    cin >> userType; cout << endl;

    if(userType == 1){
        cout<<"\t\t\tLOGIN DEl USUARIO: Administrador\n";
        cout<<"\t\t\t-----------------\n";
        cout <<"\tUSUARIO: "; cin.ignore();
        getline(cin, user); 
        cout <<"\n\tPASSWORD: "; cin.ignore();
        cin >> passVery;

        if(password == passVery){
            cout << "Bienvenido"<< endl;
            isAdmin = true;
            return true;
        }
        else{
            cout << "Incorrecto"<<endl;
        }
    }
    else if(userType == 2){

        cout<<"\t\t\tLOGIN DEl USUARIO: Empleado\n";
        cout<<"\t\t\t-------------------\n";
        return true;
    }
    else{
        cout << "alv"<< endl;
    }
    return false;
}

void menu(){
    cout << "\t\t\t BIENVENIDO AL PORTAL DE ORDENES\n";
    cout << "\t\t\t -------------------------------\n";
     cout<<"\n\t\t\t            Menu";
     cout<<"\n\t 1> Agregar 1 pedido a domicilio";
     cout<<"\n\t 2> Agregar 1 encargo en restaurante";
     cout<<"\n\t 3> Ver pedidos a domicilio";
     cout<<"\n\t 4> Ver encargos en el restaurante";
     cout<<"\n\t 5> Ver total de venta\n\n";
}

void addDelivery(Deliverdata *Deliv, int size){
    cin.ignore();
    cout << "\n\t\t\t Bienvenido al portal de ingreso!";
    for (int i = 0; i < size; i++)
    {
   cout << "\n\t Ingrese su nombre: ";
    getline(cin, Deliv[i].name); cin.ignore();
   cout << "\n\t Digite su dirección... ";
    cout << "\n\t Digite el numero de casa: ";
    cin >> Deliv[i].Direction.HouseNumber; cin.ignore();
    cout << "\n\t Digite la ciudad: ";
    getline(cin, Deliv[i].Direction.city); cin.ignore();   
    cout << "\n\t Digite el numero de casa: ";
    getline(cin, Deliv[i].Direction.state); cin.ignore(); 
   cout << "\n\t Digite su numero telefonico: ";cin.ignore();
    cin >> Deliv[i].telephone;
    cout << "\n\tPedido: ";
   cout << "\n\t Ingrese el plato principal: "; 
   cout << "\n\t 1> Pizza. \n\t 2> Ensalada. \n\t 3> Pasta. \n\t Opcion: ";cin.ignore();
    cin >> Deliv[i].maindish;  
    cout << "\n\t Escoja la entrada que desee para acompañar: "; 
    cout << "\n\t 1> Rollitos de queso. \n\t 2> Papas fritas. \n\t Opcion: ";cin.ignore();
    cin >> Deliv[i].mouth;
   cout << "\n\t: Seleccione la bebida que desee: \n\t 1> Gaseosa. \n\t 2> Te. \n\t Opcion: ";cin.ignore();
    cin >> Deliv[i].drink; 
    cout << "\n\t Ingrese el monto: "; 
    cin >> Deliv[i].amount;
    cout << "\n\t Seleccione el tipo de pago: \n\t 1> Efectivo. \n\t 2> Tarjeta. \n\t Opcion: "; 
    cin >> Deliv[i].payType;  
    }  
}

void addRest(Restdata *Rest, int size){
    cin.ignore();
    cout << "\n\t\t\t Bienvenido al portal de ingreso!";

    for (int i = 0; i < size; i++)
    {
   cout << "\n\t Ingrese su nombre: ";
    getline(cin, Rest[i].name); cin.ignore();
   cout << "\n\t Digite la cantidad de personas acompañantes: ";
    cin >> Rest[i].Persons; cin.ignore();
   cout << "\n\t Ingrese el plato principal: "; 
   cout << "\n\t 1> Pizza. \n\t 2> Ensalada. \n\t 3> Pasta. \n\t Opcion: ";
    cin >> Rest[i].maindish; cin.ignore();  
    cout << "\n\t Escoja la entrada que desee para acompañar: "; 
    cout << "\n\t 1> Rollitos de queso. \n\t 2> Papas fritas. \n\t Opcion: ";
    cin >> Rest[i].mouth;cin.ignore();
   cout << "\n\t: Seleccione la bebida que desee: \n\t 1> Gaseosa. \n\t 2> Te. \n\t Opcion: ";
    cin >> Rest[i].drink; 
    cout << "\n\t Ingrese el monto: "; 
    cin >> Rest[i].amount;
    cout << "\n\t Seleccione el tipo de pago: \n\t 1> Efectivo. \n\t 2> Tarjeta. \n\t Opcion: ";
    cin >> Rest[i].payType;
    }
    cin.ignore();
}

void OpMenu(int n, int opcion, int Naux1, int Naux2){
    Deliverdata Deliv[n];
    Restdata Rest[n];
     if (opcion == 1)
     {
        cout << "\t Ingrese la cantidad de pedidos: "; cin >> n;
        Naux1 = n;
        Deliverdata Deliv[n];
        addDelivery(Deliv, n);
     }
     else if (opcion == 2)      
     {
        cout << "\t Ingrese la cantidad de pedidos: "; cin >> n;
        Naux2 = n;
        Restdata Rest[n];   
        addRest(Rest, n); 
     }
     else if(opcion == 4){
         PrintDeliv(Deliv,Naux1);
     }
     else if (opcion == 5)
     {
         
     }
     else{
         cout << "\n\tError, numero invalido\n";
     }

}

void PrintDeliv(Deliverdata *Deliv, int size){
    for (int i = 0; i < size; i++){
        cout << "\n\t Plato principal: ";

        switch(Deliv[i].maindish){
            case 1:
            cout << "\n\tPizza.";
            break;
            case 2:
            cout << "\n\tEnsalada.";
            break;
            case 3:
            cout << "\n\tPasta.";
            break;
            default: cout << "\n\tError.";
            break;                  
        }  

        cout << "\n\t Acompañamieto: "; 

        switch(Deliv[i].mouth){
            case 1:
            cout << "\n\tRollitos de queso.";
            break;
            case 2:
            cout << "\n\tPapas fritas.";
            break;
            default: cout << "\n\tError.";
            break;                  
        }

        cout << "\n\t Bebida: ";cin.ignore();

        switch(Deliv[i].drink){
            case 1:
            cout << "\n\tGaseosa.";
            break;
            case 2:
            cout << "\n\tTe.";
            break;
            default: cout << "\n\tError.";
            break;
        }

        cout << "\n\t Monto: "; 
        cout << "\n\t" << Deliv[i].amount;
    
        cout << "\n\t Tipo de pago: "; 

        switch(Deliv[i].payType){
            case 1:
            cout << "\n\tEfectivo.";
            break;
            case 2:
            cout << "\n\tTarjeta.";
            break;
            default: cout << "\n\tError.";
            break;
        }   
    }
}

void PrintRest(Restdata *Rest, int size){
for (int i = 0; i < size; i++){
    cout << "\n\t Plato principal: ";cin.ignore();

     switch(Rest[i].maindish){
         case 1:
         cout << "\n\tPizza.";
         break;
         case 2:
         cout << "\n\tEnsalada.";
         break;
         case 3:
         cout << "\n\tPasta.";
         break;
         default: cout << "\n\tError.";
         break;                  
     }  
    cout << "\n\t Acompañamieto: "; 

         switch(Rest[i].mouth){
         case 1:
         cout << "\n\tRollitos de queso.";
         break;
         case 2:
         cout << "\n\tPapas fritas.";
         break;
         default: cout << "\n\tError.";
         break;                  
     }
   cout << "\n\t Bebida: ";cin.ignore();

         switch(Rest[i].drink){
         case 1:
         cout << "\n\tGaseosa.";
         break;
         case 2:
         cout << "\n\tTe.";
         break;
         default: cout << "\n\tError.";
         break;
     }

    cout << "\n\t Monto: "; 
    cout << "\n\t" << Rest[i].amount;

    cout << "\n\t Tipo de pago: "; 

         switch(Rest[i].payType){
         case 1:
         cout << "\n\tEfectivo.";
         break;
         case 2:
         cout << "\n\tTarjeta.";
         break;
         default: cout << "\n\tError.";
         break;
     }    
}
}