class Movimientos{       //clase Movimientos para obtener objetos servomotores que me hacen mover el brazo
	private:
		int angulo;      //privada ya que es mi atributo/característica de mi objeto
	public:
		Movimientos();  //prototipo de metodo constructor
		Movimientos(int);  //prototipo de metodo constructor (sobrecarga)
		void set_angulo(int ang);  
		int get_angulo();
		void Aumenta();    //prototipos de los metodos a usar
		void Disminuye();
};

Movimientos::Movimientos(){// constructor vacío de movimientos
	angulo=100;
}

Movimientos::Movimientos(int ang){//sobrecarga de constructor movimientos
	angulo=ang;
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
		float temperatura;
	public:
		Articulacion();
		Articulacion(int ang,float temp);
		void set_temperatura(float);
		float get_temperatura();
};

Articulacion::Articulacion(){
	temperatura=20;
}

Articulacion::Articulacion(int ang,float temp):Movimientos(ang){
	temperatura=temp;
}
void Articulacion::set_temperatura(float temp){
	temperatura=temp;
}
float Articulacion::get_temperatura(){
	return temperatura;
}

class Mano: public Movimientos{
	private:
		int limiteAbertura;
		int limiteCerradura;
		float temperatura;
	public:
		Mano();
		Mano(int ang,int limA,int limC);
		void set_limiteAbertura(int limA);
		int get_limiteAbertura();
		void set_limiteCerradura(int LimC);
		int get_limiteCerradura();
		void set_temperatura(float); // sobreescritura ya que Articulacion tambien lo tiene
		float get_temperatura();  // sobreescritura ya que Articulacion tambien lo tiene
};

Mano::Mano(){
	limiteAbertura=50;
	limiteCerradura=20;
}

Mano::Mano(int ang,int limA,int limC):Movimientos(ang){
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
void Mano::set_temperatura(float temp){ // sobreescritura
	temperatura=temp;
}
float Mano::get_temperatura(){   // sobreescritura
	return temperatura;
}