/*
* Proyecto brazo robotico
* Jesus Misael Resendiz Cruz
* A01706166
* 11/06/2020
* Esta clase define objetos de tipo Robots, con este inicializo todos los brazos completos que yo quiero,
* en el main solo se crea uno solo para poner en practica todas las funciones que tiene integrado.
*/
# ifndef ROBOTS_H_
# define  ROBOTS_H_
//Uso de las clases a instanciar
#include "Restaurar.h" 
#include "Movimientos.h" 
#include "Cajas.h"
//Creacion de la clase Robots
class Robots{
	private:
		//Atributos
		Restaurar PosicionesServo1;  
		Restaurar PosicionesServo2;  
		Restaurar PosicionesServo3;  
		Restaurar PosicionesServo4; 
									
		Movimientos *servos[5];   
		Cajas cajasVerdes; 
		Cajas cajasRojas;
		Cajas cajasAmarillas;
	
	public:
		//Prototipo del constructor 
		Robots();
		// Prototipo de los metodos
		void set_particular_PosicionesServo2(int pose1,int pose2,int pose3,int pose4); 
		void set_particular_PosicionesServo3(int pose1,int pose2,int pose3,int pose4);    
		int get_particular_PosicionesServo1(int nfila,int ncolumna);
		int get_particular_PosicionesServo2(int nfila,int ncolumna);
		int get_particular_PosicionesServo3(int nfila,int ncolumna); 
		int get_particular_PosicionesServo4(int nfila,int ncolumna);
		void set_anguloServo1(int ang);
		void set_anguloServo2(int ang);  
		void set_anguloServo3(int ang);
		void set_anguloServo4(int ang);
		int get_anguloServo1();
		int get_anguloServo2();
		int get_anguloServo3();     
		int get_anguloServo4();
		void set_temperaturaServo2(int temp);  
		void set_temperaturaServo3(int temp);
		int get_temperaturaServo2();
		int get_temperaturaServo3();   
		void set_limiteAberturaServo4(int limA);  
		void set_limiteCerraduraServo4(int limC);
		int get_limiteAberturaServo4();             
		int get_limiteCerraduraServo4();  
		void servo1Aumenta();
		void servo2Aumenta();
		void servo3Aumenta();       
		void servo4Aumenta();
		void servo1Disminuye();
		void servo2Disminuye();  
		void servo3Disminuye();
		void servo4Disminuye();
		void set_cajasVerdes(Cajas cV);
		void set_cajasRojas(Cajas cR);
		void set_cajasAmarillas(Cajas cA);
		void set_CantidadCajasVerdes(int cant);
		void set_CantidadCajasRojas(int cant);     
		void set_CantidadCajasAmarillas(int cant);
		int get_CantidadCajasVerdes();
		int get_CantidadCajasRojas();    
		int get_CantidadCajasAmarillas();
		void goHome(){
						cout<<"Yendo a home..."<<endl;
						cout<<"Servo1: "<<servos[1]->home()<<endl;
						cout<<"Servo2: "<<servos[2]->home()<<endl;
						cout<<"Servo3: "<<servos[3]->home()<<endl;
						cout<<"Servo4: "<<servos[4]->home()<<endl;
					}
						
};
// Definicion del constructor por default
Robots::Robots(){ 
    servos[1]=new Articulacion();                       
	servos[2]=new Articulacion();
	servos[3]=new Articulacion();
	servos[4]=new Mano();
	//Angulos iniciales
	int Servo1posicionI[100][100]={{13,42,74},{13,42,74},{13,42,74},{0,28,56},{0,28,56},{94,112,135},{94,112,135},{94,112,135},{101,101,101}};
	int Servo2posicionI[100][100]={{98,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24},{25,26,27}}; 
	int Servo3posicionI[100][100]={{99,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24},{25,26,27}}; 
	int Servo4posicionI[100][100]={{50,50,50},{50,50,50},{15,15,15},{15,15,15},{15,15,15},{15,15,15},{15,15,15},{50,50,50},{21,21,21}}; 
	// Agregacion de los angulos iniciales 
	PosicionesServo1.set_posicionCompleto(Servo1posicionI);    
	PosicionesServo2.set_posicionCompleto(Servo2posicionI);    
	PosicionesServo3.set_posicionCompleto(Servo3posicionI);
	PosicionesServo4.set_posicionCompleto(Servo4posicionI);
	// Iniciar en Home
	servos[1]->set_angulo(101);
	servos[2]->set_angulo(70);
	servos[3]->set_angulo(75);
	servos[4]->set_angulo(21);
	
}
// Definicion del constructor por default
void Robots::set_particular_PosicionesServo2(int pose1,int pose2,int pose3,int pose4){   //contenido de mis metodos anteriormente mencionados
	PosicionesServo2.set_posicion(pose1,pose2,pose3,pose4);
}
// Fucion que garda las nuevas posiciones algoritmicas de los servos para el guardado de cajas

