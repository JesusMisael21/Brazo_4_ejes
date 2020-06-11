/*
* Proyecto brazo robotico
* Jesus Misael Resendiz Cruz
* A01706166
* 11/06/2020
* Esta clase define objetos de tipo Movimientos que seran composicion de Robots, estos objetos
* son los servomotores en donde pueden ser Articulacion o Mano.
*/
class Movimientos{       //clase Movimientos para obtener objetos servomotores que me hacen mover el brazo
	private:
		int angulo;      //privada ya que es mi atributo/característica de mi objeto
		float temperatura;
	public:
		Movimientos();  //prototipo de metodo constructor
		Movimientos(int,float);  //prototipo de metodo constructor (sobrecarga)
		void set_angulo(int ang);  
		int get_angulo();
		void Aumenta();    //prototipos de los metodos a usar
		void Disminuye();
		virtual void set_limiteAbertura(int limA)=0;       //método abstracto será sobreescrito ejecución
		virtual int get_limiteAbertura()=0;                       //pure virtual
		virtual void set_limiteCerradura(int LimC)=0;
		virtual int get_limiteCerradura()=0;
				// se sobreescribirán con polimorfismo
		virtual void set_temperatura(float){}
		virtual float get_temperatura(){return 21.0;}
		virtual int home(){             
								return 0;
							}
		
};

Movimientos::Movimientos(){// constructor vacío de movimientos
	angulo=100;
}

Movimientos::Movimientos(int ang,float temp){//sobrecarga de constructor movimientos
	angulo=ang;
	temperatura=temp;
}

void Movimientos::set_angulo(int ang){  //setter que me permite modificar el atributo de mi objeto en forma de entero
	angulo=ang;
}
int Movimientos::get_angulo(){    //getter que me permite tomar el valor de la caracteristica de mi objeto en forma de entero
	return angulo;
}

void Movimientos::Aumenta(){  //metodo que me permite aumentar la posicion de mi servo objeto de uno en uno
	angulo++;
}
void Movimientos::Disminuye(){  //metodo que me permite disminuir la posicion de mi servo objeto de uno en uno
	angulo--;
}

class Articulacion: public Movimientos{ //clase hija de Movimientos
	private:
		int limiteAbertura;
		int limiteCerradura;
		
	public:
		Articulacion();
		Articulacion(int ang,float temp);
		float get_temperatura();
		int home(){                   
					return 80;
					}
		void set_limiteAbertura(int limA);
		int get_limiteAbertura();
		void set_limiteCerradura(int LimC);
		int get_limiteCerradura();
};

Articulacion::Articulacion(){
	set_temperatura(0);
}

Articulacion::Articulacion(int ang,float temp):Movimientos(ang,temp){}
	
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

class Mano: public Movimientos{
	private:
		int limiteAbertura;
		int limiteCerradura;
		
	public:
		Mano();
		Mano(int ang,float temp,int limA,int limC);
		void set_limiteAbertura(int limA);
		int get_limiteAbertura();
		void set_limiteCerradura(int LimC);
		int get_limiteCerradura();
		float get_temperatura();  // sobreescritura ya que Articulacion tambien lo tiene
		int home(){
					return 21;
					}
};

Mano::Mano(){
	limiteAbertura=50;
	limiteCerradura=20;
}

Mano::Mano(int ang,float temp,int limA,int limC):Movimientos(ang,temp){
	limiteAbertura=limA;
	limiteCerradura=limC;
}
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
float Mano::get_temperatura(){   // sobreescritura
	int te=Movimientos::get_temperatura();
	return te*0.8;
}