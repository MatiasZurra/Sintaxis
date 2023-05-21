#include<iostream>
#include<math.h>
#include<string.h>
#include<time.h>

#define M 20        //Maximo valor de n para la cadena aleatoria
#define m 1			//Minimo valor de n para la cadena aleatoria
using namespace std;

void Mostrarmenu(void);

void analizar_cadena();
void analizar_cadena_pap();
string darCadenaEjemplo();

int main(){
	int OpcMenu=0;
	while(OpcMenu!=5){
		system("cls");					
		Mostrarmenu();
		cin>>OpcMenu;
		switch(OpcMenu){						
			case 1:{
				cout<<"El lenguaje a utilizar es: L = { a^n b^(2n) | n > 0}"<<endl;
				system("PAUSE");		
				break;
			}
			case 2:{
				analizar_cadena();
				system("PAUSE");
				break;
			}
			case 3:{
				analizar_cadena_pap();
				system("PAUSE");
				break;
			}
			case 4:{
				string cadenaEjemplo = darCadenaEjemplo();
                cout << "Cadena de ejemplo: " << cadenaEjemplo << endl;
                system("PAUSE");
				break;
			}
			case 5:{
				printf("\nADIOS");
				break;
			}
			default:{
				printf("\nNO SEAS ZAPALLO ELEGI UNA OPCION VALIDA\n");
				system("PAUSE");
				break;
			}
		}
		
	}
}
void Mostrarmenu(void){
	printf("\n1: MOSTRAR EL LENGUAJE\n");
	printf("\n2: ANALIZAR CADENA COMPLETA\n");
	printf("\n3: ANALIZAR CADENA PASO A PASO\n");
	printf("\n4: DAR UNA CADENA DE EJEMPLO\n");
	printf("\n5: SALIR\n");
		
}


void analizar_cadena() {
	fflush(stdin);
    std::string palabra;
    std::cout << "Ingrese una palabra: ";
    std::getline(std::cin, palabra);

    int cont = 0;
    for (char letra : palabra) {
        if (letra == 'a') {
            cont++;
        } else {
            break;
        }
    }

    std::string palabraesperada = std::string(cont, 'a') + std::string(2 * cont, 'b');

    if (palabraesperada == palabra && palabra.length() != 0) {
        std::cout << "\nLa palabra ingresada pertenece al Lenguaje" << std::endl;
    } else {
        std::cout << "\nLa palabra ingresada no pertenece al Lenguaje" << std::endl;
    }
}


void analizar_cadena_pap() {
    std::string palabra = "";
    int cant_a = 0;
    int cant_b = 0;

    while (true) {
    	fflush(stdin);
        std::cout << "Ingrese un caracter (presione Enter para finalizar): ";
        char caracter;
        std::cin.get(caracter);

        if (caracter == '\n') {
            if (!palabra.empty() && 2 * cant_a == cant_b) {
                std::cout << "\nLa palabra: " << palabra << ", pertenece al Lenguaje" <<std::endl;
            } else {
                std::cout << "\nLa palabra ingresada no pertenece al Lenguaje" << std::endl;
            }
            return;
        } else if (caracter != 'a' && caracter != 'b') {
            std::cout << "\nLa palabra ingresada no pertenece al Lenguaje" << std::endl;
            return;
        } else {
            if (caracter == 'a' && palabra.find('b') == std::string::npos) {
                cant_a++;
                palabra += caracter;
            } else if (caracter == 'b' && (cant_b / 2 < cant_a) && (cant_a > 0)) {
                cant_b++;
                palabra += caracter;
            } else {
                std::cout << "\nLa palabra ingresada no pertenece al Lenguaje" << std::endl;
                return;
            }
        }
    }
}


string darCadenaEjemplo() {
    srand(time(NULL));
    int n =rand()% (M-m+1)+m; // Generar un valor aleatorio entre 1 y 50
    string cadenaEjemplo = "";


    for (int i = 0; i < n; i++)    // Generar n veces 'a' (n + 1) veces
        cadenaEjemplo += 'a';
          
    for (int i = 0; i < (2 * n); i++)    // Generar (2 * n) veces 'b'
		cadenaEjemplo += 'b';
 
	return cadenaEjemplo;
}