void Robots::set_particular_PosicionesServo3(int pose1,int pose2,int pose3,int pose4){
	PosicionesServo3.set_posicion(pose1,pose2,pose3,pose4);
}
// Funciones que extraen una posicon particular de dicho servo
int Robots::get_particular_PosicionesServo1(int nfila,int ncolumna){
	return PosicionesServo1.particular_posicion(nfila,ncolumna);
}

int Robots::get_particular_PosicionesServo2(int nfila,int ncolumna){
	return PosicionesServo2.particular_posicion(nfila,ncolumna);
}

int Robots::get_particular_PosicionesServo3(int nfila,int ncolumna){
	return PosicionesServo3.particular_posicion(nfila,ncolumna);
}

int Robots::get_particular_PosicionesServo4(int nfila,int ncolumna){
	return PosicionesServo4.particular_posicion(nfila,ncolumna);
}
//Funciones que modifican de forma mecanica del angulo de los servos 
void Robots::set_anguloServo1(int ang){
	servos[1]->set_angulo(ang);
}

void Robots::set_anguloServo2(int ang){
	servos[2]->set_angulo(ang);
}

void Robots::set_anguloServo3(int ang){
	servos[3]->set_angulo(ang);
}

void Robots::set_anguloServo4(int ang){
	servos[4]->set_angulo(ang);
}
// Funciones que extraen el angulo actual del servo 
int Robots::get_anguloServo1(){
	return servos[1]->get_angulo();
}

int Robots::get_anguloServo2(){
	return servos[2]->get_angulo();
}

int Robots::get_anguloServo3(){
	return servos[3]->get_angulo();
}

int Robots::get_anguloServo4(){
	return servos[4]->get_angulo();
}
// Funciones que mandan a guarda la temperatura de los servos
void Robots::set_temperaturaServo2(int temp){
	servos[2]->set_temperatura(temp);
}

void Robots::set_temperaturaServo3(int temp){
	servos[3]->set_temperatura(temp);
}
// Funciones que extraen la informacion de la temperatura de los servos
int Robots::get_temperaturaServo2(){
	return servos[2]->get_temperatura();
}

int Robots::get_temperaturaServo3(){
	return servos[3]->get_temperatura();
}
//Funciones que mantienen un limite en abertura y cerradura de la mano
void Robots::set_limiteAberturaServo4(int limA){
	servos[4]->set_limiteAbertura(limA);
}

void Robots::set_limiteCerraduraServo4(int limC){
	servos[4]->set_limiteCerradura(limC);
}
// Funciones que extraen dichas abertura y cerraduras actuales
int Robots::get_limiteAberturaServo4(){
	return servos[4]->get_limiteAbertura();
}

int Robots::get_limiteCerraduraServo4(){
	return servos[4]->get_limiteCerradura();
}
//Funciones que aumentan y disminuyen los angulos de cada servo
void Robots::servo1Aumenta(){
	servos[1]->Aumenta();
}

void Robots::servo2Aumenta(){
	servos[2]->Aumenta();
}

void Robots::servo3Aumenta(){
	servos[3]->Aumenta();
}

void Robots::servo4Aumenta(){
	servos[4]->Aumenta();
}

void Robots::servo1Disminuye(){
	servos[1]->Disminuye();
}

void Robots::servo2Disminuye(){
	servos[2]->Disminuye();
}

void Robots::servo3Disminuye(){
	servos[3]->Disminuye();
}

void Robots::servo4Disminuye(){
	servos[4]->Disminuye();
}
//Funciones que agregan la cantidad de cajas a guardar
void Robots::set_cajasVerdes(Cajas cV){
	cajasVerdes=cV;
}

void Robots::set_cajasRojas(Cajas cR){
	cajasRojas=cR;
}

void Robots::set_cajasAmarillas(Cajas cA){
	cajasAmarillas=cA;
}

void Robots::set_CantidadCajasVerdes(int cant){
	cajasVerdes.set_cantidad(cant);
}

void Robots::set_CantidadCajasRojas(int cant){
	cajasRojas.set_cantidad(cant);
}

void Robots::set_CantidadCajasAmarillas(int cant){
	cajasAmarillas.set_cantidad(cant);
}
// Funciones que extraen la informacion de cantidad de cajas a guardar
int Robots::get_CantidadCajasVerdes(){
	return cajasVerdes.get_cantidad();
}

int Robots::get_CantidadCajasRojas(){
	return cajasRojas.get_cantidad();
}

int Robots::get_CantidadCajasAmarillas(){
	return cajasAmarillas.get_cantidad();
}
# endif  // ROBOTS_H_