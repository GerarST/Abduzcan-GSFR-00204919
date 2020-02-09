#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define PASSWORD "cin.clear"

//Comida.
enum Maindish {Pizza, Pasta, Lasagna};
enum Drink {Beer, Soda, Tea};
enum Starter {GarlicBread, PizzaRolls, CheeseSticks};

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
    MainD* orDish;
    Drinks* orDrink;
    Starters* orStarter;
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

struct Serve{
    DeliveryOrder* DeliveryC;
    RestOrder* RestC;
};

//Variables globales.
bool Admin = false;
int idOrder = 1;

const float PriceS[] = {3.99, 4.99, 3.75};
const float PriceM[] = {13.99, 5.55, 6.25};
const float PriceD[] = {1.99, 0.95, 1.15};

//Prototipos de funciones.
DeliveryOrder* AddOrder(DeliveryOrder* list);
DeliveryOrder* ServeOrder(DeliveryOrder* list, DeliveryOrder* next);
DeliveryOrder* pop(DeliveryOrder* list);
RestOrder* AddOrder(RestOrder* list);
RestOrder* ServeOrder(RestOrder* list, RestOrder* next);
RestOrder* pop(RestOrder* list);
MainD* AddFood(MainD* list, Maindish md);
Drinks* AddFood(Drinks* list, Drink d);
Starters* AddFood(Starters* list, Starter st);
bool login();
void printOptions();
void PrintOrder(DeliveryOrder* list);
void PrintOrder(RestOrder* list);
void DeleteOr(DeliveryOrder** list, int ID);
void DeleteOr(RestOrder** list, int ID);
void Print(MainD* list);
void Print(Drinks* list);
void Print(Starters* list);
float PrintTotal(MainD* list);
float PrintTotal(Drinks* list);
float PrintTotal(Starters* list);
float PrintTimeT(DeliveryOrder* list);
float PrintTimeT(RestOrder* list);


int main(){
    //Declaracion de variables.
    DeliveryOrder* D_Order = NULL;
    RestOrder* R_Order = NULL;
    MainD* MDish = NULL;
    Drinks* Drks = NULL; 
    Starters* St = NULL;
    Serve Order;
    Order.DeliveryC = NULL;
    Order.RestC = NULL; 
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
                D_Order = AddOrder(D_Order); break;
            // Agregar ordenes en restaurante
            case 2:
                R_Order = AddOrder(R_Order); break;
            // Ver ordenes a domicilio
            case 3:
                PrintOrder(D_Order); break;
            //Ver ordenes en restaurante
            case 4:
                PrintOrder(R_Order); break;
            //Despachar ordenes a domicilio
            case 5: 
                D_Order = ServeOrder(D_Order, Order.DeliveryC); pop(D_Order); break;
            //Despachar ordenes en restaurante
            case 6: 
                R_Order = ServeOrder(R_Order, Order.RestC); pop(R_Order); break;
            //Ver tiempo promedio de espera a domicilio
            case 7:  PrintTimeT(D_Order); break;
            //Ver tiempo promedio de espera en restaurante
            case 8: PrintTimeT(R_Order); break;
            //Cancelar orden(Domilio o restaurante, solo admin)
            case 9: 
                if(Admin){
                    if(R_Order->RestMenu.idOrder == idOrder || D_Order->DeliveryMenu.idOrder == idOrder){
                        if(!R_Order && !D_Order)
                            cout << "\n\tLa lista está vacía!";
                        else{
                            DeleteOr(&R_Order, idOrder); DeleteOr(&D_Order, idOrder);
                        }   
                    }
                }
                else
                    cout << "\n\t\tNo tiene los permisos requeridos \n\t\tpara realizar esta accion!";
                break;
            //Calcular total de ventas
            case 10: break;
            //Cambiar de usuario
            case 11: login(); break;
            case 12: return 0; break;
            default:
            break;
        }        

    }while(option != 12);

    return 0;
}

//Inicio de sesion
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
//Imprimir opciones principales
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

    //Inicio de bloque para DELIVERY...
