/*
*Proyecto brazo robotico
*Jesús Misael Reséndiz Cruz
*A01706166
*
*Proyecto que simula el movimiento de un brazo robotico de 4 ejes, 
*tiene la opcion de guardar posiciones y actualizarlas para guardar hasta 3 tipos
*de cajas que se encuentran en diferentes espacios tridimencionales, cada tipo de caja puede contener
* hasta la cantidad de 3. Este robot tambien puede ser manupulado manualmente con comandos de la consola.
*/

#include <iostream>
#include <string> //usar variables tipo string
#include <sstream> //usar istringstream para convertir cadena a entero
#include <windows.h> // usar Sleep()
using namespace std;
#include "Cajas.h" //llamo mi clase Cajas 
#include "Robots.h"

Robots Brazo;
Cajas cajVerdes(0); //inicializo mis 3 cajas (objetos) de clase Cajas, con cantidad inicial de 0 cajas cada una
Cajas cajRojas(0);
Cajas cajAmarillas(0);

 //variables globales
int posiSer1[9],posiSer2[9],posiSer3[9],posiSer4[9];

string quitarChar(string cade, int cont);       //funciones prototipo inicializados en esta parte del programa
void recopilarPosiciones(int c);
void menu();

int main(){
	
	Brazo.set_cajasVerdes(cajVerdes);
	Brazo.set_cajasRojas(cajRojas);          //envío objetos de tipo Cajas al objeto creado de tipo Robots (Cajas son atributos de Robots)
	Brazo.set_cajasAmarillas(cajAmarillas);
	
	int S3P1=0,S3P2=1,S3P3=2,S3P4=3; //variables que obtienen los angulos especificos para cada matriz de angulos  
	int S2P1=5,S2P2=6,S2P3=7,S2P4=8;//
	int temperatura2=Brazo.get_temperaturaServo2();   // inicializo mis variables temperatura para los servos 2 y 3 que comunmete son afectados por este factor
	int temperatura3=Brazo.get_temperaturaServo3();   //
	char inchar;    //acumulador de caracteres para el swith
	string cadena=""; //cadena de caracteres para el swith
	int count=0,num;
	menu();
	while(true){   //ciclo while simulando un microcontrolador 
		cin>>inchar;           //ingreso mi texto en la pantalla dependiendo de lo que quiero que se active del swith
		if(inchar=='q')break;
		count++;
		cadena+=inchar;     //entra al swith hasta que sea algun caracter del menu
		switch (inchar){   
			case 's':	
				menu();    //vuelo a mostrar mi menú
				cadena="";
				count=0;
				break;
			case 'a':                       
				Brazo.servo1Aumenta();
				cout<<"Angulo servo1: "<<Brazo.get_anguloServo1()<<endl;
				cadena="";
				count=0;                //case que me permite mover el servo1 en incrementos de 1 en 1
				break;
			case 'b':
				Brazo.servo1Disminuye();
				cout<<"Angulo servo1: "<<Brazo.get_anguloServo1()<<endl;
				cadena=""; 
				count=0;              //case que me permite mover el servo 1 en decrementos de 1 en 1
				break; 
			case 'c':
				Brazo.servo2Aumenta();
				cout<<"Angulo servo2: "<<Brazo.get_anguloServo2()<<endl;
				cadena="";
				count=0;                   //case que me permite mover el servo2 en incrementos de 1 en 1
				break;
			case 'd':
				Brazo.servo2Disminuye();
				cout<<"Angulo servo2: "<<Brazo.get_anguloServo2()<<endl;
				cadena="";
				count=0;                            //case que me permite mover el servo 2 en decrementos de 1 en 1
				break; 
			case 'e':
				Brazo.servo3Aumenta();
				cout<<"Angulo servo3: "<<Brazo.get_anguloServo3()<<endl;
				cadena="";
				count=0;                  //case que me permite mover el servo3 en incrementos de 1 en 1
				break;
			case 'f':
				Brazo.servo3Disminuye();
				cout<<"Angulo servo3: "<<Brazo.get_anguloServo3()<<endl;
				cadena="";                             //case que me permite mover el servo 3 en decrementos de 1 en 1
				count=0;
				break;
			case 'g':
				Brazo.servo4Aumenta();
				cout<<"Angulo servo4: "<<Brazo.get_anguloServo4()<<endl;
				cadena="";
				count=0;                              //case que me permite mover el servo 4 en incrementos de 1 en 1
				break;
			case 'h':
				Brazo.servo4Disminuye();
				cout<<"Angulo servo4: "<<Brazo.get_anguloServo4()<<endl;
				cadena="";                                   //case que me permite mover el servo 4 en decrementos de 1 en 1
				count=0;
				break;
			case ',':
				cadena=quitarChar(cadena,count);    //quita el ultimo elemento de la cadena, 
				istringstream(cadena)>>num;                   //quedandose con el puro numero
				Brazo.set_CantidadCajasVerdes(num);               //posteriormente para insertarlo en el atributo de cantidad de 
				cout<<"Cajas verdes introducidas: "<<Brazo.get_CantidadCajasVerdes()<<endl;        //cajas verdes a guardar
				count=0;
				cadena="";
				break;
			case '=':
				cadena=quitarChar(cadena,count); //mismo proceso para cajas rojas 
				istringstream(cadena)>>num;        
				Brazo.set_CantidadCajasRojas(num);        
				cout<<"Cajas Rojas introducidas: "<<Brazo.get_CantidadCajasRojas()<<endl; 
				count=0;
				cadena="";
				break;
			case '/':
				cadena=quitarChar(cadena,count);  //mismo proceso para cajas amarillas
				istringstream(cadena)>>num;        
				Brazo.set_CantidadCajasAmarillas(num);     
				cout<<"Cajas amarillas introducidas: "<<Brazo.get_CantidadCajasAmarillas()<<endl;   
				count=0;
				cadena="";
				break;
			case 'i':
				S2P1=Brazo.get_anguloServo2();   //obtengo los angulos de la posicion 1 de mi brazo para cualquier caja a guardar
				S3P1=Brazo.get_anguloServo3();
				cout<<"Posicion 1 pre-guardada para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			case 'j':
				S2P2=Brazo.get_anguloServo2();    //este me sirve para guardar de la posicion 2 a la posicion 4 de mi brazo, 2 3 y 4 comparten 
				S3P2=Brazo.get_anguloServo3();    //estos mismos angulos
				cout<<"Posiciones 2, 3 y 4 pre-guardadas para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			case 'k':
				S2P3=Brazo.get_anguloServo2();   //este me sirve para guardar de la posicion 5 a la posicion 6 de mi brazo, 5 y 6 comparten 
				S3P3=Brazo.get_anguloServo3();   //estos mismos angulos
				cout<<"Posiciones 5 y 6 pre-guardadas para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			case 'l':
				S2P4=Brazo.get_anguloServo2(); //este me sirve para guardar de la posicion 7 a la posicion 8 de mi brazo, 7 y 8 comparten 
				S3P4=Brazo.get_anguloServo3();   //estos mismos angulos
				cout<<"Posiciones 7 y 8 pre-guardadas para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			case 'm':
				Brazo.set_particular_PosicionesServo2(S2P1,S2P2,S2P3,S2P4);
				Brazo.set_particular_PosicionesServo3(S3P1,S3P2,S3P3,S3P4);   // Mando a guardar atributo de posicion para restableces mis nuevas
				cout<<"Posiciones guardadas para los servos 2 y 3."<<endl;		//posiciones
				count=0;                                                     
				cadena="";
				break;
			case '%':
				cadena=quitarChar(cadena,count);     //funcion que me quita el ultimo elemento de la cadena, 
				istringstream(cadena)>>num;          //quedandonme con el puro numero
				Brazo.set_limiteAberturaServo4(num);  //asigno el angulo maximo de abertura para mi mano
				cout<<"Limite de abertura para servo 4: "<<Brazo.get_limiteAberturaServo4()<<endl;   //cajas rojas a guardar
				count=0;
				cadena="";
				break;
			case '#':
				cadena=quitarChar(cadena,count);     //funcion que me quita el ultimo elemento de la cadena, 
				istringstream(cadena)>>num;          //quedandonme con el puro numero
				Brazo.set_limiteCerraduraServo4(num);  //asigno el angulo limite de cerradura para mi mano
				cout<<"Limite de cerradura para servo 4: "<<Brazo.get_limiteCerraduraServo4()<<endl;   //cajas rojas a guardar
				count=0;
				cadena="";
				break;
			case 'n':
				recopilarPosiciones(0);                               //refresco mis posiciones antes de ejecutar el algoritmo de guardado
				if(Brazo.get_CantidadCajasVerdes()>0 and Brazo.get_temperaturaServo2()<100 and Brazo.get_temperaturaServo3()<100 and Brazo.get_limiteCerraduraServo4()>10 and Brazo.get_limiteAberturaServo4()<60){  //si hay algo que guardar de las cajas verdes 
					cout<<endl<<endl<<"                   Guardando "<<Brazo.get_CantidadCajasVerdes()<<" cajas verdes..."<<endl<<endl;
					cout<<"               Servo1:"<<"        Servo2:"<<"     Servo3:"<<"       Servo4:"<<endl;
					for(int i=0;i<Brazo.get_CantidadCajasVerdes();i++){     //que lo ejecute la cantidad de veces propuestas
						for(int j=0;j<9;j++){                          //con las 9 posiciones necesarias para guardar una sola caja
							Brazo.set_anguloServo1(posiSer1[j]);
							Brazo.set_anguloServo2(posiSer2[j]);
							Brazo.set_anguloServo3(posiSer3[j]);
							Brazo.set_anguloServo4(posiSer4[j]);    
							cout<<"Posicion "<<j+1<<":        "<<Brazo.get_anguloServo1()<<"            "<<Brazo.get_anguloServo2()<<"            "<<Brazo.get_anguloServo3()<<"            "<<Brazo.get_anguloServo4()<<endl;
							Sleep(1000); // un segundo por movimiento 
						}
					}
					cout<<endl<<endl<<"                     Listo!"<<endl;
					Brazo.set_temperaturaServo2(temperatura2++);  //incrementa la temperatura por movimiento de los servos
					Brazo.set_temperaturaServo3(temperatura3++);
				}
				count=0;             
				cadena="";
				break;
			case 'o':
				recopilarPosiciones(1);                               //refresco mis posiciones antes de ejecutar el algoritmo de guardado
				if(Brazo.get_CantidadCajasRojas()>0 and Brazo.get_temperaturaServo2()<100 and Brazo.get_temperaturaServo3()<100 and Brazo.get_limiteCerraduraServo4()>10 and Brazo.get_limiteAberturaServo4()<60){  //si hay algo que guardar de las cajas rojas 
					cout<<endl<<endl<<"                   Guardando "<<Brazo.get_CantidadCajasRojas()<<" cajas rojas..."<<endl<<endl;
					cout<<"               Servo1:"<<"        Servo2:"<<"     Servo3:"<<"       Servo4:"<<endl;
					for(int i=0;i<Brazo.get_CantidadCajasRojas();i++){     //que lo ejecute la cantidad de veces propuestas
						for(int j=0;j<9;j++){                          //con las 9 posiciones necesarias para guardar una sola caja
							Brazo.set_anguloServo1(posiSer1[j]);
							Brazo.set_anguloServo2(posiSer2[j]);
							Brazo.set_anguloServo3(posiSer3[j]);
							Brazo.set_anguloServo4(posiSer4[j]);    
							cout<<"Posicion "<<j+1<<":        "<<Brazo.get_anguloServo1()<<"            "<<Brazo.get_anguloServo2()<<"            "<<Brazo.get_anguloServo3()<<"            "<<Brazo.get_anguloServo4()<<endl;
							Sleep(1000); // un segundo por movimiento 
						}
					}
					cout<<endl<<endl<<"                     Listo!"<<endl;
					Brazo.set_temperaturaServo2(temperatura2++);
					Brazo.set_temperaturaServo3(temperatura3++);  //incrementa la temperatura por movimiento de los servos
				}
				count=0;                                                    
				cadena="";
				break;
			case 'p':
				recopilarPosiciones(2);                               //refresco mis posiciones antes de ejecutar el algoritmo de guardado
				if(Brazo.get_CantidadCajasAmarillas()>0 and Brazo.get_temperaturaServo2()<100 and Brazo.get_temperaturaServo3()<100 and Brazo.get_limiteCerraduraServo4()>10 and Brazo.get_limiteAberturaServo4()<60){   //si hay algo que guardar de las cajas amarillas 
					cout<<endl<<endl<<"                   Guardando "<<Brazo.get_CantidadCajasAmarillas()<<" cajas amarillas..."<<endl<<endl;
					cout<<"               Servo1:"<<"        Servo2:"<<"     Servo3:"<<"       Servo4:"<<endl;
					for(int i=0;i<Brazo.get_CantidadCajasAmarillas();i++){     //que lo ejecute la cantidad de veces propuestas
						for(int j=0;j<9;j++){                          //con las 9 posiciones necesarias para guardar una sola caja
							Brazo.set_anguloServo1(posiSer1[j]);
							Brazo.set_anguloServo2(posiSer2[j]);
							Brazo.set_anguloServo3(posiSer3[j]);
							Brazo.set_anguloServo4(posiSer4[j]);    //itero mis apuntadores 
							cout<<"Posicion "<<j+1<<":        "<<Brazo.get_anguloServo1()<<"            "<<Brazo.get_anguloServo2()<<"            "<<Brazo.get_anguloServo3()<<"            "<<Brazo.get_anguloServo4()<<endl;
							Sleep(1000); // un segundo por movimiento 
						}
					}
					cout<<endl<<endl<<"                     Listo!"<<endl;
					Brazo.set_temperaturaServo2(temperatura2++);
					Brazo.set_temperaturaServo3(temperatura3++);  //incrementa la temperatura por movimiento de los servos
				}
				count=0;                                                    
				cadena="";
				break;
		}
	}
	Brazo.goHome();
	cout<<"adios";
	return 0;
} // end main
string quitarChar(string cade, int cont){  //funcion que me elimina el ultimo caracter de mi cadena
	string cad="";
	for(int i=0;i<cont-1;i++){
		cad=cad+cade[i];
	}
	return cad;
}
void recopilarPosiciones(int c){ //columna c donde se encuentran los 9 valores para el servo X que almacena poscicion
	for(int f=0;f<9;f++){
		posiSer1[f]=Brazo.get_particular_PosicionesServo1(f,c);
		posiSer2[f]=Brazo.get_particular_PosicionesServo2(f,c);
		posiSer3[f]=Brazo.get_particular_PosicionesServo3(f,c);
		posiSer4[f]=Brazo.get_particular_PosicionesServo4(f,c);
	}
}
void menu(){
	cout<<"       Menu: \n";
	cout<<"'a' Incrementa 1 grado servomotor 1 (base).\n";
	cout<<"'b' Decrementa 1 grado servomotor 1 (base).\n";
	cout<<"'c' Incrementa 1 grado servomotor 2 (articulacion 1).\n";
	cout<<"'d' Decrementa 1 grado servomotor 2 (articulacion 1).\n";
	cout<<"'e' Incrementa 1 grado servomotor 3 (articulacion 2).\n";
	cout<<"'f' Decrementa 1 grado servomotor 3 (articulacion 2).\n";
	cout<<"'g' Incrementa 1 grado servomotor 4 (mano).\n";
	cout<<"'h' Decrementa 1 grado servomotor 4 (mano).\n";
	cout<<"'<numero>'+',' Cantidad de cajas verdes.\n";
	cout<<"'<numero>'+'=' Cantidad de cajas Rojas.\n";
	cout<<"'<numero>'+'/' Cantidad de cajas Amarillas.\n";
	cout<<"'i' Pre-guardar posicion 1 para servos 2 y 3.\n";
	cout<<"'j' Pre-guardar posiciones 2, 3 y 4 para servos 2 y 3.\n";
	cout<<"'k' Pre-guardar posiciones 5 y 6 para servos 2 y 3.\n";
	cout<<"'l' Pre-guardar posiciones 7 y 8 para servos 2 y 3.\n";
	cout<<"'m' Guardar posiciones pre-guardadas para los servos 2 y 3.\n";
	cout<<"'<numero>'+'%' Asignacion de abertura limite de la mano del robot.\n";
	cout<<"'<numero>'+'#' Asignacion de cerradura limite de la mano del robot.\n";
	cout<<"'n' Guardar cajas verdes en los contenedores.\n";
	cout<<"'o' Guardar cajas rojas en los contenedores.\n";
	cout<<"'p' Guardar cajas amarillas en los contenedores.\n";
	cout<<"'s' VOLVER A MOSTRAR EL MENU.\n";
	cout<<"'q' Salir del programa.\n";
}