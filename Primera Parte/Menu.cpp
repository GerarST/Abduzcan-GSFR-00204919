#include <iostream>
#include <string>
using namespace std;

bool isAdmin = false;
int auxD = 0, auxR = 0;

struct address{
    int HouseNumber;
    string city, state;
};

struct Deliverdata{
     int amount, payType, maindish, mouth, drink, telephone;
     string name;
     address Direction;
};
struct Deliverdata DataD;

struct Restdata{
     int Persons,amount, payType, maindish, mouth, drink;
     string name;
     address Direction;
};
struct Restdata DataR;

bool login();
void menu();
void addDelivery(Deliverdata *Deliv);
void addRest(Restdata *Rest);
void PrintDeliv(Deliverdata *Deliv);
void PrintRest(Restdata *Rest);
void searchByName(Deliverdata* array, int size);
void searchByName(Restdata* array, int size);

int main(){
    int n = 0, opcion = 0;
    Deliverdata Deliv[n];
    Restdata Rest[n]; 
    if(login() == false)
        return 0;
    do{
        menu();
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                addDelivery(Deliv);
            break;
            case 2:
                addRest(Rest);
            break;
            case 3:
                PrintDeliv(Deliv);
            break;
            case 4:
                PrintRest(Rest);
            case 5:
                break;
            case 6:
                searchByName(Deliv, auxD);
                break;
            case 7:
                searchByName(Rest, auxR);
                break;
            case 8:
                return 0;
                break;
        
        default: cout << "Error!\n";
            break;
        }
    }while(opcion > 0 && opcion < 7);
}

bool login(){

    string user, password = "cin.clear", passVery;
    int userType;
    
    cout<<"\t\t\t MENU DE INICIO DE CESION.\n";
    cout<<"\t\t\t Que tipo de cuenta desea usar?: \n\t 1> Administrador. \n\t 2> Empleado. \n\t Opcion: ";
    cin >> userType; cin.ignore(); cout << endl;

    if(userType == 1){
        cout<<"\t\t\tLOGIN DEl USUARIO: Administrador\n";
        cout<<"\t\t\t--------------------------------\n";
        cout <<"\tUSUARIO: ";
        getline(cin, user); 
        cout <<"\n\tPASSWORD: ";
        cin >> passVery;

            if(password.compare(passVery) == 0){
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
        cout << "Valor invalido!"<< endl;
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
     cout<<"\n\t 5> Ver total de venta";
     cout<<"\n\t 6> Ver pedidos por nombre a domicilio.";
     cout<<"\n\t 7> Ver pedidos por nombre en restaurante.";
     cout<<"\n\t 8> Salir.";
     cout<<"\n\tOpcion: ";
}

void addDelivery(Deliverdata *Deliv){
    cout << "\n\t\t\t Bienvenido al portal de ingreso!\n";
        int size = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();
    auxD=size;

    Deliv = new Deliverdata[size];
    for (int i = 0; i < size; i++)
    {
   cout << "\n\t Ingrese su nombre: ";
    getline(cin, Deliv[i].name);
   cout << "\n\t Digite su dirección... ";
    cout << "\n\t Digite el numero de casa: ";
    cin >> Deliv[i].Direction.HouseNumber; cin.ignore();
    cout << "\n\t Digite la ciudad: ";
    getline(cin, Deliv[i].Direction.city);   
    cout << "\n\t Digite su departamento: ";
    getline(cin, Deliv[i].Direction.state); 
   cout << "\n\t Digite su numero telefonico: ";
    cin >> Deliv[i].telephone;cin.ignore();
    cout << "\n\tPedido: ";
   cout << "\n\t Ingrese el plato principal: "; 
   cout << "\n\t 1> Pizza. \n\t 2> Ensalada. \n\t 3> Pasta. \n\t Opcion: ";
    cin >> Deliv[i].maindish;  cin.ignore();
    cout << "\n\t Escoja la entrada que desee para acompañar: "; 
    cout << "\n\t 1> Rollitos de queso. \n\t 2> Papas fritas. \n\t Opcion: ";
    cin >> Deliv[i].mouth;cin.ignore();
   cout << "\n\t: Seleccione la bebida que desee: \n\t 1> Gaseosa. \n\t 2> Te. \n\t Opcion: ";
    cin >> Deliv[i].drink; cin.ignore();
    cout << "\n\t Ingrese el monto: "; 
    cin >> Deliv[i].amount;cin.ignore();
    cout << "\n\t Seleccione el tipo de pago: \n\t 1> Efectivo. \n\t 2> Tarjeta. \n\t Opcion: "; 
    cin >> Deliv[i].payType;  cin.ignore();
    }  
}

void addRest(Restdata *Rest){
    cout << "\n\t\t\t Bienvenido al portal de ingreso!";
        int size = 0;
    cout << "\n\tCantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();
    auxR = size;

    Rest = new Restdata[size];

    for (int i = 0; i < size; i++)
    {
   cout << "\n\t Ingrese su nombre: ";
    getline(cin, Rest[i].name); 
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

void PrintDeliv(Deliverdata *Deliv){
    
    for (int i = 0; i < auxD; i++){
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

        cout << "\n\t Bebida: ";
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

void PrintRest(Restdata *Rest){

    for (int i = 0; i < auxR; i++){

    cout << "\n\t Plato principal: ";
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
             default: 
             cout << "\n\tError.";
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

void searchByName(Deliverdata* array, int size){
    bool userExists = false;
    string aux = "";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].name) == 0){
            // Imprimir datos
            userExists = true;
        }
    }
    
    (!userExists) ? cout << "No existe el usuario" : cout << "";
}

void searchByName(Restdata* array, int size){
    bool userExists = false;
    string aux = "";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].name) == 0){
            // Imprimir datos
            userExists = true;
        }
    }
    
    (!userExists) ? cout << "No existe el usuario" : cout << "";
}
