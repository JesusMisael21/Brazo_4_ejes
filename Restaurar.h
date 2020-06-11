/*
* Proyecto brazo robotico
* Jesus Misael Resendiz Cruz
* A01706166
* 11/06/2020
* Esta clase define objeto de tipo Restaurar que son composicion de Robots, me permite crear
* posiciones para cada servo, esta se estara modificando con el tiempo por la temperatura
* adquirida por el mismo servo.
*/
# ifndef RESTAURAR_H_
# define  RESTAURAR_H_
class Restaurar{    
	private:
		int posicion[100][100];
		int posicionI[100][100]={{97,8,2},{3,0,9},{8,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24},{25,26,27}}; //angulos iniciales
	public:
		Restaurar();  //prototipo de metodo constructor
		Restaurar(int pos[100][100]);  //prototipo de metodo constructor  (sobrecarga)
		int particular_posicion(int nfila,int ncolumna); //apuntador ya que me retorna un arreg      
		void set_posicion(int sP1,int sP2,int sP3,int sP4);  //metodos prototipos (getters y setters)
		void set_posicionCompleto(int posi[100][100]);
};

Restaurar::Restaurar(int pos[100][100]){ //constructor , inicializa los atributos, matriz de valores enteros(angulos)
	int i,j;
	for(i = 0; i < 9; i++)     //extraigo los valores y los añador en el atributo posicion
		for (j = 0; j < 3; j++)
			posicion[i][j]=pos[i][j];
}

Restaurar::Restaurar(){ // sobrecarga de constructor restaurar, inicia en vacío
	int i,j;
	for(i = 0; i < 9; i++)     //extraigo los valores y los añador en el atributo posicion
		for (j = 0; j < 3; j++)
			posicion[i][j]=posicionI[i][j];
}

void Restaurar::set_posicionCompleto(int posi[100][100]){
	int i,j;
	for(i = 0; i < 9; i++)     //extraigo los valores y los añador en el atributo posicion
		for (j = 0; j < 3; j++)
			posicion[i][j]=posi[i][j];
}

void Restaurar::set_posicion(int sP1,int sP2,int sP3,int sP4){ // metodo setter que me permite restablecer los angulos de mis servomotores
	int i,j;                                                // cada ves que lo necesite, ya que estos tienden a cambiar conforme al tiempo 
	for(i = 0; i < 8; i++)                            //de ser utilizados. Este casualmente será utilizado justo cuando vallamos a ejecutar 
		for (j = 0; j < 3; j++){                        //el algoritmo de guardado de cajas
			if (i==0){
				posicion[i][j]=sP1;
			}
			if (i>=1 and i<=3){
				posicion[i][j]=sP2;
			}
			if (i>=4 and i<=5){
				posicion[i][j]=sP3;
			}
			if (i>=6 and i<=7){
				posicion[i][j]=sP4;
			}
		}
}
int Restaurar::particular_posicion(int nfila,int ncolumna){  //regresa una posicion particular
	return posicion[nfila][ncolumna];
}
# endif