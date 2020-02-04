#include <iostream>
#include <string>
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
    Maindish* orDish;
    Drink* orDrink;
    Starter* orStarter;
    PayType Pay;
    int idOrder;
    float total;
    float time;
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
//Prototipos de funciones.
bool login();
void printOptions();
DeliveryOrder* AddOrder(DeliveryOrder* list);
RestOrder* AddOrder(RestOrder* list);
MainD* AddFood(MainD* list, Maindish md);
Drinks* AddFood(Drinks* list, Drink d);
Starters* AddFood(Starters* list, Starter st);
void PrintOrder(DeliveryOrder* Array);

int main(){
    //Declaracion de variables y arreglos.
    DeliveryOrder* D_Array = NULL;
    RestOrder* R_Array = NULL;
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
                AddOrderD(D_Array);
            break;
            // Agregar ordenes en restaurante
            case 2:
                //AddOrder(R_Array);
            break;
            case 3:
                PrintOrderD(D_Array);
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

    int aux = 0;
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
        }while(aux != 4);

        /*if(aux == 1)
            Array[i].DeliveryMenu.orDish = Pizza;
        else if(aux == 2)
            Array[i].DeliveryMenu.orDish = Pasta;
        else
            Array[i].DeliveryMenu.orDish = Salad;*/
        do{
            cout << "Bebida" << endl;
            cout << "1 - Jugo" << endl;
            cout << "2 - Soda" << endl;
            cout << "3 - Te helado" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();
        }while(aux != 4);

        /*if(aux == 1)
            newOrder->DeliveryMenu.orDrink = Juice;
        else if(aux == 2)
            Array[i].DeliveryMenu.orDrink = Soda;
        else
            Array[i].DeliveryMenu.orDrink = Tea;

        Array[i].DeliveryMenu.idOrder = idOrder++;*/

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

    newOrder->DeliveryMenu.idOrder = idOrder++;

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
        }while(aux != 4);

        /*if(aux == 1)
            newOrder->DeliveryMenu.orStarter = GarlicBread;
        else if(aux == 2)
            newOrder->DeliveryMenu.orStarter = FrenchFries;
        else
            newOrder->DeliveryMenu.orStarter = CheeseSticks;*/
        do{
            cout << "Plato principal" << endl;
            cout << "1 - Pizza" << endl;
            cout << "2 - Pasta" << endl;
            cout << "3 - Ensalada" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();
        }while(aux != 4);

        /*if(aux == 1)
            Array[i].DeliveryMenu.orDish = Pizza;
        else if(aux == 2)
            Array[i].DeliveryMenu.orDish = Pasta;
        else
            Array[i].DeliveryMenu.orDish = Salad;*/
        do{
            cout << "Bebida" << endl;
            cout << "1 - Jugo" << endl;
            cout << "2 - Soda" << endl;
            cout << "3 - Te helado" << endl;
            cout << "4 - Salir.\n";
            cout << "Su opcion:\t"; cin >> aux;
            cin.ignore();
        }while(aux != 4);

        /*if(aux == 1)
            newOrder->DeliveryMenu.orDrink = Juice;
        else if(aux == 2)
            Array[i].DeliveryMenu.orDrink = Soda;
        else
            Array[i].DeliveryMenu.orDrink = Tea;

        Array[i].DeliveryMenu.idOrder = idOrder++;*/

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
