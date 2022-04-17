#include <iostream>


using namespace std;

/*
crear menu y corregir
*/
class calculadora{
    protected:
    int num1;
    int num2;
    float total;
    
    public:
    void ingresar_numero1();
    void ingresar_numero2();
    void resultado();
};

class suma: public calculadora{
    public:
    void formula1();
};

class resta: public calculadora{
    public:
    void formula2();
};

class multiplicar: public calculadora{
    public:
    void formula3();
};

class dividir: public calculadora{
    public:
    void formula4();
};

void calculadora::ingresar_numero1(){
    cout << "Ingresar primer valor: ";
    cin >> num1;
}

void calculadora::ingresar_numero2(){
    cout << "Ingresar segundo valor: ";
    cin >> num2;
}

void suma::formula1(){
    total= num1+num2;
}

void resta::formula2(){
    total= num1-num2;
}

void multiplicar::formula3(){
    total= num1*num2;
}

void dividir::formula4(){
    while (num2==00){
        cout << "El segundo valor no puede ser 0 favor de corregirlo.";
        ingresar_numero2();
    }  
    total= num1/num2;
}

void calculadora::resultado(){
    cout <<total<<endl;
}

void terminar(){
    cout << "Que tenga un buen dia."<<endl;
};

class menusett: public suma, public resta, public multiplicar, public dividir{
    protected:
    int o;

    public:
    void menu();
    void seguir();
};

void menusett::seguir(){
    int opcion;
    cout << "Desea continuar? \n1. Si \n2. No"<<endl;
    cin >> opcion;
     if (opcion == 1){
        menu();
     }if (opcion == 2){
        terminar();
     }else{     
        cout << "Opcion invalida favor de volver a intentarlo."<<endl;
        seguir();
     }
};

void menusett::menu(){

    cout << "Que operacion desea hacer? \n1. Suma \n2. Resta \n3. Multiplicar \n4. Dividir \n5. Salir"<<endl;
        cin >>o;

    switch (o){
    case 1:
        suma::ingresar_numero1();
        suma::ingresar_numero2();
        formula1();
        cout << "El resultado es: "<<endl;
        suma::resultado();
        seguir();
        system("cls");
        break;
    
    case 2:
        resta::ingresar_numero1();
        resta::ingresar_numero2();
        formula2();
        cout << "El resultado es: "<<endl;
        resta::resultado();
        seguir();
        system("cls");
        break;

    case 3:
        multiplicar::ingresar_numero1();
        multiplicar::ingresar_numero2();
        formula3();
        cout << "El resultado es: "<<endl;
        multiplicar::resultado();
        seguir();
        system("cls");
        break;

    case 4:
        dividir::ingresar_numero1();
        dividir::ingresar_numero2();
        formula4();
        cout << "El resultado es: "<<endl;
        dividir::resultado();
        seguir();
        system("cls");
        break;

    case 5:
        terminar();
        break;

    default:
        cout << "Opcion invalida favor de volver a intentarlo."<<endl;
        menu();
        break;
    }
};

int main(){
    menusett menus;

    menus.menu();
    
    
    return 0;
}