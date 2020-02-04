#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define PASSWORD "cin.clear"

//Comida.
enum Maindish {Pizza, Salad, Pasta};
enum Drink {Juice, Soda, Tea};
enum Starter {GarlicBread, FrenchFries, CheeseSticks};
//Pago.
enum PayType{Card, Cash};
//Estructuras para enums
struct MainD{
    Maindish element;
    MainD* next;
};
struct Drinks{
    Drink element;
    Drinks* next;
};
struct Starters{
    Starter element;
    Starters* next;
};
//Estructuras de datos.
struct Address{
    int hNum;
    string settlement, municipality, department;
};

struct MenuInfo{
    string name;
    MainD *orDish;
    Drinks *orDrink;
    Starters *orStarter;
    PayType Pay;
    int idOrder;
    float total;
    float waitTime;
};

struct DeliveryOrder{
    Address DeliveryAddress;
    MenuInfo DeliveryMenu;
    int cellphone;
    DeliveryOrder* next;
};

struct RestOrder{
    int Persons;
    MenuInfo RestMenu;
    RestOrder* next;
};
//Variables globales.
bool Admin = false;
int idOrder = 1;
const float TotalS[] = {3.99, 4.99, 3.75};
const float TotalM[] = {13.99, 5.55, 6.25};
const float TotalD[] = {1.99, 0.95, 1.15};
//Prototipos de funciones.
bool login();
void printOptions();
DeliveryOrder* AddOrder(DeliveryOrder* list);
RestOrder* AddOrder(RestOrder* list);
MainD* AddFood(MainD* list, Maindish md);
Drinks* AddFood(Drinks* list, Drink d);
Starters* AddFood(Starters* list, Starter st);
void PrintOrder(DeliveryOrder* list);
void PrintOrder(RestOrder* list);
void Print(MainD* list);
void Print(Drinks* list);
void Print(Starters* list);
float PrintTotal(MainD* list);
float PrintTotal(Drinks* list);
float PrintTotal(Starters* list)

int main(){
    //Declaracion de variables y arreglos.
    DeliveryOrder* D_Order = NULL;
    RestOrder* R_Order = NULL;
    int option = 0;

    // Verificacion para iniciar sesion
    if(!login())
        return 0;
    
    //Funcionamiento principal
    do{
        printOptions(); cin >> option;
        cin.ignore();

        switch(option){
            // Agregar ordenes a domicilio
            case 1:
                D_Order = AddOrder(D_Order);
            break;
            // Agregar ordenes en restaurante
            case 2:
                R_Order = AddOrder(R_Order);
            break;
            case 3:
                //PrintOrder(D_Order);
            break;
            case 4:
            //nada
            break;
            case 0:
            // nada
            break;
            default:
            break;
        }        

    }while(option != 12);

    return 0;
}

bool login(){
    string Pass = "";
    char option;
    cout << "\n\t\t\tINICIO DE SESION\n";
    cout << "\t\t\t----------------\n";
    cout << "\tA - Administrador\n";
    cout << "\tE - Empleado\n";
    cout << "\tSu opcion:\t"; cin >> option;

    switch(option){
        case 'a':
        case 'A':
            cout << "Contraseña de Administrador: "; cin >> Pass;

            if(Pass.compare(PASSWORD) == 0){
                Admin = true;
                return true;
            }
            else{
                cout << "Contraseña incorrecta" << endl;
            }
            break;
        case 'e':
        case 'E':
            Admin = false;
            return true;
            break;
        default: cout << "Opcion invalida!";
            break;
    }
    return false;
}

void printOptions(){
    cout << "\t\t\t BIENVENIDO AL PORTAL DE ORDENES\n";
    cout << "\t\t\t -------------------------------\n";
    cout << "\n\t\t\t <-------------Menu------------->";
    cout << "\n\t 1> Agregar 1 pedido a domicilio";
    cout << "\n\t 2> Agregar 1 encargo en restaurante";
    cout << "\n\t 3> Ver pedidos a domicilio";
    cout << "\n\t 4> Ver encargos en el restaurante";
    cout << "\n\t 5> Despachar ordenes a domicilio";
    cout << "\n\t 6> Despachar ordenes a restaurante";
    cout << "\n\t 7> Ver tiempo promedio de espera domicilio";
    cout << "\n\t 8> Ver tiempo promedio de espera restaurante";
    cout << "\n\t 9> Cancelar orden. (Domicilio o restaurante: Solo admin)";
    cout << "\n\t 10> Calcular total de ventas";
    cout << "\n\t 11> Cambiar de usuario.";
    cout << "\n\t 12> Salir.";
    cout << "\n\t Opcion: ";
}

