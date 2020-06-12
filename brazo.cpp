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
//Librerias necesarias
#include <iostream>
#include <string> 
#include <sstream> 
#include <windows.h> 
using namespace std;
// Llamar a la clases a instanciar
#include "Cajas.h" 
#include "Robots.h"

//Instanciamiento de las clases 
Robots Brazo;
//Se inicializan 3 tipos de cajas con cantidad inicial
Cajas cajVerdes(0); 
Cajas cajRojas(0);
Cajas cajAmarillas(0);

 //Variables globales
int posiSer1[9],posiSer2[9],posiSer3[9],posiSer4[9];

// Prototipo funciones
string quitarChar(string cade, int cont);       
void recopilarPosiciones(int c);
void menu();

int main(){
	
	//Envío de objetos de tipo Cajas al objeto creado de tipo Robots.
	Brazo.set_cajasVerdes(cajVerdes);
	Brazo.set_cajasRojas(cajRojas);          
	Brazo.set_cajasAmarillas(cajAmarillas);
	
	// Declaracion de variables locales
	int S3P1=0,S3P2=1,S3P3=2,S3P4=3; 
	int S2P1=5,S2P2=6,S2P3=7,S2P4=8;
	char inchar;   
	string cadena=""; 
	int count=0,num;
	
	// Se mandan la temeraturas iniciales
	int temperatura2=Brazo.get_temperaturaServo2();   
	int temperatura3=Brazo.get_temperaturaServo3();  
	
	// Se muestra el menu de operacion
	menu();
	
	//Ciclo while simulando un microcontrolador 
	while(true){   
		// Ingreso del caracter que pide el menu
		cin>>inchar;

		if(inchar=='q')break;
		count++;
		//Entra al swith hasta que sea algun caracter del menu
		cadena+=inchar;     
		switch (inchar){ 
			// Velve a mostrar mi menú
			case 's':	
				menu();    
				cadena="";
				count=0;
				break;
			//Mover el servo1 en incrementos de 1 en 1
			case 'a':                       
				Brazo.servo1Aumenta();
				cout<<"Angulo servo1: "<<Brazo.get_anguloServo1()<<endl;
				cadena="";
				count=0;                
				break;
			//Mueve el servo 1 en decrementos de 1 en 1
			case 'b':
				Brazo.servo1Disminuye();
				cout<<"Angulo servo1: "<<Brazo.get_anguloServo1()<<endl;
				cadena=""; 
				count=0;            
				break; 
			//Mover el servo2 en incrementos de 1 en 1
			case 'c':
				Brazo.servo2Aumenta();
				cout<<"Angulo servo2: "<<Brazo.get_anguloServo2()<<endl;
				cadena="";
				count=0;                  
				break;
			//Mueve el servo 2 en decrementos de 1 en 1
			case 'd':
				Brazo.servo2Disminuye();
				cout<<"Angulo servo2: "<<Brazo.get_anguloServo2()<<endl;
				cadena="";
				count=0;                            
				break; 
			//Mover el servo3 en incrementos de 1 en 1
			case 'e':
				Brazo.servo3Aumenta();
				cout<<"Angulo servo3: "<<Brazo.get_anguloServo3()<<endl;
				cadena="";
				count=0;                
				break;
			//Mueve el servo 3 en decrementos de 1 en 1
			case 'f':
				Brazo.servo3Disminuye();
				cout<<"Angulo servo3: "<<Brazo.get_anguloServo3()<<endl;
				cadena="";                            
				count=0;
				break;
			//Mover el servo4 en incrementos de 1 en 1
			case 'g':
				Brazo.servo4Aumenta();
				cout<<"Angulo servo4: "<<Brazo.get_anguloServo4()<<endl;
				cadena="";
				count=0;                             
				break;
			//Mueve el servo 4 en decrementos de 1 en 1
			case 'h':
				Brazo.servo4Disminuye();
				cout<<"Angulo servo4: "<<Brazo.get_anguloServo4()<<endl;
				cadena="";                                   
				count=0;
				break;
			// Quita el ultimo elemento de la cadena, despues lo inserta a la cantidad de cajas verdes a guardar
			case ',':
				cadena=quitarChar(cadena,count);  
				istringstream(cadena)>>num;           
				Brazo.set_CantidadCajasVerdes(num);               
				cout<<"Cajas verdes introducidas: "<<Brazo.get_CantidadCajasVerdes()<<endl;        
				count=0;
				cadena="";
				break;
			// Quita el ultimo elemento de la cadena, despues lo inserta a la cantidad de cajas rojas a guardar
			case '=':
				cadena=quitarChar(cadena,count); 
				istringstream(cadena)>>num;        
				Brazo.set_CantidadCajasRojas(num);        
				cout<<"Cajas Rojas introducidas: "<<Brazo.get_CantidadCajasRojas()<<endl; 
				count=0;
				cadena="";
				break;
			// Quita el ultimo elemento de la cadena, despues lo inserta a la cantidad de cajas amarillas a guardar
			case '/':
				cadena=quitarChar(cadena,count);  
				istringstream(cadena)>>num;        
				Brazo.set_CantidadCajasAmarillas(num);     
				cout<<"Cajas amarillas introducidas: "<<Brazo.get_CantidadCajasAmarillas()<<endl;   
				count=0;
				cadena="";
				break;
			//Se obtiene los angulos de la posicion 1 de mi brazo para cualquier caja a guardar
			case 'i':
				S2P1=Brazo.get_anguloServo2();   
				S3P1=Brazo.get_anguloServo3();
				cout<<"Posicion 1 pre-guardada para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			//Guarda la posicion 2 a la posicion 4 del brazo
			case 'j':
				S2P2=Brazo.get_anguloServo2();    
				S3P2=Brazo.get_anguloServo3();   
				cout<<"Posiciones 2, 3 y 4 pre-guardadas para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			//Guarda la posicion 5 a la posicion 6 del brazo
			case 'k':
				S2P3=Brazo.get_anguloServo2();  
				S3P3=Brazo.get_anguloServo3(); 
				cout<<"Posiciones 5 y 6 pre-guardadas para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			//Guarda la posicion 7 a la posicion 8 del brazo
			case 'l':
				S2P4=Brazo.get_anguloServo2(); 
				S3P4=Brazo.get_anguloServo3();  
				cout<<"Posiciones 7 y 8 pre-guardadas para los servos 2 y 3."<<endl;
				count=0;
				cadena="";
				break;
			// Manda restablece todas las nuevas posiciones
			case 'm':
				Brazo.set_particular_PosicionesServo2(S2P1,S2P2,S2P3,S2P4);
				Brazo.set_particular_PosicionesServo3(S3P1,S3P2,S3P3,S3P4);   
				cout<<"Posiciones guardadas para los servos 2 y 3."<<endl;		
				count=0;                                                     
				cadena="";
				break;
			// Quita el ultimo caracter y las manda al limite de abertura del robot
			case '%':
				cadena=quitarChar(cadena,count);     
				istringstream(cadena)>>num;    
				Brazo.set_limiteAberturaServo4(num); 
				cout<<"Limite de abertura para servo 4: "<<Brazo.get_limiteAberturaServo4()<<endl;  
				count=0;
				cadena="";
				break;
			// Quita el ultimo caracter y las manda al limite de cerradura del robot
			case '#':
				cadena=quitarChar(cadena,count);    
				istringstream(cadena)>>num;         
				Brazo.set_limiteCerraduraServo4(num);  
				cout<<"Limite de cerradura para servo 4: "<<Brazo.get_limiteCerraduraServo4()<<endl;  
				count=0;
				cadena="";
				break;
			//Guarda la cantidad de cajas verdes introducidas
			case 'n':
				recopilarPosiciones(0);                               
				if(Brazo.get_CantidadCajasVerdes()>0 and Brazo.get_temperaturaServo2()<100 and Brazo.get_temperaturaServo3()<100 and Brazo.get_limiteCerraduraServo4()>10 and Brazo.get_limiteAberturaServo4()<60){
					cout<<endl<<endl<<"                   Guardando "<<Brazo.get_CantidadCajasVerdes()<<" cajas verdes..."<<endl<<endl;
					cout<<"               Servo1:"<<"        Servo2:"<<"     Servo3:"<<"       Servo4:"<<endl;
					for(int i=0;i<Brazo.get_CantidadCajasVerdes();i++){    
						for(int j=0;j<9;j++){                        
							Brazo.set_anguloServo1(posiSer1[j]);
							Brazo.set_anguloServo2(posiSer2[j]);
							Brazo.set_anguloServo3(posiSer3[j]);
							Brazo.set_anguloServo4(posiSer4[j]);    
							cout<<"Posicion "<<j+1<<":        "<<Brazo.get_anguloServo1()<<"            "<<Brazo.get_anguloServo2()<<"            "<<Brazo.get_anguloServo3()<<"            "<<Brazo.get_anguloServo4()<<endl;
							Sleep(1000); 
						}
					}
					cout<<endl<<endl<<"                     Listo!"<<endl;
					 // Incrementa la temperatura por movimiento de los servos
					Brazo.set_temperaturaServo2(temperatura2++); 
					Brazo.set_temperaturaServo3(temperatura3++);
				}
				count=0;             
				cadena="";
				break;
			//Guarda la cantidad de cajas rojas introducidas
			case 'o':
				recopilarPosiciones(1);                               
				if(Brazo.get_CantidadCajasRojas()>0 and Brazo.get_temperaturaServo2()<100 and Brazo.get_temperaturaServo3()<100 and Brazo.get_limiteCerraduraServo4()>10 and Brazo.get_limiteAberturaServo4()<60){ 
					cout<<endl<<endl<<"                   Guardando "<<Brazo.get_CantidadCajasRojas()<<" cajas rojas..."<<endl<<endl;
					cout<<"               Servo1:"<<"        Servo2:"<<"     Servo3:"<<"       Servo4:"<<endl;
					for(int i=0;i<Brazo.get_CantidadCajasRojas();i++){    
						for(int j=0;j<9;j++){                          
							Brazo.set_anguloServo1(posiSer1[j]);
							Brazo.set_anguloServo2(posiSer2[j]);
							Brazo.set_anguloServo3(posiSer3[j]);
							Brazo.set_anguloServo4(posiSer4[j]);    
							cout<<"Posicion "<<j+1<<":        "<<Brazo.get_anguloServo1()<<"            "<<Brazo.get_anguloServo2()<<"            "<<Brazo.get_anguloServo3()<<"            "<<Brazo.get_anguloServo4()<<endl;
							Sleep(1000);
						}
					}
					cout<<endl<<endl<<"                     Listo!"<<endl;
					 // Incrementa la temperatura por movimiento de los servos
					Brazo.set_temperaturaServo2(temperatura2++);
					Brazo.set_temperaturaServo3(temperatura3++); 
				}
				count=0;                                                    
				cadena="";
				break;
			//Guarda la cantidad de cajas amarillas introducidas
			case 'p':
				recopilarPosiciones(2);                             
				if(Brazo.get_CantidadCajasAmarillas()>0 and Brazo.get_temperaturaServo2()<100 and Brazo.get_temperaturaServo3()<100 and Brazo.get_limiteCerraduraServo4()>10 and Brazo.get_limiteAberturaServo4()<60){  
					cout<<endl<<endl<<"                   Guardando "<<Brazo.get_CantidadCajasAmarillas()<<" cajas amarillas..."<<endl<<endl;
					cout<<"               Servo1:"<<"        Servo2:"<<"     Servo3:"<<"       Servo4:"<<endl;
					for(int i=0;i<Brazo.get_CantidadCajasAmarillas();i++){    
						for(int j=0;j<9;j++){                         
							Brazo.set_anguloServo1(posiSer1[j]);
							Brazo.set_anguloServo2(posiSer2[j]);
							Brazo.set_anguloServo3(posiSer3[j]);
							Brazo.set_anguloServo4(posiSer4[j]);   
							cout<<"Posicion "<<j+1<<":        "<<Brazo.get_anguloServo1()<<"            "<<Brazo.get_anguloServo2()<<"            "<<Brazo.get_anguloServo3()<<"            "<<Brazo.get_anguloServo4()<<endl;
							Sleep(1000); 
						}
					}
					cout<<endl<<endl<<"                     Listo!"<<endl;
					// Incrementa la temperatura por movimiento de los servos
					Brazo.set_temperaturaServo2(temperatura2++);
					Brazo.set_temperaturaServo3(temperatura3++);  
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
//Funcion que me elimina el ultimo caracter de mi cadena
string quitarChar(string cade, int cont){  
	string cad="";
	for(int i=0;i<cont-1;i++){
		cad=cad+cade[i];
	}
	return cad;
}
// Funcion que recopila la posicion particular de cada servo
void recopilarPosiciones(int c){ 
	for(int f=0;f<9;f++){
		posiSer1[f]=Brazo.get_particular_PosicionesServo1(f,c);
		posiSer2[f]=Brazo.get_particular_PosicionesServo2(f,c);
		posiSer3[f]=Brazo.get_particular_PosicionesServo3(f,c);
		posiSer4[f]=Brazo.get_particular_PosicionesServo4(f,c);
	}
}
// Menu operativo
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