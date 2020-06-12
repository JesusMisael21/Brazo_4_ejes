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
//Creacion de la clase Cajas
class Cajas{             
	private:
		//Atributos
		int cantidad;  
	public:
		// Prototipo de los constructores
		Cajas();     
		Cajas(int cant); 
		//Prototipo de los metodos
		int get_cantidad();      
		void set_cantidad(int);
};
//Definicion de los constructores
Cajas::Cajas(){  
	cantidad=0;
}
Cajas::Cajas(int cant){   
	cantidad=cant;
}
//Definicion de los metodos
void Cajas::set_cantidad(int cant){   
	cantidad=cant;
}
int Cajas::get_cantidad(){   
	return cantidad;
}
# endif