DeliveryOrder* AddOrder(DeliveryOrder* list){
    DeliveryOrder* newOrder = new DeliveryOrder;
    newOrder->next = NULL;
    newOrder->DeliveryMenu.orDish = NULL;
    newOrder->DeliveryMenu.orDrink = NULL;
    newOrder->DeliveryMenu.orStarter = NULL;
    //agregar en restaurante
    int aux = 0, auxSt = 0, auxDr = 0, auxMd = 0;
    char opcion;
    float time = 0;
    
    cout << "Nombre:\t"; getline(cin, newOrder->DeliveryMenu.name);
    cout << "Direccion" << endl;
    cout << "Colonia:\t"; getline(cin, newOrder->DeliveryAddress.settlement);
    cout << "Municipio:\t"; getline(cin, newOrder->DeliveryAddress.municipality);
    cout << "Departamento:\t"; getline(cin, newOrder->DeliveryAddress.department);
    cout << "No. casa:\t"; cin >> newOrder->DeliveryAddress.hNum;
    cin.ignore();

        do{

            cout << "Entrada" << endl;
            cout << "1 - Pan con ajo" << endl;
            cout << "2 - Papas Fritas" << endl;
            cout << "3 - Palitos de queso" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();

            if (aux != 4)
            {
                aux--;
                newOrder->DeliveryMenu.orStarter = AddFood(newOrder->DeliveryMenu.orStarter, Starter(aux));
                aux++; auxSt++;
            }
            
        }while(aux != 4);
         
        do{
            cout << "Plato principal" << endl;
            cout << "1 - Pizza" << endl;
            cout << "2 - Pasta" << endl;
            cout << "3 - Ensalada" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();
            
            if (aux != 4)
            {
                aux--;
                newOrder->DeliveryMenu.orDish = AddFood(newOrder->DeliveryMenu.orDish, Maindish(aux));
                aux++; auxMd++;
            }

        }while(aux != 4);

        do{
            cout << "Bebida" << endl;
            cout << "1 - Jugo" << endl;
            cout << "2 - Soda" << endl;
            cout << "3 - Te helado" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();

            
            if (aux != 4)
            {
                aux--;
                newOrder->DeliveryMenu.orDrink = AddFood(newOrder->DeliveryMenu.orDrink, Drink(aux));
                aux++; auxDr++;
            }

        }while(aux != 4);

        
    cout << "Tipo de pago" << endl;
    cout << "1 - Tarjeta" << endl;
    cout << "2 - Efectivo" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    switch (aux){
        case 1:
            newOrder->DeliveryMenu.Pay = Card;
        break;
        case 2:
            newOrder->DeliveryMenu.Pay = Cash;
        break;
        default: cout << "\nOpcion invalida!\n";
        break;
    }

    cout << "Monto: "; cin >> newOrder->DeliveryMenu.total;
    cin.ignore();
    cout << "Telefono: "; cin >> newOrder->cellphone;
    cin.ignore();

    //agregar en restaurante
    newOrder->DeliveryMenu.idOrder = idOrder++;

    time = (auxSt * 1.10 + auxMd * 1.5 + auxDr * 1.35) + 15;
    newOrder->DeliveryMenu.waitTime = time;  

    newOrder->DeliveryMenu.total = PrintTotal(list->DeliveryMenu.orDish) + PrintTotal(list->DeliveryMenu.orDrink) + PrintTotal(list->DeliveryMenu.orStarter);

    if (!list)
        list = newOrder;
    else{
        DeliveryOrder* aux = list;
        while(aux->next)
            aux = aux->next;
        
        aux->next = newOrder;
    }
    return list;
}

RestOrder* AddOrder(RestOrder* list){
    RestOrder* newOrder = new RestOrder;
    newOrder->next = NULL;

    int aux = 0;
    char opcion;
    float time = 0;
    
    cout << "Nombre:\t"; getline(cin, newOrder->RestMenu.name);
    cout << "Personas por mesa:\t"; cin >> newOrder->Persons;
        do{
            cout << "Entrada" << endl;
            cout << "1 - Pan con ajo" << endl;
            cout << "2 - Papas Fritas" << endl;
            cout << "3 - Palitos de queso" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();

            if (aux != 4)
            {
                aux--;
                newOrder->RestMenu.orStarter = AddFood(newOrder->RestMenu.orStarter, Starter(aux));
                aux++;
            }
        }while(aux != 4);

        do{
            cout << "Plato principal" << endl;
            cout << "1 - Pizza" << endl;
            cout << "2 - Pasta" << endl;
            cout << "3 - Ensalada" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();

            
            if (aux != 4)
            {
                aux--;
                newOrder->RestMenu.orDish = AddFood(newOrder->RestMenu.orDish, Maindish(aux));
                aux++;
            }

        }while(aux != 4);

        do{
            cout << "Bebida" << endl;
            cout << "1 - Jugo" << endl;
            cout << "2 - Soda" << endl;
            cout << "3 - Te helado" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();

            
            if (aux != 4)
            {
                aux--;
                newOrder->RestMenu.orDrink = AddFood(newOrder->RestMenu.orDrink, Drink(aux));
                aux++;
            }
        }while(aux != 4);


    cout << "Tipo de pago" << endl;
    cout << "1 - Tarjeta" << endl;
    cout << "2 - Efectivo" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    switch (aux){
        case 1:
            newOrder->RestMenu.Pay = Card;
        break;
        case 2:
            newOrder->RestMenu.Pay = Cash;
        break;
        default: cout << "\nOpcion invalida!\n";
        break;
    }

    cout << "Monto: "; cin >> newOrder->RestMenu.total;
    cin.ignore();

    newOrder->RestMenu.idOrder = idOrder++;

    if (!list)
        list = newOrder;
    else{
        RestOrder* aux = list;
        while(aux->next)
            aux = aux->next;
        
        aux->next = newOrder;
    }
    return list;
}

