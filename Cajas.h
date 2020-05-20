# ifndef CAJAS_H_
# define  CAJAS_H_

class Cajas{               //clase cajas, para obtener los tipos de cajas que voy a manipular
	private:
		int cantidad;    //atributo de mi objeto caja
	public:
		Cajas();      //prototipo de metodo constructor
		Cajas(int cant);       //prototipo de metodo constructor (sobrecarga)
		int get_cantidad();       //prototipo de metodos getters y setters
		void set_cantidad(int);
};
Cajas::Cajas(){  // constructor de cajas
	cantidad=0;
}
Cajas::Cajas(int cant){     //sobrecarga de constructor cajas
	cantidad=cant;
}
void Cajas::set_cantidad(int cant){   //establesco un nuevo valor para el atributo cantidad
	cantidad=cant;
}
int Cajas::get_cantidad(){   //extraigo la característica cantidad de mi objeto
	return cantidad;
}
# endif