/*
* Proyecto brazo robotico
* Jesus Misael Resendiz Cruz
* A01706166
* 11/06/2020
* Esta clase define objetos de tipo Movimientos que seran composicion de Robots, estos objetos
* son los servomotores en donde pueden ser Articulacion o Mano.
*/
// Creación de la clase Movimientos
class Movimientos{  
	// Atributos
	private:
		int angulo;    
		float temperatura;
	public:
		//Prototipo de los constructores
		Movimientos(); 
		Movimientos(int,float); 
		//Prototipo de los metodos normales
		void set_angulo(int ang);  
		int get_angulo();
		void Aumenta();   
		void Disminuye();
		virtual void set_temperatura(float){}
		virtual float get_temperatura(){return 21.0;}
		virtual int home(){             
								return 0;
							}
		// Prototipo de los metodos abstractos
		virtual void set_limiteAbertura(int limA)=0;       
		virtual int get_limiteAbertura()=0;                       
		virtual void set_limiteCerradura(int LimC)=0;
		virtual int get_limiteCerradura()=0;
		
};
// Definicion del constructor por default
Movimientos::Movimientos(){
	angulo=100;
}

Movimientos::Movimientos(int ang,float temp){//sobrecarga de constructor movimientos
	angulo=ang;
	temperatura=temp;
}
// Definicion del constructor parametrizado
void Movimientos::set_angulo(int ang){ 
	angulo=ang;
}
int Movimientos::get_angulo(){    
	return angulo;
}
// Definicion de los metodos
void Movimientos::Aumenta(){ 
	angulo++;
}
void Movimientos::Disminuye(){
	angulo--;
}
// Creacion de la clase Articulacion
class Articulacion: public Movimientos{ 
	//Atributos
	private:
		int limiteAbertura;
		int limiteCerradura;
		
	public:
		//Prototipo de los constructores
		Articulacion();
		Articulacion(int ang,float temp);
		//Prototipo de los metodos
		float get_temperatura();
		int home(){                   
					return 80;
					}
		void set_limiteAbertura(int limA);
		int get_limiteAbertura();
		void set_limiteCerradura(int LimC);
		int get_limiteCerradura();
};
// Definicion del constructor por default
Articulacion::Articulacion(){
	set_temperatura(0);
}
// Definicion del constructor parametrizado
Articulacion::Articulacion(int ang,float temp):Movimientos(ang,temp){}

// Definicion de los metodos
float Articulacion::get_temperatura(){
	int te=Movimientos::get_temperatura();
	return te*0.8;
}
void Articulacion::set_limiteAbertura(int limA){
	limiteAbertura=limA*2;
}
void Articulacion::set_limiteCerradura(int limC){
	limiteCerradura=limC*3;
}
int Articulacion::get_limiteAbertura(){
	return limiteAbertura*2;
}
int Articulacion::get_limiteCerradura(){
	return limiteCerradura*3;
}
//Creacion de la clase Mano
class Mano: public Movimientos{
	private:
		//Atributos
		int limiteAbertura;
		int limiteCerradura;
		
	public:
		//Prototipo de los constructores
		Mano();
		Mano(int ang,float temp,int limA,int limC);
		// Prototipo de los metodos
		void set_limiteAbertura(int limA);
		int get_limiteAbertura();
		void set_limiteCerradura(int LimC);
		int get_limiteCerradura();
		float get_temperatura(); 
		int home(){
					return 21;
					}
};
// Definicion del constructor por default
Mano::Mano(){
	limiteAbertura=50;
	limiteCerradura=20;
}
// Definicion del constructor parametrizado
Mano::Mano(int ang,float temp,int limA,int limC):Movimientos(ang,temp){
	limiteAbertura=limA;
	limiteCerradura=limC;
}
//Definicion de los metodos setters y getters
void Mano::set_limiteAbertura(int limA){
	limiteAbertura=limA;
}
void Mano::set_limiteCerradura(int limC){
	limiteCerradura=limC;
}
int Mano::get_limiteAbertura(){
	return limiteAbertura;
}
int Mano::get_limiteCerradura(){
	return limiteCerradura;
}
float Mano::get_temperatura(){  
	int te=Movimientos::get_temperatura();
	return te*0.8;
}