MainD* AddFood(MainD* list, Maindish md){
    MainD* newFood = new MainD;
    newFood->element = md;
    newFood->next = NULL;

    if (!list)
        list = newFood;
    else{
        MainD* aux = list;
        while(aux->next)
            aux = aux->next;

        aux->next = newFood;
    }
    return list;
}

Drinks* AddFood(Drinks* list, Drink d){
    Drinks* newFood = new Drinks;
    newFood->element = d;
    newFood->next = NULL;

    if (!list)
        list = newFood;
    else{
        Drinks* aux = list;
        while(aux->next)
            aux = aux->next;

        aux->next = newFood;
    }
    return list;
}

Starters* AddFood(Starters* list, Starter st){
    Starters* newFood = new Starters;

    newFood->element = st;
    newFood->next = NULL;

    if (!list)
        list = newFood;
    else{
        Starters* aux = list;
        while(aux->next)
            aux = aux->next;

        aux->next = newFood;
    }
    return list;
}
//para mi casa sobrecargarla
void PrintOrder(DeliveryOrder* list){

    if (!list)
        return;
    else{
        cout << "\nNombre: \t" << list->DeliveryMenu.name << endl;
        cout << "ID: \t" << list->DeliveryMenu.idOrder << endl;
        cout << "Direccion... \t" << endl;
        cout << list->DeliveryAddress.department << ", " << list->DeliveryAddress.municipality << ", " << list->DeliveryAddress.settlement << ", " << list->DeliveryAddress.hNum << endl;

        cout << "Entradas: " << endl; 
        Print(list->DeliveryMenu.orStarter);
        cout << "Plato principal: " << endl;
        Print(list->DeliveryMenu.orDrink);
        cout << "Bebidas: " << endl;
        Print(list->DeliveryMenu.orDrink);
        cout << "Tipo de pago: "<< endl;
            switch (list->DeliveryMenu.Pay)
            {
            case Card:
                cout << "Tarjeta."; break;   
            case Cash: cout << "Efectivo."; break;
            }
            cout << endl;
            cout << "Total: ";
            cout << list->DeliveryMenu.total;
            cout << "Tiempo de espera: ";
            cout << list->DeliveryMenu.waitTime;
    }
    
}

void Print(MainD* list){
    if(!list)
        return;
    else{
        switch (list->element)
        {
        case Pizza:
            cout << "Pizza."; break;
        case Salad:
            cout << "Ensalada."; break;
        case Pasta:
            cout << "Pasta."; break;
        }
        cout << endl;
        Print(list->next);
    }
}

void Print(Drinks* list){
    if(!list)
        return;
    else{
        switch (list->element)
        {
        case Juice:
            cout << "Jugo."; break;
        case Soda:
            cout << "Soda."; break;
        case Tea:
            cout << "Te."; break;
        }
        cout << endl;
        Print(list->next);
    }
}

void Print(Starters* list){
    if(!list)
        return;
    else{
        switch (list->element)
        {
        case GarlicBread:
            cout << "Pan con ajo."; break;
        case FrenchFries:
            cout << "Papas fritas."; break;
        case CheeseSticks:
            cout << "Palitos de queso."; break;
        }
        cout << endl;
        Print(list->next);
    }
}

float PrintTotal(MainD* list){
    if(!list)
        return 0;
    else{
        return TotalM[int(list->element)] + PrintTotal(list->next);
    }
}

float PrintTotal(Drinks* list){
    if(!list)
        return 0;
    else{
        return TotalD[int(list->element)] + PrintTotal(list->next);
    }
}

float PrintTotal(Starters* list){
    if(!list)
        return 0;
    else{
        return TotalS[int(list->element)] + PrintTotal(list->next);
    }
    
}