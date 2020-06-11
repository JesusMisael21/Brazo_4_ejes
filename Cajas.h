  /*
* Proyecto brazo robotico
* Jesus Misael Resendiz Cruz
* A01706166
* 11/06/2020
* Esta clase defina objeto de tipo Cajas que serán agregadas a la clase Robots
* cada objeto de este tipo sera un color diferente así teniendo diferentes cantidades
* de cajas.
*/

# ifndef CAJAS_H_
# define  CAJAS_H_

class Cajas{             
	private:
		int cantidad;    //atributo de mi objeto caja
	public:
		Cajas();     
		Cajas(int cant);     
		int get_cantidad();      
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