DeliveryOrder* AddOrder(DeliveryOrder* list){
    DeliveryOrder* newOrder = new DeliveryOrder;
    
    newOrder->DeliveryMenu.orDish = NULL;
    newOrder->DeliveryMenu.orDrink = NULL;
    newOrder->DeliveryMenu.orStarter = NULL;
    newOrder->next = NULL;
    
    int aux = 0, auxSt = 0, auxDr = 0, auxMd = 0;
    char opcion;
    float time = 0;
    
    cout << "\t\tNombre completo:\t"; getline(cin, newOrder->DeliveryMenu.name);
    cout << "\tDireccion..." << endl;
    cout << "\t\tColonia:\t"; getline(cin, newOrder->DeliveryAddress.settlement);
    cout << "\t\tMunicipio:\t"; getline(cin, newOrder->DeliveryAddress.municipality);
    cout << "\t\tDepartamento:\t"; getline(cin, newOrder->DeliveryAddress.department);
    cout << "\t\tNo. casa:\t"; cin >> newOrder->DeliveryAddress.hNum;
    cin.ignore();

        do{

            cout << "\n\tEntrada" << endl;
            cout << "\t1 - Pan con ajo" << endl;
            cout << "\t2 - Papas Fritas" << endl;
            cout << "\t3 - Palitos de queso" << endl;
            cout << "\t4 - Salir.\n";
            cout << "\tSu opcion:\t"; cin >> aux;
            cin.ignore();

            if (aux != 4)
            {
                aux--;
                newOrder->DeliveryMenu.orStarter = AddFood(newOrder->DeliveryMenu.orStarter, Starter(aux));
                aux++; auxSt++;
            }
            
        }while(aux != 4);
         
        do{
            cout << "\n\tPlato principal" << endl;
            cout << "\t1 - Pizza" << endl;
            cout << "\t2 - Pasta" << endl;
            cout << "\t3 - EnLasagnaa" << endl;
            cout << "\t4 - Salir.\n";
            cout << "\tSu opcion:\t"; cin >> aux;
            cin.ignore();
            
            if (aux != 4)
            {
                aux--;
                newOrder->DeliveryMenu.orDish = AddFood(newOrder->DeliveryMenu.orDish, Maindish(aux));
                aux++; auxMd++;
            }

        }while(aux != 4);

        do{
            cout << "\n\tBebida" << endl;
            cout << "\t1 - Jugo" << endl;
            cout << "\t2 - Soda" << endl;
            cout << "\t3 - Te helado" << endl;
            cout << "\t4 - Salir.\n";
            cout << "\tSu opcion:\t"; cin >> aux;
            cin.ignore();
            
            if (aux != 4)
            {
                aux--;
                newOrder->DeliveryMenu.orDrink = AddFood(newOrder->DeliveryMenu.orDrink, Drink(aux));
                aux++; auxDr++;
            }

        }while(aux != 4);

        
    cout << "\n\tTipo de pago" << endl;
    cout << "\t1 - Tarjeta" << endl;
    cout << "\t2 - Efectivo" << endl;
    cout << "\tSu opcion:\t"; cin >> aux;
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

    cout << "\n\tTelefono: "; cin >> newOrder->cellphone;
    cin.ignore();

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

DeliveryOrder* ServeOrder(DeliveryOrder* list, DeliveryOrder* DeliveryC){
    DeliveryOrder* newOrder = new DeliveryOrder;

    newOrder->DeliveryMenu = list->DeliveryMenu;
    newOrder->DeliveryAddress = list->DeliveryAddress;
    newOrder->cellphone = list->cellphone;

    newOrder->next = DeliveryC;
    DeliveryC = newOrder;

    return DeliveryC;
}

DeliveryOrder* pop(DeliveryOrder* list){
    if(!list)
        return NULL;
    else
        return list->next;
}

void DeleteOr(DeliveryOrder** list, int ID){
    if(*list){
        if((*(*list)).DeliveryMenu.idOrder == ID){
            (*list) = (*(*list)).next;
        }
    }
    else
        DeleteOr(&(*(*list)).next, ID);
}

void PrintOrder(DeliveryOrder* list){

    if (!list)
        return;
    else{
        cout << "\n\t\t\tPIZZERIA ABDUZCAN EL SALVADOR.\n";
        cout << "\n\t\t\t   Av. LA REVOLUCION Y BOULVEVARD\n\t\t\tDEL HIPODROMO. NO. 222, SAN SALVADOR\n Telefono: 2790-7653";
        cout << "\tNombre: \t" << list->DeliveryMenu.name << endl;
        cout << "\tID: \t" << list->DeliveryMenu.idOrder << endl;
        cout << "\tDireccion... \t" << endl;
        cout << list->DeliveryAddress.department << ", " << list->DeliveryAddress.municipality << ", " << list->DeliveryAddress.settlement << ", " << list->DeliveryAddress.hNum << endl;
        
        cout << "\n-----------------------------\n";
        cout << "\tEntradas: " << endl; 
        Print(list->DeliveryMenu.orStarter);
        cout << "\tPlato principal: " << endl;
        Print(list->DeliveryMenu.orDrink);
        cout << "\tBebidas: " << endl;
        Print(list->DeliveryMenu.orDrink);
        cout << "\n-----------------------------\n";

        cout << "\tTipo de pago: "<< endl;
            switch (list->DeliveryMenu.Pay)
            {
            case Card: cout << "\tTarjeta.";  break;   
            case Cash: cout << "\tEfectivo."; break;
            }
        cout << endl;
        cout << "\tSubTotal General: \t";
        cout << list->DeliveryMenu.total;
        cout << "\n\tTiempo de espera: ";
        cout << list->DeliveryMenu.waitTime;
        cout << "\n-----------------------------\n";
    }
    
}

float PrintTimeT(DeliveryOrder* list){
    if(!list)
        return 0;
    else{
        return list->DeliveryMenu.waitTime + PrintTimeT(list->next);
    }
}
//Fin de bloque para DELIVERY||

    //Inicio de bloque para RESTAURANT...
RestOrder* AddOrder(RestOrder* list){
    RestOrder* newOrder = new RestOrder;
    newOrder->next = NULL;

    int aux = 0, auxSt = 0, auxDr = 0, auxMd = 0;
    char opcion;
    float time = 0;
    
    cout << "Nombre completo:\t"; getline(cin, newOrder->RestMenu.name);
    cout << "Personas por mesa:\t"; cin >> newOrder->Persons; cin.ignore();
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
            cout << "3 - EnLasagnaa" << endl;
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

    newOrder->RestMenu.idOrder = idOrder++;

    time = (auxSt * 1.10 + auxMd * 1.5 + auxDr * 1.35) + 15;
    newOrder->RestMenu.waitTime = time; 
    
    newOrder->RestMenu.total = PrintTotal(list->RestMenu.orDish) + PrintTotal(list->RestMenu.orDrink) + PrintTotal(list->RestMenu.orStarter);


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

RestOrder* ServeOrder(RestOrder* list, RestOrder* RestC){
    RestOrder* newOrder = new RestOrder;

    newOrder->RestMenu = list->RestMenu;
    newOrder->Persons = list->Persons;

    newOrder->next = RestC;
    RestC = newOrder;

    return RestC;
}

RestOrder* pop(RestOrder* list){
    if(!list)
        return NULL;
    else
        return list->next;
}

void DeleteOr(RestOrder** list, int ID){
    if(*list){
        if((*(*list)).RestMenu.idOrder == ID){
            (*list) = (*(*list)).next;
        }
    }
    else
        DeleteOr(&(*(*list)).next, ID);
}

void PrintOrder(RestOrder* list){

    if (!list)
        return;
    else{
        cout << "\nNombre: \t" << list->RestMenu.name << endl;
        cout << "ID: \t" << list->RestMenu.idOrder << endl;

        cout << "Entradas: " << endl; 
        Print(list->RestMenu.orStarter);
        cout << "Plato principal: " << endl;
        Print(list->RestMenu.orDrink);
        cout << "Bebidas: " << endl;
        Print(list->RestMenu.orDrink);
        cout << "Tipo de pago: "<< endl;
            switch (list->RestMenu.Pay)
            {
            case Card:
                cout << "Tarjeta."; break;   
            case Cash: cout << "Efectivo."; break;
            }
            cout << endl;
            cout << "Total: ";
            cout << list->RestMenu.total;
            cout << "Tiempo de espera... ";
            cout << list->RestMenu.waitTime;
            cout << endl;
    }
    
}

float PrintTimeT(RestOrder* list){
    if(!list)
        return 0;
    else{
        return list->RestMenu.waitTime + PrintTimeT(list->next);
    }
}
//Fin de bloque para RESTAURANT||

    //Funciones Divide and Conquer...
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
//Funciones Divide and Conquer||

    //Funciones Print...
void Print(MainD* list){
    if(!list)
        return;
    else{
        switch (list->element)
        {
        case Pizza:
            cout << "Pizza."; break;
        case Lasagna:
            cout << "EnLasagnaa."; break;
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
        case Beer:
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
        case PizzaRolls:
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
        return PriceM[int(list->element)] + PrintTotal(list->next); 
    }
}

float PrintTotal(Drinks* list){
    if(!list)
        return 0;
    else{
        return PriceD[int(list->element)] + PrintTotal(list->next);
    }
}

float PrintTotal(Starters* list){
    if(!list)
        return 0;
    else{
        return PriceS[int(list->element)] + PrintTotal(list->next);
    }
    
}